/* 
 * File:   Library.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 12 juin 2011, 22:34
 */
#include <iostream>
#include "Library.h"
using namespace std;

Library::Library(const string& fileName) {
    double groupBoundaries[] = {18.0E6,1.0E-11};
    energyMesh=new EnergyMesh(groupBoundaries, 2);
    
}

Library::~Library() {
    delete energyMesh ;
}

EnergyMesh * Library::getEnergyMesh() {
    return energyMesh ;
}