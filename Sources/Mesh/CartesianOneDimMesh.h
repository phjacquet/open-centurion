/* 
 * File:   CartesianOneDimMesh.h
 * Author: Phil
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
    CartesianOneDimMesh(const double* nodes, int size);
    CartesianOneDimMesh(const CartesianOneDimMesh& orig);
    virtual ~CartesianOneDimMesh();
    
    std::string toString() ;
private:
    std::vector<CartesianOneDimRegion> regions ;
};

#endif	/* CARTESIANONEDIMMESH_H */

