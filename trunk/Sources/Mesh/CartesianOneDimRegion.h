/*
 * File:   CartesianOneDimRegion.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 11 juin 2011, 19:06
 */

#ifndef CARTESIANONEDIMREGION_H
#define	CARTESIANONEDIMREGION_H
#include "Region.h"

class CartesianOneDimRegion : public Region {
public:
    CartesianOneDimRegion(double l_center, double l_thickness, std::string l_name);
    CartesianOneDimRegion(const CartesianOneDimRegion& orig);
    virtual ~CartesianOneDimRegion();
    std::string toString() ;
    double getThickness() const ;
    double getCenter() const ;

private:
    double center;
    double thickness;
};

#endif	/* CARTESIANONEDIMREGION_H */

