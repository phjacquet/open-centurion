/* 
 * File:   EnergyMesh.h
 * Author: Sab_n_Phil
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
    EnergyMesh(const double* groupBoundaries, int size);
    EnergyMesh(const EnergyMesh& orig);
    virtual ~EnergyMesh();
    std::string toString() ;
private:
    std::vector<EnergyGroup> energyGroups ;
};

#endif	/* ENERGYMESH_H */

