/*
 * File:   EnergyMesh.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 13 juin 2011, 02:09
 */

#include <stdexcept>
#include <sstream>
#include <stdlib.h>
#include "EnergyMesh.h"
#include "EnergyGroup.h"
#include "Exceptions/InputConsistency.h"

using namespace std ;

EnergyMesh::EnergyMesh(const double* groupBoundaries, unsigned size) {
    if (size<2)
        throw InputConsistency(3,LOG_INP_CONS_E("Incorrect size of nodes array")) ;
    energyGroups.clear() ;
    energyGroups.reserve(size-1) ;
    for (unsigned i=0; i<size-1; i++) {
        double boundaryLeft = groupBoundaries[i] ;
        double boundaryRight = groupBoundaries[i+1] ;
        if (boundaryLeft <= boundaryRight) {
            throw InputConsistency(4,LOG_INP_CONS_E("Bad group boundaries order")) ;
        }
        stringstream ss ;
        ss<<i ;
        energyGroups.push_back( EnergyGroup(boundaryLeft, boundaryRight, ss.str()) );
    }
}


EnergyMesh::EnergyMesh(const EnergyMesh& orig) {
    throw runtime_error("EnergyMesh::EnergyMesh(const EnergyMesh& orig) : Unimplemented method") ;
}

EnergyMesh::~EnergyMesh() {
}

Region* EnergyMesh::getRegion(unsigned n) {
    return &energyGroups[n] ;
}

Region* EnergyMesh::getRegion(std::string s) {
    unsigned n ;
    stringstream ss(s) ;
    ss>>n ;
    if (n>=energyGroups.size()) return 0 ;
    else return &energyGroups[n] ;
}

unsigned EnergyMesh::size() const {
    return energyGroups.size();
}

string EnergyMesh::toString() {
    stringstream ss ;
    ss<<"<EnergyMesh>"<<endl ;
    for (unsigned i=0; i < energyGroups.size(); i++) {
        ss<<energyGroups[i].toString()<<endl;
    }
    ss<<"</EnergyMesh>\n" ;
    return ss.str();
}
