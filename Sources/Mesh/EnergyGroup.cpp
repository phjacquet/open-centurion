/* 
 * File:   EnergyGroup.cpp
 * Author: Sab_n_Phil
 * 
 * Created on 14 juin 2011, 22:12
 */

#include "EnergyGroup.h"

EnergyGroup::EnergyGroup(double l_energyLeft, double l_energyRight) {
    energyLeft = l_energyLeft ;
    energyRight = l_energyRight ;
}

EnergyGroup::EnergyGroup(const EnergyGroup& orig) {
}

EnergyGroup::~EnergyGroup() {
}

