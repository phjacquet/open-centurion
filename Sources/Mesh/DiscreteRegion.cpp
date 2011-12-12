/*
 * File:   DiscreteRegion.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 décembre 2011, 0h44
 */

#include <sstream>
#include "DiscreteRegion.h"

using namespace std ;

DiscreteRegion::DiscreteRegion(std::string l_name) {
    name = l_name ;
}
DiscreteRegion::DiscreteRegion(const DiscreteRegion& orig) {
    name=orig.name ;
}
DiscreteRegion::~DiscreteRegion() {
}
string DiscreteRegion::toString() {
    stringstream ss ;
    ss<<"[ <"<<name<<">"<<"]";
    return ss.str();
}
