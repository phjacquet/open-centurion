/*
 * File:   CartesianTwoDimMesh.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 21:26
 */

#ifndef CARTESIANTWODIMMESH_H
#define	CARTESIANTWODIMMESH_H

#include <string>
#include <vector>
#include "Mesh.h"
#include "CartesianTwoDimRegion.h"
#include "CartesianOneDimMesh.h"

class CartesianTwoDimMesh : public Mesh {
public:
    CartesianTwoDimMesh(CartesianOneDimMesh& meshX, CartesianOneDimMesh& meshY) ;
    CartesianTwoDimMesh(const CartesianTwoDimMesh& orig);
    virtual ~CartesianTwoDimMesh();
    const Region* getRegion(unsigned n) const ;
    const Region* getRegion(std::string s) const ;
    unsigned size() const ;

    std::string toString() ;
private:
    std::vector<CartesianTwoDimRegion> regions ;
};

#endif	/* CARTESIANTWODIMMESH_H */

