/*
 * File:   InputConsistency.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 13 juin 2011, 01:43
 */

//1: CartesianOneDimMesh constructor, array size
//2: CartesianOneDimMesh constructor, node order
//3: EnergyMesh constructor, array size
//4: EnergyMesh constructor, node order
//5: DoubleMeshField buildFamily(), for bad mesh option
//6: DoubleMeshField buildFamily(), for bad family definition


#include <sstream>
#include "InputConsistency.h"
using namespace std;

InputConsistency::InputConsistency(int l_id , const string& l_d , int l_lvl ) throw ()
: id(l_id), description(l_d), level(l_lvl) {
	stringstream ss ;
    ss<<"InputConsistency #"<<id<<" - LEVEL "<<level<<" - "<<description ;
    whatMsg=ss.str() ;
}

const char* InputConsistency::what() const throw () {
	return whatMsg.c_str();
}

int InputConsistency::getLevel() const throw () {
    return level;
}

InputConsistency::~InputConsistency() throw () {
}
