/*
 * File:   EnergyGroup.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 14 juin 2011, 22:12
 */

#include <sstream>
#include "EnergyGroup.h"

using namespace std ;

EnergyGroup::EnergyGroup(double l_energyLeft, double l_energyRight, string l_name) {
    energyLeft = l_energyLeft ;
    energyRight = l_energyRight ;
    name = l_name ;
}

EnergyGroup::EnergyGroup(const EnergyGroup& orig) {
    energyLeft = orig.energyLeft ;
    energyRight = orig.energyRight ;
    name = orig.name ;
}

EnergyGroup::~EnergyGroup() {
}

string EnergyGroup::toString() {
    stringstream ss ;
    ss<<"<G name=\""<<name<<"\"> "<<energyLeft<<" "<<energyRight<<"</G>";
    return ss.str();
}
