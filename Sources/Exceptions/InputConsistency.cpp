/* 
 * File:   InputConsistency.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 13 juin 2011, 01:43
 */

#include <sstream>
#include "InputConsistency.h"
using namespace std;

InputConsistency::InputConsistency(int l_id , const string& l_d , int l_lvl ) throw ()
: id(l_id), description(l_d), level(l_lvl) {
}

const char* InputConsistency::what() const throw () {
    stringstream ss ;
    ss<<"InputConsistency #"<<id<<" : "<<description<<" - LEVEL "<<level ;
    return ss.str().c_str();
}

int InputConsistency::getLevel() const throw () {
    return level;
}

InputConsistency::~InputConsistency() throw () {
}
