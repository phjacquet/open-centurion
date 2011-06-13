/* 
 * File:   Mesh.h
 * Author: Sab_n_Phil
 *
 * Created on 13 juin 2011, 01:43
 */

#ifndef MESH_H
#define	MESH_H

#include <string>

class Mesh {
public:
    Mesh();
    Mesh(const Mesh& orig);
    virtual ~Mesh();
    virtual std::string toString() = 0 ;
    
private:

};

#endif	/* MESH_H */

