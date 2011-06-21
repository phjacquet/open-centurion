/* 
 * File:   CartesianOneDimRegion.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 11 juin 2011, 19:06
 */

#include <sstream>
#include "CartesianOneDimRegion.h"

using namespace std;

CartesianOneDimRegion::CartesianOneDimRegion(double l_center, double l_thickness) {
    center=l_center;
    thickness=l_thickness;
}

CartesianOneDimRegion::CartesianOneDimRegion(const CartesianOneDimRegion& orig) {
    center=orig.center;
    thickness=orig.thickness;
}

CartesianOneDimRegion::~CartesianOneDimRegion() {
}

std::string CartesianOneDimRegion::toString() {
    stringstream ss ;
    ss<<"["<<center-thickness/2.<<","<<center+thickness/2<<"]";
    return ss.str();
}