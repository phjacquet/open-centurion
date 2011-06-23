/* 
 * File:   EnergyGroup.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 14 juin 2011, 22:12
 */

#ifndef ENERGYGROUP_H
#define	ENERGYGROUP_H

#include "Region.h"

class EnergyGroup : public Region {
public:
    EnergyGroup(double l_energyLeft, double l_energyRight, std::string l_name);
    EnergyGroup(const EnergyGroup& orig);
    virtual ~EnergyGroup();
    std::string toString() ;
private:
    double energyLeft;
    double energyRight;
};

#endif	/* ENERGYGROUP_H */

