/* 
 * File:   CartesianOneDimMesh.cpp
 * Author: Phil
 * 
 * Created on 1 juin 2011, 21:26
 */
#include <sstream>
#include "CartesianOneDimMesh.h"
#include "Exception/InputConsistency.h"

using namespace std ;

CartesianOneDimMesh::CartesianOneDimMesh(const double* nodes, int size)  {
    regions.clear() ;
    regions.reserve(size-1) ;
    for (int i=0; i<size-1; i++) {
        double boundaryLeft = nodes[i] ;
        double boundaryRight = nodes[i+1] ;
        double center = 0.5*(boundaryLeft + boundaryRight) ;
        double thickness = boundaryRight-boundaryLeft;
        if (thickness <= 0.) {
            throw InputConsistency(1,"Bad nodes order") ;
        }
        regions.push_back(CartesianOneDimRegion(center, thickness));
    }
}

CartesianOneDimMesh::CartesianOneDimMesh(const CartesianOneDimMesh& orig) {
}

CartesianOneDimMesh::~CartesianOneDimMesh() {
}

std::string CartesianOneDimMesh::toString() {
    stringstream ss ;
    ss<<"CartesianOneDimMesh\n" ;
    for (int i=0; i<regions.size()-1; i++) {
        ss<<regions[i].toString()<<";";
    }
    ss<<regions.back().toString() ;
    return ss.str();
}
