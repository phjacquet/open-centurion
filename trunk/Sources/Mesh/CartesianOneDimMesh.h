/* 
 * File:   CartesianOneDimMesh.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 21:26
 */

#ifndef CARTESIANONEDIMMESH_H
#define	CARTESIANONEDIMMESH_H

#include <string>
#include<vector>
#include "Mesh.h"
#include "CartesianOneDimRegion.h"

class CartesianOneDimMesh : public Mesh {
public:
    CartesianOneDimMesh(const double* nodes, uint32_t size);
    CartesianOneDimMesh(const CartesianOneDimMesh& orig);
    virtual ~CartesianOneDimMesh();
    Region* getRegion(uint32_t n) ;
    Region* getRegion(std::string s)  ;
    uint32_t size() ;
    
    std::string toString() ;
private:
    std::vector<CartesianOneDimRegion> regions ;
};

#endif	/* CARTESIANONEDIMMESH_H */

