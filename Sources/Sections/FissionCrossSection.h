/* 
 * File:   FissionCrossSection.h
 * Author: Phil
 *
 * Created on 1 juin 2011, 22:54
 */

#ifndef FISSIONCROSSSECTION_H
#define	FISSIONCROSSSECTION_H
#include "CrossSection.h"

class FissionCrossSection  : public CrossSection {
public:
    FissionCrossSection();
    FissionCrossSection(const FissionCrossSection& orig);
    virtual ~FissionCrossSection();
private:

};

#endif	/* FISSIONCROSSSECTION_H */

