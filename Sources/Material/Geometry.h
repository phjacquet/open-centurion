/* 
 * File:   Geometry.h
 * Author: Sab_n_Phil
 *
 * Created on 12 juin 2011, 22:32
 */

#ifndef GEOMETRY_H
#define	GEOMETRY_H
#include <string>
#include <map>
#include <vector>
#include "Library.h"
#include "Mesh/Mesh.h"
#include "Mesh/Region.h"
#include "Sections/ProblemCrossSections.h"
class Geometry {
public:
    Geometry(Mesh * l_spatialMesh, Library& l_library);
    void fill(const std::vector<Region *> & regions, std::vector< std::pair< std::string,double > > medium);
    ProblemCrossSections * getXS();
    virtual ~Geometry();
private:
    Geometry(const Geometry& orig);
    Geometry operator=(const Geometry& orig);

    Mesh *spatialMesh  ;
    Library *library  ;
    EnergyMesh * energyMesh ;
    ProblemCrossSections problemMacroXS ;
};

#endif	/* GEOMETRY_H */

