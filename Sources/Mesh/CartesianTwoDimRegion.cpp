/*
 * File:   CartesianTwoDimRegion.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 11 juin 2011, 19:06
 */

#include <sstream>
#include "CartesianTwoDimRegion.h"

using namespace std;

CartesianTwoDimRegion::CartesianTwoDimRegion(double l_centerX, double l_centerY, double l_thicknessX, double l_thicknessY, string l_name) {
    centerX=l_centerX;
    centerY=l_centerY;
    thicknessX=l_thicknessX;
    thicknessY=l_thicknessY;
    name = l_name ;
}

CartesianTwoDimRegion::CartesianTwoDimRegion(const CartesianTwoDimRegion& orig) {
    centerX=orig.centerX;
    centerY=orig.centerY;
    thicknessX=orig.thicknessX;
    thicknessY=orig.thicknessY;
    name=orig.name ;
}

CartesianTwoDimRegion::~CartesianTwoDimRegion() {
}

std::string CartesianTwoDimRegion::toString() {
    stringstream ss ;
    ss<<"<Cart2D name=\""<<name<<"\"> X : "<<centerX-thicknessX/2.<<" "<<centerX+thicknessX/2<<
                                    " Y : "<<centerY-thicknessY/2.<<" "<<centerY+thicknessY/2<<" </Cart2D>";
    return ss.str();
}
