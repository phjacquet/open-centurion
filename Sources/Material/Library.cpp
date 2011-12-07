/* 
 * File:   Library.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 12 juin 2011, 22:34
 */
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Library.h"
#include "Sections/DefaultTotalCrossSection.h"

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

vector<CrossSection *> Library::setOfTotalMicroXS(vector< pair< string,double > > medium) {
    vector<CrossSection *> micros;
    for (uint32_t n = 0; n< medium.size(); n++) {
        if ( problemMicroXS.find(medium[n].first) != problemMicroXS.end()) {
            micros.push_back( problemMicroXS.find(medium[n].first)->second.getXS(ProblemCrossSections::TOTAL) );
        }
        else  {
            stringstream err;
            err<<"Library::setOfTotalMicroXS(vector< pair< string,double > > medium) : it contains unknwon nucleus name :"<<medium[n].first ;
            throw runtime_error(err.str().c_str()) ;
        }
    }
}
   