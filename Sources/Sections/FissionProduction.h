/*
 * File:   FissionProduction.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:54
 */

#ifndef FISSIONPRODUCTION_H
#define FISSIONPRODUCTION_H

#include "CrossSection.h"

class Mesh;
class EnergyMesh;
class DoubleMeshField;

class FissionProduction : public CrossSection {
public:
    FissionProduction(EnergyMesh * energyMesh, Mesh * spatialMesh);
    FissionProduction(const FissionProduction& orig);
    virtual ~FissionProduction();
    void collapseSpatialRegions(const std::string & name, const std::vector< std::string > & regionsName);
    DoubleMeshField * getData() ;
    void buildData() ;
    void calculateMacro(const std::string & mediumName, std::map< SetOfXS::E_XS, std::vector<CrossSection*> >  mmicroXS, const std::vector< double > & concentrations) ;
    virtual std::string toString(const std::string & option="")  ;
private:

    DoubleMeshField * data;

};

#endif // FISSIONPRODUCTION_H
