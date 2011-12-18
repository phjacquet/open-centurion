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
#include "Sections/SetOfXS.h"

class Library ;
class Mesh ;
class DiscreteMesh ;
class EnergyMesh ;
class Region ;

class Geometry {
public:
    Geometry(Mesh * l_spatialMesh, Library * l_library);
    void fill(const std::string & name, const std::string regionsName[], unsigned size, const std::vector< std::pair< std::string,double > > & medium);
    void fill(const std::string & name, const std::vector<std::string> & regionsName, const std::vector< std::pair< std::string,double > > & medium);
    void buildMacros() ;
    SetOfXS * getXS();
    virtual ~Geometry();
    virtual std::string toString() ;
private:
    Geometry(const Geometry& orig);
    Geometry operator=(const Geometry& orig);
    void buildXS();

    std::map<std::string, std::pair< std::vector<std::string>,std::vector<double> > > materials ;
    Mesh *spatialMesh  ;
    EnergyMesh * energyMesh ;
    DiscreteMesh * discreteMesh ;
    Library *library  ;
    SetOfXS pbMacXS ;
};

#endif	/* GEOMETRY_H */

