/* 
 * File:   ProblemCrossSections.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 12 juin 2011, 23:06
 */

#include "ProblemCrossSections.h"

ProblemCrossSections::ProblemCrossSections() {
}

ProblemCrossSections::ProblemCrossSections(const ProblemCrossSections& orig) {
}

ProblemCrossSections::~ProblemCrossSections() {
}

CrossSection * ProblemCrossSections::getCrossSection(E_XS xs) {
    return & (xsMap.find(xs)->second) ;
}
    

