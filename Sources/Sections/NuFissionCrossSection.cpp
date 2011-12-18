/*
 * File:   NuFissionCrossSection.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:54
 */

#include <vector>
#include <stdexcept>
#include <sstream>
#include "NuFissionCrossSection.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/Mesh.h"
#include "Field/DoubleMeshField.h"
#include "SetOfXS.h"
#include "Exceptions/InputConsistency.h"


using namespace std ;

NuFissionCrossSection::NuFissionCrossSection(EnergyMesh * energyMesh, Mesh * spatialMesh) {
    vector< pair_MeshOption_t > meshes ;
    meshes.push_back( pair_MeshOption_t(energyMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption_t(spatialMesh,DoubleMeshField::LAZY) ) ;
    data = new DoubleMeshField(meshes) ;
    xsType = SetOfXS::NUFISSION ;
}

NuFissionCrossSection::NuFissionCrossSection(const NuFissionCrossSection& orig) {
    throw runtime_error("NuFissionCrossSection::NuFissionCrossSection(const NuFissionCrossSection& orig) : Unimplemented method") ;
}

NuFissionCrossSection::~NuFissionCrossSection() {
    delete data ;
}

void NuFissionCrossSection::collapseSpatialRegions(const string & name,
                                                   const std::vector< std::string > & regionsName) {
    data->buildFamily(1,regionsName,name) ;
}

DoubleMeshField * NuFissionCrossSection::getData() {
    return data ;
}

void NuFissionCrossSection::buildData() {
    data->buildData();
}

void NuFissionCrossSection::calculateMacro(const string & mediumName,
                                              vector<CrossSection*> microXS,
                                              const vector< double > & concentrations) {
    FieldIterator it = data->getIterator() ;
    data->setDouble( it(":;"+mediumName) , 0.0 );
    vector<double*> dM = data->getDoubles(it(":;"+mediumName)) ;
    for (unsigned n=0; n<microXS.size(); n++) {
        vector<double *> dm = microXS[n]->getData()->getDoubles(it(":;-")) ;
        if (dM.size()!=dm.size())
            throw InputConsistency(17, LOG_INP_CONS_E("NuFissionCrossSection::calculateMacro(...) : medium "+
                                                      mediumName+
                                                      " is not compatible with one of micro cross sections"));
        for (unsigned g=0; g<data->getMesh(0)->size(); g++) {
            *dM[g]+=(*dm[g])*concentrations[n] ;
        }
    }
}

string NuFissionCrossSection::toString() {
    stringstream ss;
    ss<<"<NuFissionCrossSection>"<<endl;
    ss<<data->toString()<<endl;
    ss<<"</NuFissionCrossSection>"<<endl;
    return ss.str() ;
}
