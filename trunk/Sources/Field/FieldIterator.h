/* 
 * File:   FieldIterator.h
 * Author: Sab_n_Phil
 *
 * Created on 16 juin 2011, 01:34
 */

#ifndef FIELDITERATOR_H
#define	FIELDITERATOR_H

#include <vector>
#include "Mesh/Mesh.h"
class FieldIterator {
public:
    FieldIterator(std::vector<Mesh * > * l_meshes);
    FieldIterator(const FieldIterator& orig);
    virtual ~FieldIterator();
private:
    std::vector<Mesh * > * meshes ;
    std::vector<std::string> meshIndexes;
};

#endif	/* FIELDITERATOR_H */

