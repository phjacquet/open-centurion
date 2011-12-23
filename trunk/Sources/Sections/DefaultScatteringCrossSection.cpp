/*
 * File:   DefaultScatteringCrossSection.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:13
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "DefaultScatteringCrossSection.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/Mesh.h"
#include "Field/DoubleMeshField.h"
#include "SetOfXS.h"
#include "Exceptions/InputConsistency.h"

using namespace std ;

DefaultScatteringCrossSection::DefaultScatteringCrossSection(EnergyMesh * energyMesh, Mesh * momentMesh, Mesh * spatialMesh) {
    vector< pair_MeshOption_t > meshes ;
    meshes.push_back( pair_MeshOption_t(energyMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption_t(energyMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption_t(momentMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption_t(spatialMesh,DoubleMeshField::LAZY) ) ;
    data = new DoubleMeshField(meshes) ;
    xsType = SetOfXS::SCATTERING ;
}

DefaultScatteringCrossSection::DefaultScatteringCrossSection(const DefaultScatteringCrossSection& orig) {
    throw runtime_error("DefaultScatteringCrossSection::DefaultScatteringCrossSection(const DefaultScatteringCrossSection& orig) : Unimplemented method") ;
}

DefaultScatteringCrossSection::~DefaultScatteringCrossSection() {
    delete data ;
}

void DefaultScatteringCrossSection::collapseSpatialRegions(const string & name, const std::vector< std::string > & regionsName) {
    data->buildFamily(3,regionsName,name) ;
}

DoubleMeshField * DefaultScatteringCrossSection::getData() {
    return data ;
}

void DefaultScatteringCrossSection::buildData() {
    data->buildData();
}

void DefaultScatteringCrossSection::calculateMacro(const string & mediumName,
                                             map< SetOfXS::E_XS, vector<CrossSection*> > mmicroXS,
                                              const vector< double > & concentrations) {
    //cout<<"DefaultScatteringCrossSection::calculateMacro("<<mediumName<<","<<mmicroXS.size()<<","<<concentrations.size()<<")"<<endl;
    if (mmicroXS.find(SetOfXS::SCATTERING)==mmicroXS.end())
        throw InputConsistency(21, LOG_INP_CONS_E("DefaultScatteringCrossSection::calculateMacro(...) : mmicroXS does not contain required micros XS"));
    vector<CrossSection*> & microXS = mmicroXS[SetOfXS::SCATTERING] ;
    FieldIterator it = data->getIterator() ;
    data->setDouble( it(":;:;:;"+mediumName) , 0.0 );
    vector<double*> dM = data->getDoubles(it(":;:;:;"+mediumName)) ;
    for (unsigned n=0; n<microXS.size(); n++) {
        vector<double *> dm = microXS[n]->getData()->getDoubles(it(":;:;:;-")) ;
        if (dM.size()!=dm.size())
            throw InputConsistency(15, LOG_INP_CONS_E("DefaultScatteringCrossSection::calculateMacro(...) : medium "+
                                                      mediumName+
                                                      " is not compatible with one of micro cross sections"));
        for (unsigned i=0; i<dM.size(); i++) {
            //cout<<*dm[i]<<" * "<<concentrations[n]<<endl;
            *dM[i]+=(*dm[i])*concentrations[n] ;
        }
    }
}

string DefaultScatteringCrossSection::toString(const string & option) {
    stringstream ss;
    ss<<"<DefaultScatteringCrossSection>"<<endl;
    ss<<data->toString(option)<<endl;
    ss<<"</DefaultScatteringCrossSection>"<<endl;
    return ss.str() ;
}
