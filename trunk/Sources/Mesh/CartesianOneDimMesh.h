/*
 * File:   CartesianOneDimMesh.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 21:26
 */

#ifndef CARTESIANONEDIMMESH_H
#define	CARTESIANONEDIMMESH_H

#include <string>
#include <vector>
#include "Mesh.h"
#include "CartesianOneDimRegion.h"

class CartesianOneDimMesh : public Mesh {
public:
    CartesianOneDimMesh(const double* nodes, unsigned size);
    CartesianOneDimMesh(const CartesianOneDimMesh& orig);
    virtual ~CartesianOneDimMesh();
    Region* getRegion(unsigned n) ;
    Region* getRegion(std::string s)  ;
    unsigned size() ;

    std::string toString() ;
private:
    std::vector<CartesianOneDimRegion> regions ;
};

#endif	/* CARTESIANONEDIMMESH_H */

