/*
 * File:   NuFissionCrossSection.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:54
 */

#ifndef NUFISSIONCROSSSECTION_H
#define	NUFISSIONCROSSSECTION_H
#include "CrossSection.h"

class Mesh;
class EnergyMesh;
class DoubleMeshField;

class NuFissionCrossSection : public CrossSection {
public:
    NuFissionCrossSection(EnergyMesh * energyMesh, Mesh * spatialMesh);
    NuFissionCrossSection(const NuFissionCrossSection& orig);
    virtual ~NuFissionCrossSection();
    void collapseSpatialRegions(const std::string & name, const std::vector< std::string > & regionsName);
    DoubleMeshField * getData() ;
    void buildData() ;
    void calculateMacro(const std::string & mediumName, std::map< SetOfXS::E_XS, std::vector<CrossSection*> >  mmicroXS, const std::vector< double > & concentrations) ;
    virtual std::string toString(const std::string & option="")  ;
private:

    DoubleMeshField * data;

};

#endif	/* NUFISSIONCROSSSECTION_H */

