/*
 * File:   NuFissionCrossSection.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:54
 */

#include <vector>
#include <stdexcept>
#include "NuFissionCrossSection.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/Mesh.h"
#include "Field/DoubleMeshField.h"

using namespace std ;

NuFissionCrossSection::NuFissionCrossSection(EnergyMesh * energyMesh, Mesh * spatialMesh) {
    vector< pair_MeshOption > meshes ;
    meshes.push_back( pair_MeshOption(energyMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption(energyMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption(spatialMesh,DoubleMeshField::LAZY) ) ;
    data = new DoubleMeshField(meshes) ;
}

NuFissionCrossSection::NuFissionCrossSection(const NuFissionCrossSection& orig) {
    throw runtime_error("NuFissionCrossSection::NuFissionCrossSection(const NuFissionCrossSection& orig) : Unimplemented method") ;
}

NuFissionCrossSection::~NuFissionCrossSection() {
    delete data ;
}

void NuFissionCrossSection::collapseSpatialRegions(const string & name,
                                                   const std::vector< std::string > & regionsName) {
    data->buildFamily(2,regionsName,name) ;
}

DoubleMeshField * NuFissionCrossSection::getData() {
    return data ;
}

void NuFissionCrossSection::calculateMacro(const string & mediumName,
                                              vector<CrossSection*> microXS,
                                              const vector< double > & concentrations) {
    FieldIterator it = data->getIterator() ;
    data->setDouble( it(":;"+mediumName) , 0 );
}
