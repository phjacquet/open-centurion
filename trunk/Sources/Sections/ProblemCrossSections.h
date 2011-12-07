/* 
 * File:   ProblemCrossSections.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
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
    void newTotalXS(CrossSection * totalXS) ;
    void newScatXS( CrossSection * scatXS ) ;
    void newNuFissXS( CrossSection * nuFissionXS ) ;
    void newFissDistXS( CrossSection * fissionDistribution ) ;
    enum E_XS {
        TOTAL,
        SCATTERING,
        NUFISSION,
        FISSION_DISTRIBUTION
    };
    
    CrossSection * getXS(E_XS xs) ;
    
private:
    ProblemCrossSections(const ProblemCrossSections& orig);
    ProblemCrossSections operator=(const ProblemCrossSections& orig);
    
    std::map<E_XS, CrossSection *> xsMap;
};

#endif	/* PROBLEMCROSSSECTIONS_H */

