/*
 * File:   Geometry.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 juin 2011, 22:32
 */

#ifndef GEOMETRY_H
#define	GEOMETRY_H
#include <string>
#include <map>
#include <vector>
#include "Sections/ProblemCrossSections.h"
class Library ;
class Mesh ;
class DiscreteMesh ;
class EnergyMesh ;
class Region ;

class Geometry {
public:
    Geometry(Mesh * l_spatialMesh, Library * l_library);
    void fill(const std::string & name, const std::vector<std::string> & regionsName, const std::vector< std::pair< std::string,double > > & medium);
    ProblemCrossSections * getXS();
    virtual ~Geometry();
private:
    Geometry(const Geometry& orig);
    Geometry operator=(const Geometry& orig);
    void buildXS();

    Mesh *spatialMesh  ;
    EnergyMesh * energyMesh ;
    DiscreteMesh * discreteMesh ;
    Library *library  ;
    ProblemCrossSections pbMacXS ;
};

#endif	/* GEOMETRY_H */

