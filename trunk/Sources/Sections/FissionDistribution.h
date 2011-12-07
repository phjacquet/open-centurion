/* 
 * File:   FissionDistribution.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:54
 */

#ifndef FISSIONDISTRIBUTION_H
#define	FISSIONDISTRIBUTION_H
#include "CrossSection.h"

class Mesh ;
class EnergyMesh ;
class DoubleMeshField;

class FissionDistribution  : public CrossSection {
public:
    FissionDistribution(EnergyMesh * energyMesh, Mesh * spatialMesh);
    FissionDistribution(const FissionDistribution& orig);
    virtual ~FissionDistribution();
    void collapseSpatialRegions(const std::string & name, const std::vector< std::string > & regionsName)  ;
private:

    DoubleMeshField * data ;
    
};

#endif	/* FISSIONDISTRIBUTION_H */

