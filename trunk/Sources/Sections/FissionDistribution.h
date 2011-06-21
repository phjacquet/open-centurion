/* 
 * File:   FissionDistribution.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:54
 */

#ifndef FISSIONDISTRIBUTION_H
#define	FISSIONDISTRIBUTION_H
#include "CrossSection.h"

class FissionDistribution  : public CrossSection {
public:
    FissionDistribution();
    FissionDistribution(const FissionDistribution& orig);
    virtual ~FissionDistribution();
private:

};

#endif	/* FISSIONDISTRIBUTION_H */

