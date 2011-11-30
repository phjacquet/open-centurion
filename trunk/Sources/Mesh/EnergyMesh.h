/* 
 * File:   EnergyMesh.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 13 juin 2011, 02:09
 */

#ifndef ENERGYMESH_H
#define	ENERGYMESH_H

#include <vector>
#include "Mesh.h"
#include "EnergyGroup.h"

class EnergyMesh : public Mesh {
public:
    EnergyMesh(const double* groupBoundaries, uint32_t size);
    EnergyMesh(const EnergyMesh& orig);
    virtual ~EnergyMesh();
    Region* getRegion(uint32_t n) ;
    Region* getRegion(std::string s) ;
    uint32_t size() ;
    
    std::string toString() ;
private:
    
    std::vector<EnergyGroup> energyGroups ;
};

#endif	/* ENERGYMESH_H */

