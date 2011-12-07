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
    data->buildFamily(2,regionsName,name) ;
}