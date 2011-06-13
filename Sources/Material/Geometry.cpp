/* 
 * File:   Geometry.cpp
 * Author: Sab_n_Phil
 * 
 * Created on 12 juin 2011, 22:32
 */

#include "Geometry.h"

using namespace std;

Geometry::Geometry(const Mesh & l_spatialMesh, const Library& l_library) {
    
}

void Geometry::fill(map< vector<Region>, vector<string,double> > mediumInMesh){
    
}

ProblemCrossSections * Geometry::getXS() {
    return &problemMacroXS;
}
    
Geometry::~Geometry() {
}

