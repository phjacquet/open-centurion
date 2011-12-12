/*
 * File:   FissionDistribution.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:54
 */

#include <vector>
#include <stdexcept>
#include "FissionDistribution.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/Mesh.h"
#include "Field/DoubleMeshField.h"

using namespace std ;

FissionDistribution::FissionDistribution(EnergyMesh * energyMesh, Mesh * spatialMesh) {
    vector< pair_MeshOption > meshes ;
    meshes.push_back( pair_MeshOption(energyMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption(spatialMesh,DoubleMeshField::LAZY) ) ;
    data = new DoubleMeshField(meshes) ;
}

FissionDistribution::FissionDistribution(const FissionDistribution& orig) {
    throw runtime_error("FissionDistribution::FissionDistribution(const FissionDistribution& orig) : Unimplemented method") ;
}

FissionDistribution::~FissionDistribution() {
    delete data ;
}

void FissionDistribution::collapseSpatialRegions(const string & name, const std::vector< std::string > & regionsName) {
    data->buildFamily(1,regionsName,name) ;
}

DoubleMeshField * FissionDistribution::getData() {
    return data ;
}

void FissionDistribution::calculateMacro(const string & mediumName,
                                              vector<CrossSection*> microXS,
                                              const vector< double > & concentrations) {
    FieldIterator it = data->getIterator() ;
    data->setDouble( it(":;"+mediumName) , 0 );
}
