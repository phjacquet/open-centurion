/* 
 * File:   CartesianOneDimMesh.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 1 juin 2011, 21:26
 */

#include <stdexcept>
#include <sstream>
#include "CartesianOneDimMesh.h"
#include "Exceptions/InputConsistency.h"

using namespace std ;

CartesianOneDimMesh::CartesianOneDimMesh(const double* nodes, int size)  {
    if (size<2)
        throw InputConsistency(1,LOG_INP_CONS_E("Incorrect size of nodes array"));
    regions.clear() ;
    regions.reserve(size-1) ;
    for (int i=0; i<size-1; i++) {
        double boundaryLeft = nodes[i] ;
        double boundaryRight = nodes[i+1] ;
        double center = 0.5*(boundaryLeft + boundaryRight) ;
        double thickness = boundaryRight-boundaryLeft;
        if (thickness <= 0.) {
            throw InputConsistency(2,LOG_INP_CONS_E("Bad nodes order")) ;
        }
        regions.push_back(CartesianOneDimRegion(center, thickness));
    }
}

CartesianOneDimMesh::CartesianOneDimMesh(const CartesianOneDimMesh& orig) {
    throw runtime_error("CartesianOneDimMesh::CartesianOneDimMesh(const CartesianOneDimMesh& orig) : Unimplemented method") ;
}

CartesianOneDimMesh::~CartesianOneDimMesh() {
}

string CartesianOneDimMesh::toString() {
    stringstream ss ;
    ss<<"CartesianOneDimMesh\n" ;
    for (unsigned int i=0; i<regions.size()-1; i++) {
        ss<<regions[i].toString()<<";";
    }
    ss<<regions.back().toString() ;
    return ss.str();
}
