/*
 * File:   CartesianOneDimRegion.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 11 juin 2011, 19:06
 */

#include <sstream>
#include "CartesianOneDimRegion.h"

using namespace std;

CartesianOneDimRegion::CartesianOneDimRegion(double l_center, double l_thickness, string l_name) {
    center=l_center;
    thickness=l_thickness;
    name = l_name ;
}

CartesianOneDimRegion::CartesianOneDimRegion(const CartesianOneDimRegion& orig) {
    center=orig.center;
    thickness=orig.thickness;
    name=orig.name ;
}

CartesianOneDimRegion::~CartesianOneDimRegion() {
}

double CartesianOneDimRegion::getThickness() const  {
    return thickness;
}

double CartesianOneDimRegion::getCenter() const {
    return center;
}


std::string CartesianOneDimRegion::toString() {
    stringstream ss ;
    ss<<"<Cart1D name=\""<<name<<"\"> "<<center-thickness/2.<<" "<<center+thickness/2<<"</Cart1D>";
    return ss.str();
}
