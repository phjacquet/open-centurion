/* 
 * File:   CartesianOneDimRegion.cpp
 * Author: Sab_n_Phil
 * 
 * Created on 11 juin 2011, 19:06
 */

#include "CartesianOneDimRegion.h"

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

