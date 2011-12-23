/*
 * File:   SetOfXS.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 juin 2011, 23:06
 */

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "CrossSection.h"
#include "SetOfXS.h"
#include "CrossSection.h"

using namespace std;

SetOfXS::SetOfXS() {
}

SetOfXS::SetOfXS(const SetOfXS& orig) {
    throw runtime_error("SetOfXS::SetOfXS(const SetOfXS& orig) : unimplemented method");
}
SetOfXS SetOfXS::operator=(const SetOfXS& orig) {
    throw runtime_error("SetOfXS::operator=(const SetOfXS& orig) : unimplemented method");
}

SetOfXS::~SetOfXS() {
    for (map<E_XS, CrossSection *>::iterator it = xsMap.begin(); it != xsMap.end(); it++) {
        try  {
            delete it->second;
        } catch(const exception & e) {
            cout << "SetOfXS::~SetOfXS() : failed to free CrossSection *"<<endl;
            cout << e.what() << endl;
        }
    }
}

void SetOfXS::newXS(CrossSection * xs) {
    xsMap[xs->getType()] = xs;
}

CrossSection * SetOfXS::getXS(E_XS xs) {
    return (xsMap.find(xs)->second);
}

string SetOfXS::toString(const string & option) {
    stringstream ss;
    ss << "<SetOfXS>"<<endl;
    for (map<E_XS, CrossSection *>::iterator it = xsMap.begin(); it != xsMap.end(); it++)
        ss<<it->second->toString(option) ;
    ss << "</SetOfXS>";
    return ss.str();
}
