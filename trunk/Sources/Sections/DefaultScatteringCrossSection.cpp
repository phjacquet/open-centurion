/*
 * File:   DefaultScatteringCrossSection.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:13
 */

#include <vector>
#include <stdexcept>
#include "DefaultScatteringCrossSection.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/Mesh.h"
#include "Field/DoubleMeshField.h"

using namespace std ;

DefaultScatteringCrossSection::DefaultScatteringCrossSection(EnergyMesh * energyMesh, Mesh * momentMesh, Mesh * spatialMesh) {
    vector< pair_MeshOption > meshes ;
    meshes.push_back( pair_MeshOption(energyMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption(energyMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption(momentMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption(spatialMesh,DoubleMeshField::LAZY) ) ;
    data = new DoubleMeshField(meshes) ;
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

void DefaultScatteringCrossSection::calculateMacro(const string & mediumName,
                                              vector<CrossSection*> microXS,
                                              const vector< double > & concentrations) {
    FieldIterator it = data->getIterator() ;
    data->setDouble( it(":;"+mediumName) , 0 );
}
