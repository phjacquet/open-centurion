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
    pbMacXS.getXS(SetOfXS::TOTAL)->collapseSpatialRegions(name, regionsName) ;
    pbMacXS.getXS(SetOfXS::SCATTERING)->collapseSpatialRegions(name, regionsName) ;
    pbMacXS.getXS(SetOfXS::FISSION_DISTRIBUTION)->collapseSpatialRegions(name, regionsName) ;
    pbMacXS.getXS(SetOfXS::NUFISSION)->collapseSpatialRegions(name, regionsName) ;
}

void  Geometry::buildMacros() {
    SetOfXS::E_XS xsTypes[] = {SetOfXS::TOTAL,SetOfXS::SCATTERING,SetOfXS::NUFISSION,SetOfXS::FISSION_DISTRIBUTION};
    for (unsigned i=0; i<4; i++) {
        pbMacXS.getXS(xsTypes[i])->buildData() ;
        typedef pair< const string,pair< vector<string>,vector<double> > > iter_t  ;
        BOOST_FOREACH(  iter_t &it , materials ) {
            pbMacXS.getXS(xsTypes[i])->calculateMacro( it.first,
                    library->setOfMicroXS(xsTypes[i], it.second.first),
                    it.second.second ) ;
        }
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
}

string Geometry::toString() {
    stringstream ss;
    ss<<"<Geometry>"<<endl;
    ss<<pbMacXS.toString()<<endl;
    ss<<"</Geometry>";
    return ss.str() ;
}
