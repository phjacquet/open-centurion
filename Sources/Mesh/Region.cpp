/*
 * File:   Region.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 13 juin 2011, 01:46
 */

#include "Region.h"
using namespace std;

Region::Region() {
}

Region::Region(const Region& orig) {
}

Region::~Region() {
}

string & Region::getName() {
    return name ;
}
