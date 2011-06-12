/* 
 * File:   CartesianOneDimMesh.h
 * Author: Phil
 *
 * Created on 1 juin 2011, 21:26
 */

#ifndef CARTESIANONEDIMMESH_H
#define	CARTESIANONEDIMMESH_H

#include<vector>

class CartesianOneDimMesh {
public:
    CartesianOneDimMesh(std::vector<double> & nodesCoordinates);
    CartesianOneDimMesh(const CartesianOneDimMesh& orig);
    virtual ~CartesianOneDimMesh();
private:
    
};

#endif	/* CARTESIANONEDIMMESH_H */

