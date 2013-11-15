/*
 * File:   CartesianTwoDimRegion.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 11 juin 2011, 19:06
 */

#ifndef CARTESIANTWODIMREGION_H
#define	CARTESIANTWODIMREGION_H
#include "Region.h"

class CartesianTwoDimRegion : public Region {
public:
    CartesianTwoDimRegion(double l_centerX, double l_centerY, double l_thicknessX, double l_thicknessY, std::string l_name);
    CartesianTwoDimRegion(const CartesianTwoDimRegion& orig);
    virtual ~CartesianTwoDimRegion();
    std::string toString() ;
private:
    double centerX;
    double centerY;
    double thicknessX;
    double thicknessY;
};

#endif	/* CARTESIANTWODIMREGION_H */

