/* 
 * File:   Library.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 juin 2011, 22:34
 */

#ifndef LIBRARY_H
#define	LIBRARY_H
#include <string>
#include <map>
#include <vector>
#include "Mesh/EnergyMesh.h"
#include "Sections/ProblemCrossSections.h"

class DefaultTotalCrossSection ;

class Library {
public:
    Library(const std::string& fileName);
    virtual ~Library();
    EnergyMesh * getEnergyMesh() ;
    std::vector<CrossSection *> setOfTotalMicroXS(std::vector< std::pair< std::string,double > > medium) ;
private:
    Library(const Library& orig);
    Library& operator=(const Library& );
    
    EnergyMesh * energyMesh ;
    std::map<std::string, ProblemCrossSections> problemMicroXS ;
};

#endif	/* LIBRARY_H */

