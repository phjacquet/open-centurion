/*
 * File:   CartesianOneDimMesh.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 21:26
 */
#include <cstdio>
#include <stdexcept>
#include <sstream>
#include <basetsd.h>
#include <stdlib.h>
#include "CartesianOneDimMesh.h"
#include "Exceptions/InputConsistency.h"

using namespace std ;

CartesianOneDimMesh::CartesianOneDimMesh(const double* nodes, unsigned size)  {
    if (size<2)
        throw InputConsistency(1,LOG_INP_CONS_E("Incorrect size of nodes array"));
    regions.clear() ;
    regions.reserve(size-1) ;
    for (unsigned i=0; i<size-1; i++) {
        double boundaryLeft = nodes[i] ;
        double boundaryRight = nodes[i+1] ;
        double center = 0.5*(boundaryLeft + boundaryRight) ;
        double thickness = boundaryRight-boundaryLeft;
        if (thickness <= 0.) {
            throw InputConsistency(2,LOG_INP_CONS_E("Bad nodes order")) ;
        }
        stringstream ss ;
        ss<<i ;
        regions.push_back(CartesianOneDimRegion( center, thickness, ss.str() ) );
    }
}

CartesianOneDimMesh::CartesianOneDimMesh(const CartesianOneDimMesh& orig) {
    throw runtime_error("CartesianOneDimMesh::CartesianOneDimMesh(const CartesianOneDimMesh& orig) : Unimplemented method") ;
}

CartesianOneDimMesh::~CartesianOneDimMesh() {
}

Region* CartesianOneDimMesh::getRegion(unsigned n) {
    return &regions[n] ;
}

Region* CartesianOneDimMesh::getRegion(std::string s) {
    unsigned n ;
    stringstream ss(s) ;
    ss>>n ;
    if (n>=regions.size()) return 0 ;
    else return &regions[n] ;
}

unsigned CartesianOneDimMesh::size()  {
    return regions.size();
}

string CartesianOneDimMesh::toString() {
    stringstream ss ;
    ss<<"<CartesianOneDimMesh>"<<endl ;
    for (unsigned i=0; i<regions.size(); i++) {
        ss<<regions[i].toString()<<endl;
    }
    ss<<"</CartesianOneDimMesh>\n" ;
    return ss.str();
}
