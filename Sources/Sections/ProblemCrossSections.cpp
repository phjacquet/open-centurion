/* 
 * File:   ProblemCrossSections.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 12 juin 2011, 23:06
 */

#include <stdexcept>
#include "ProblemCrossSections.h"

using namespace std;

ProblemCrossSections::ProblemCrossSections() {
}

ProblemCrossSections::ProblemCrossSections(const ProblemCrossSections& orig) {
    throw runtime_error("ProblemCrossSections::ProblemCrossSections(const ProblemCrossSections& orig)");
}

ProblemCrossSections::~ProblemCrossSections() {
    for (map<E_XS, CrossSection *>::iterator it = xsMap.begin(); it != xsMap.end(); it++) {
        delete it->second;
    }
}

void ProblemCrossSections::newTotalXS(CrossSection * totalXS) {
    xsMap[TOTAL] = totalXS;
}

void ProblemCrossSections::newScatXS(CrossSection * scatXS) {
    xsMap[SCATTERING] = scatXS;
}

void ProblemCrossSections::newNuFissXS(CrossSection * nuFissionXS) {
    xsMap[NUFISSION] = nuFissionXS;
}

void ProblemCrossSections::newFissDistXS(CrossSection * fissionDistribution) {
    xsMap[FISSION_DISTRIBUTION] = fissionDistribution;
}

CrossSection * ProblemCrossSections::getXS(E_XS xs) {
    return (xsMap.find(xs)->second);
}


