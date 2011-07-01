/* 
 * File:   FieldIterator.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
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
    std::string get(int meshIndex, int regionIndex);
private:
    std::vector<Mesh * > * meshes ;
    std::vector<std::string> meshIndexes;
    std::vector< std::vector< std::string>  > locData ;
};

#endif	/* FIELDITERATOR_H */

