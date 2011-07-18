/* 
 * File:   NuFissionCrossSection.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:54
 */

#ifndef NUFISSIONCROSSSECTION_H
#define	NUFISSIONCROSSSECTION_H
#include "CrossSection.h"

class NuFissionCrossSection  : public CrossSection {
public:
    NuFissionCrossSection();
    NuFissionCrossSection(const NuFissionCrossSection& orig);
    virtual ~NuFissionCrossSection();
private:

};

#endif	/* NUFISSIONCROSSSECTION_H */

