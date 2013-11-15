/*
 * File:   CartesianTwoDimMesh.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 21:26
 */
#include <cstdio>
#include <stdexcept>
#include <sstream>
#include <basetsd.h>
#include <stdlib.h>
#include "CartesianTwoDimMesh.h"
#include "Exceptions/InputConsistency.h"

using namespace std ;

CartesianTwoDimMesh::CartesianTwoDimMesh(CartesianOneDimMesh& meshX, CartesianOneDimMesh& meshY)  {
    regions.clear() ;
    regions.reserve(meshX.size()*meshY.size());

    for (unsigned ix=0; ix<meshX.size(); ix++) {
        for (unsigned iy=0; iy<meshY.size(); iy++) {

            CartesianOneDimRegion* rx = dynamic_cast<CartesianOneDimRegion*>(meshX.getRegion(ix)) ;
            CartesianOneDimRegion* ry = dynamic_cast<CartesianOneDimRegion*>(meshY.getRegion(iy)) ;
            double thicknessX=rx->getThickness();
            double thicknessY=ry->getThickness();
            double centerX=rx->getCenter();
            double centerY=ry->getCenter();
            stringstream ss ;
            ss<<ix<<"_"<<iy ;
            regions.push_back(CartesianTwoDimRegion( centerX, centerY, thicknessX, thicknessY, ss.str() ) );
        }
    }
}

CartesianTwoDimMesh::CartesianTwoDimMesh(const CartesianTwoDimMesh& orig) {
    throw runtime_error("CartesianTwoDimMesh::CartesianTwoDimMesh(const CartesianTwoDimMesh& orig) : Unimplemented method") ;
}

CartesianTwoDimMesh::~CartesianTwoDimMesh() {
}

const Region* CartesianTwoDimMesh::getRegion(unsigned n) const {
    return &regions[n] ;
}

const Region* CartesianTwoDimMesh::getRegion(std::string s) const {
    unsigned n ;
    stringstream ss(s) ;
    ss>>n ;
    if (n>=regions.size()) return 0 ;
    else return &regions[n] ;
}

unsigned  CartesianTwoDimMesh::size() const {
    return regions.size();
}

string CartesianTwoDimMesh::toString() {
    stringstream ss ;
    ss<<"<CartesianTwoDimMesh>"<<endl ;
    for (unsigned i=0; i<regions.size(); i++) {
        ss<<regions[i].toString()<<endl;
    }
    ss<<"</CartesianTwoDimMesh>\n" ;
    return ss.str();
}
