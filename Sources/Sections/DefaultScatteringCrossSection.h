/*
 * File:   DefaultScatteringCrossSection.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:13
 */

#ifndef DEFAULTSCATTERINGCROSSSECTION_H
#define	DEFAULTSCATTERINGCROSSSECTION_H
#include "CrossSection.h"

class Mesh;
class DiscreteMesh;
class EnergyMesh;
class DoubleMeshField;

class DefaultScatteringCrossSection : public CrossSection {
public:
    DefaultScatteringCrossSection(EnergyMesh * energyMesh, Mesh * momentMesh, Mesh * spatialMesh);
    DefaultScatteringCrossSection(const DefaultScatteringCrossSection& orig);
    virtual ~DefaultScatteringCrossSection();
    void collapseSpatialRegions(const std::string & name, const std::vector< std::string > & regionsName);
    DoubleMeshField * getData() ;
    void buildData() ;
    virtual void calculateMacro(const std::string & mediumName, std::map< SetOfXS::E_XS, std::vector<CrossSection*> >  mmicroXS, const std::vector< double > & concentrations) ;
    virtual std::string toString(const std::string & option="")  ;
private:

    DoubleMeshField * data;
};

#endif	/* DEFAULTSCATTERINGCROSSSECTION_H */

