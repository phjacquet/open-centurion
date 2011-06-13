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
    Geometry(const Mesh & l_spatialMesh, const Library& l_library);
    void fill(std::map< std::vector<Region>, std::vector<std::string,double> > mediumInMesh);
    ProblemCrossSections * getXS();
    virtual ~Geometry();
private:
    Geometry(const Geometry& orig);
    Geometry operator=(const Geometry& orig);

    Mesh *spatialMesh  ;
    Library *library  ;
    ProblemCrossSections problemMacroXS ;
};

#endif	/* GEOMETRY_H */

