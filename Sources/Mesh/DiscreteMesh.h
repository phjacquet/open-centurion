/*
 * File:   DiscreteMesh.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 décembre 2011, 0h44
 */

#ifndef DISCRETEMESH_H
#define	DISCRETEMESH_H

#include <string>
#include <vector>
#include "Mesh.h"
#include "DiscreteRegion.h"

class DiscreteMesh : public Mesh {
public:
    DiscreteMesh(unsigned size);
    DiscreteMesh(const DiscreteMesh& orig);
    virtual ~DiscreteMesh();
    Region* getRegion(unsigned n) ;
    Region* getRegion(std::string s) ;
    unsigned size() const ;

    std::string toString() ;
private:
    std::vector<DiscreteRegion> regions ;
};

#endif	/* DISCRETEMESH_H */

