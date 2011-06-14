/* 
 * File:   Geometry.cpp
 * Author: Sab_n_Phil
 * 
 * Created on 12 juin 2011, 22:32
 */

#include "Geometry.h"

using namespace std;

Geometry::Geometry(Mesh * l_spatialMesh, Library& l_library) {
    spatialMesh = l_spatialMesh ;
    library = & l_library ;
    energyMesh = library->getEnergyMesh();
}

void Geometry::fill(const vector<Region *>& regions, vector< pair< string,double > > medium){
    for (int region_id = 0 ; region_id < regions.size() ; region_id++) {
        //problemMacroXS.getCrossSection(ProblemCrossSections.TOTAL) ;
    }
}

ProblemCrossSections * Geometry::getXS() {
    return &problemMacroXS;
}
    
Geometry::~Geometry() {
}

