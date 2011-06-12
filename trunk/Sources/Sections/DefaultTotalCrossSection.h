/* 
 * File:   DefaultCrossSection.h
 * Author: Phil
 *
 * Created on 1 juin 2011, 22:17
 */

#ifndef DEFAULTTOTALCROSSSECTION_H
#define	DEFAULTTOTALCROSSSECTION_H
#include "CrossSection.h"

class DefaultTotalCrossSection : public CrossSection {
public:
    DefaultTotalCrossSection();
    DefaultTotalCrossSection(const DefaultTotalCrossSection& orig);
    virtual ~DefaultTotalCrossSection();
private:

};

#endif	/* DEFAULTCROSSSECTION_H */

