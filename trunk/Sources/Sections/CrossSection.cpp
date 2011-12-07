/* 
 * File:   CrossSection.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 12 juin 2011, 23:14
 */

#include "CrossSection.h"

using namespace std ;

CrossSection::CrossSection() {
}

CrossSection::CrossSection(const CrossSection& orig) {
}

CrossSection::~CrossSection() {
}

void CrossSection::calculateMacro(const string & mediumName, vector<CrossSection*> microXS, const vector< pair< string,double > > & medium ) {
    
}
