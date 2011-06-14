/* 
 * File:   EnergyGroup.h
 * Author: Sab_n_Phil
 *
 * Created on 14 juin 2011, 22:12
 */

#ifndef ENERGYGROUP_H
#define	ENERGYGROUP_H

#include "Region.h"

class EnergyGroup : public Region {
public:
    EnergyGroup(double l_energyLeft, double l_energyRight);
    EnergyGroup(const EnergyGroup& orig);
    virtual ~EnergyGroup();
private:
    double energyLeft;
    double energyRight;
};

#endif	/* ENERGYGROUP_H */

