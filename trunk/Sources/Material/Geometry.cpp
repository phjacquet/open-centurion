/*
 * File:   Geometry.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 juin 2011, 22:32
 */


#include <iostream>
#include <sstream>
#include <stdexcept>
#include <boost/foreach.hpp>
#include "Geometry.h"
#include "Library.h"
#include "Exceptions/InputConsistency.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/DiscreteMesh.h"
#include "Mesh/Region.h"
#include "Sections/DefaultTotalCrossSection.h"
#include "Sections/DefaultScatteringCrossSection.h"
#include "Sections/NuFissionCrossSection.h"
#include "Sections/FissionDistribution.h"
#include "Sections/FissionProduction.h"

using namespace std;

Geometry::Geometry(Mesh * l_spatialMesh, Library * l_library) {
    spatialMesh = l_spatialMesh ;
    library = l_library ;
    energyMesh = library->getEnergyMesh();
    discreteMesh = library->getDiscreteMesh();

    buildXS();
}

Geometry::~Geometry() {
}

Geometry::Geometry(const Geometry& orig) {
    throw runtime_error("Geometry::Geometry(const Geometry& orig)") ;
}

Geometry Geometry::operator=(const Geometry& orig) {
    throw runtime_error("Geometry::Geometry operator=(const Geometry& orig)") ;
}

void Geometry::fill(const string & name,
                    const string regionsNameA[],
                    unsigned sizeA,
                    const vector< pair< string,double > > & medium) {

    vector<string>  regionsName ;
    regionsName.resize(sizeA);
    copy ( regionsNameA, regionsNameA+sizeA, regionsName.begin() );
    fill(name,regionsName,medium) ;
}

void Geometry::fill(const string & name,
                    const vector<string> & regionsName,
                    const vector< pair< string,double > > & medium) {
    vector<string> nucleiList ;
    vector<double> nucleiConcentrations ;
    for (unsigned n = 0; n < medium.size(); n++ ) {
        nucleiList.push_back(medium[n].first) ;
        nucleiConcentrations.push_back(medium[n].second) ;
    }
    if (materials.find(name)!=materials.end())
        throw InputConsistency(13, LOG_INP_CONS_E("Material "+name+" is already defined"));
    materials[name] = pair< vector<string>,vector<double> >(nucleiList,nucleiConcentrations) ;

    SetOfXS::E_XS xsTypes[] = { SetOfXS::TOTAL,
                                SetOfXS::SCATTERING,
                                SetOfXS::NUFISSION,
                                SetOfXS::FISSION_DISTRIBUTION,
                                SetOfXS::FISSION_PRODUCTION    };
    for (unsigned i=0; i<sizeof(xsTypes)/sizeof(SetOfXS::E_XS); i++)
        pbMacXS.getXS(xsTypes[i])->collapseSpatialRegions(name, regionsName) ;

}

void  Geometry::buildMacros() {
    SetOfXS::E_XS xsTypes[] = {SetOfXS::TOTAL,SetOfXS::SCATTERING,SetOfXS::NUFISSION};
    typedef pair< const string,pair< vector<string>,vector<double> > > iter_t  ;
    for (unsigned i=0; i<3; i++) {
        pbMacXS.getXS(xsTypes[i])->buildData() ;
        BOOST_FOREACH( iter_t &it , materials ) {
            map<SetOfXS::E_XS, vector <CrossSection *> > microXS ;
            microXS[xsTypes[i]]=library->setOfMicroXS(xsTypes[i], it.second.first) ;
            pbMacXS.getXS(xsTypes[i])->calculateMacro( it.first,microXS,it.second.second ) ;
        }
    }
    pbMacXS.getXS(SetOfXS::FISSION_PRODUCTION)->buildData() ;
    BOOST_FOREACH( iter_t &it , materials ) {
        map<SetOfXS::E_XS, vector <CrossSection *> > microXS ;
        microXS[SetOfXS::FISSION_DISTRIBUTION]=library->setOfMicroXS(SetOfXS::FISSION_DISTRIBUTION, it.second.first) ;
        microXS[SetOfXS::NUFISSION]=library->setOfMicroXS(SetOfXS::NUFISSION, it.second.first) ;
        pbMacXS.getXS(SetOfXS::FISSION_PRODUCTION)->calculateMacro( it.first,microXS,it.second.second ) ;
    }
}

SetOfXS * Geometry::getXS() {
    return &pbMacXS;
}

void Geometry::buildXS() {
    pbMacXS.newXS( new DefaultTotalCrossSection(energyMesh,spatialMesh) ) ;
    pbMacXS.newXS( new DefaultScatteringCrossSection(energyMesh,discreteMesh,spatialMesh) ) ;
    pbMacXS.newXS( new NuFissionCrossSection(energyMesh,spatialMesh) ) ;
    pbMacXS.newXS( new FissionDistribution(energyMesh,spatialMesh) ) ;
    pbMacXS.newXS( new FissionProduction(energyMesh,spatialMesh) ) ;

}

string Geometry::toString() {
    stringstream ss;
    ss<<"<Geometry>"<<endl;
    ss<<pbMacXS.toString("mM")<<endl;
    ss<<"</Geometry>";
    return ss.str() ;
}
