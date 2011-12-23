/*
 * File:   CrossSection.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 juin 2011, 23:14
 */

#include <sstream>
#include "CrossSection.h"

using namespace std ;

CrossSection::CrossSection() {
    xsType = SetOfXS::NONE ;
}

CrossSection::CrossSection(const CrossSection& orig) {
}

CrossSection::~CrossSection() {
}

SetOfXS::E_XS CrossSection::getType()  {
    return xsType ;
}

string CrossSection::toString(const string & option) {
    stringstream ss;
    ss<<"<CrossSection>"<<endl;
    ss<<"unimplemented method"<<endl;
    ss<<"</CrossSection>"<<endl;
    return ss.str() ;
}
