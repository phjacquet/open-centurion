/*
 * File:   Library.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 juin 2011, 22:34
 */

#ifndef LIBRARY_H
#define	LIBRARY_H

#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "Sections/SetOfXS.h"

class EnergyMesh ;
class DiscreteMesh ;
class CartesianOneDimMesh ;

class Library {
public:
    Library(const std::string& fileName);
    virtual ~Library();
    EnergyMesh * getEnergyMesh() ;
    DiscreteMesh * getDiscreteMesh() ;
    std::vector<CrossSection *> setOfMicroXS(SetOfXS::E_XS microType, std::vector< std::string > & nucleiList) ;

private:
    Library(const Library& orig);
    Library& operator=(const Library& );
    bool loadLibraryRootFile(const std::string& fileName) ;
    bool loadEnergyMeshLibraryFile(const std::string& fileName) ;
    bool loadCrossSectionLibraryFile(const std::string& fileName) ;

    std::ofstream logStream ;
    std::map< std::string, std::string > libraries ;
    EnergyMesh * energyMesh ;
    DiscreteMesh * discreteMesh ;
    CartesianOneDimMesh * spatialOneRegionMesh ;
    std::map<std::string, SetOfXS*> problemMicroXS ;
};

#endif	/* LIBRARY_H */

