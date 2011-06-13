/* 
 * File:   ProblemCrossSections.h
 * Author: Sab_n_Phil
 *
 * Created on 12 juin 2011, 23:06
 */

#ifndef PROBLEMCROSSSECTIONS_H
#define	PROBLEMCROSSSECTIONS_H
#include <map>
#include "CrossSection.h"

class ProblemCrossSections {
public:
    ProblemCrossSections();
    virtual ~ProblemCrossSections();
    
    enum E_XS {
        TOTAL,
        SCATTERING,
        FISSION,
        FISSION_DISTRIBUTION
    };
    
private:
    ProblemCrossSections(const ProblemCrossSections& orig);
    ProblemCrossSections operator=(const ProblemCrossSections& orig);
    
    std::map<E_XS, CrossSection> xsMap;
};

#endif	/* PROBLEMCROSSSECTIONS_H */

