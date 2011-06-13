/* 
 * File:   CartesianOneDimRegion.h
 * Author: Sab_n_Phil
 *
 * Created on 11 juin 2011, 19:06
 */

#ifndef CARTESIANONEDIMREGION_H
#define	CARTESIANONEDIMREGION_H
#include "Region.h"

class CartesianOneDimRegion : public Region {
public:
    CartesianOneDimRegion(double l_center, double l_thickness);
    CartesianOneDimRegion(const CartesianOneDimRegion& orig); 
    virtual ~CartesianOneDimRegion();
private:
    double center;
    double thickness;
};

#endif	/* CARTESIANONEDIMREGION_H */
