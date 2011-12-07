/* 
 * File:   DefaultScatteringCrossSection.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:13
 */

#ifndef DEFAULTSCATTERINGCROSSSECTION_H
#define	DEFAULTSCATTERINGCROSSSECTION_H
#include "CrossSection.h"

class Mesh ;
class EnergyMesh ;
class DoubleMeshField;

class DefaultScatteringCrossSection : public CrossSection {
public:
    DefaultScatteringCrossSection(EnergyMesh * energyMesh, Mesh * spatialMesh);
    DefaultScatteringCrossSection(const DefaultScatteringCrossSection& orig);
    virtual ~DefaultScatteringCrossSection();
    void collapseSpatialRegions(const std::string & name, const std::vector< std::string > & regionsName)  ;
private:
    
    DoubleMeshField * data ;
};

#endif	/* DEFAULTSCATTERINGCROSSSECTION_H */

