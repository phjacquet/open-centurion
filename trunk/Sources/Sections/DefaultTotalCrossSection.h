/*
 * File:   DefaultCrossSection.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:17
 */

#ifndef DEFAULTTOTALCROSSSECTION_H
#define	DEFAULTTOTALCROSSSECTION_H

#include "CrossSection.h"

class Mesh ;
class EnergyMesh ;
class DoubleMeshField;

class DefaultTotalCrossSection : public CrossSection {
public:
    DefaultTotalCrossSection(EnergyMesh * energyMesh, Mesh * spatialMesh);
    DefaultTotalCrossSection(const DefaultTotalCrossSection& orig);
    virtual ~DefaultTotalCrossSection();
    void collapseSpatialRegions(const std::string & name, const std::vector< std::string > & regionsName)  ;
    DoubleMeshField * getData() ;
    void buildData() ;
    void calculateMacro(const std::string & mediumName, std::vector<CrossSection*> microXS, const std::vector< double > & concentrations ) ;
    virtual std::string toString()  ;

private:

    DoubleMeshField * data ;
};

#endif	/* DEFAULTCROSSSECTION_H */

