/* 
 * File:   DefaultCrossSection.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 1 juin 2011, 22:17
 */

#include <vector>
#include <stdexcept>
#include "DefaultTotalCrossSection.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/Mesh.h"
#include "Field/DoubleMeshField.h"


using namespace std;

DefaultTotalCrossSection::DefaultTotalCrossSection(EnergyMesh * energyMesh, Mesh * spatialMesh) {
    vector< pair_MeshOption > meshes ;
    meshes.push_back( pair_MeshOption(energyMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption(spatialMesh,DoubleMeshField::LAZY) ) ;
    data = new DoubleMeshField(meshes) ;
}

DefaultTotalCrossSection::DefaultTotalCrossSection(const DefaultTotalCrossSection& orig) {
    throw runtime_error("DefaultTotalCrossSection::DefaultTotalCrossSection(const DefaultTotalCrossSection& orig) : Unimplemented method") ;
}

DefaultTotalCrossSection::~DefaultTotalCrossSection() {
    delete data ;
}

void DefaultTotalCrossSection::collapseSpatialRegions(const string & name, const std::vector< std::string > & regionsName) {
    data->buildFamily(1,regionsName,name) ;
}
