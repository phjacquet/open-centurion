/* 
 * File:   DefaultScatteringCrossSection.h
 * Author: Phil
 *
 * Created on 1 juin 2011, 22:13
 */

#ifndef DEFAULTSCATTERINGCROSSSECTION_H
#define	DEFAULTSCATTERINGCROSSSECTION_H
#include "CrossSection.h"

class DefaultScatteringCrossSection : public CrossSection {
public:
    DefaultScatteringCrossSection();
    DefaultScatteringCrossSection(const DefaultScatteringCrossSection& orig);
    virtual ~DefaultScatteringCrossSection();
private:

};

#endif	/* DEFAULTSCATTERINGCROSSSECTION_H */

