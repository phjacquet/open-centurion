/* 
 * File:   EnergyMesh.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 13 juin 2011, 02:09
 */

#include <stdexcept>
#include <sstream>
#include "EnergyMesh.h"
#include "EnergyGroup.h"
#include "Exceptions/InputConsistency.h"

using namespace std ;

EnergyMesh::EnergyMesh(const double* groupBoundaries, int size) {
    if (size<2)
        throw InputConsistency(3,LOG_INP_CONS_E("Incorrect size of nodes array")) ;
    energyGroups.clear() ;
    energyGroups.reserve(size-1) ;
    for (int i=0; i<size-1; i++) {
        double boundaryLeft = groupBoundaries[i] ;
        double boundaryRight = groupBoundaries[i+1] ;
        if (boundaryLeft <= boundaryRight) {
            throw InputConsistency(4,LOG_INP_CONS_E("Bad group boundaries order")) ;
        }
        energyGroups.push_back(EnergyGroup(boundaryLeft, boundaryRight));
    }
}


EnergyMesh::EnergyMesh(const EnergyMesh& orig) {
    throw runtime_error("EnergyMesh::EnergyMesh(const EnergyMesh& orig) : Unimplemented method") ;
}

EnergyMesh::~EnergyMesh() {
}

string EnergyMesh::toString() {
    stringstream ss ;
    ss<<"EnergyMesh\n" ;
    for (unsigned int i=0; i<energyGroups.size()-1; i++) {
        ss<<energyGroups[i].toString()<<";";
    }
    ss<<energyGroups.back().toString() ;
    return ss.str();
}