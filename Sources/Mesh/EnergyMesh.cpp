/* 
 * File:   EnergyMesh.cpp
 * Author: Sab_n_Phil
 * 
 * Created on 13 juin 2011, 02:09
 */

#include <exception>
#include "EnergyMesh.h"
#include "EnergyGroup.h"

EnergyMesh::EnergyMesh(const double* groupBoundaries, int size) {
    energyGroups.clear() ;
    energyGroups.reserve(size-1) ;
    for (int i=0; i<size-1; i++) {
        double boundaryLeft = groupBoundaries[i] ;
        double boundaryRight = groupBoundaries[i+1] ;
        if (boundaryLeft <= boundaryRight) {
            throw InputConsistency(1,"Bad group boundaries order") ;
        }
        energyGroups.push_back(EnergyGroup(boundaryLeft, boundaryRight));
    }
}


EnergyMesh::EnergyMesh(const EnergyMesh& orig) {
    throw runtime_error("Unimplemented method") ;
}

EnergyMesh::~EnergyMesh() {
}
