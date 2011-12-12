/*
 * File:   DiscreteRegion.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 décembre 2011, 0h44
 */

#ifndef DISCRETEREGION_H
#define DISCRETEREGION_H

#include "Region.h"

class DiscreteRegion : public Region
{
    public:
        DiscreteRegion(std::string l_name);
        DiscreteRegion(const DiscreteRegion& orig);

        virtual ~DiscreteRegion();
        std::string toString() ;
};

#endif // DISCRETEREGION_H
