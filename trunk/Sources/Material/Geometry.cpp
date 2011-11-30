/* 
 * File:   Geometry.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 12 juin 2011, 22:32
 */
#include <stdexcept>
#include "Geometry.h"
#include "Library.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/Region.h"

using namespace std;

Geometry::Geometry(Mesh * l_spatialMesh, Library * l_library) {
    spatialMesh = l_spatialMesh ;
    library = l_library ;
    energyMesh = library->getEnergyMesh();
}
    
Geometry::~Geometry() {
}


Geometry::Geometry(const Geometry& orig) {
    throw runtime_error("Geometry::Geometry(const Geometry& orig)") ;
}

Geometry Geometry::operator=(const Geometry& orig) {
    throw runtime_error("Geometry::Geometry operator=(const Geometry& orig)") ;
}

void Geometry::fill(const vector<string> & regionsName, vector< pair< string,double > > medium) {
    for (uint32_t region_id = 0 ; region_id < regionsName.size() ; region_id++) {
        //problemMacroXS.getCrossSection(ProblemCrossSections.TOTAL) ;
    }
}

ProblemCrossSections * Geometry::getXS() {
    return &problemMacroXS;
}
