/* 
 * File:   Mesh.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 13 juin 2011, 01:43
 */

#ifndef MESH_H
#define	MESH_H

#include <vector>
#include <string>
#include <Mesh/Region.h>

class Mesh {
public:
    Mesh();
    Mesh(const Mesh& orig);
    virtual ~Mesh();
    virtual Region* getRegion(unsigned n) = 0 ;
    virtual Region* getRegion(std::string s) = 0 ;
    virtual std::vector<std::string> getListOfRegionsNames() ;
    virtual unsigned size() = 0 ;
    virtual std::string toString() = 0 ;    
private:
    
};

#endif	/* MESH_H */

