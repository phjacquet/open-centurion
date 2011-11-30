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

class DoubleMeshField ;

class FieldIterator {
public:
    FieldIterator(const FieldIterator& orig);
    virtual ~FieldIterator();
    FieldIterator & operator()(  const std::string & expression  );
private:
    FieldIterator(DoubleMeshField * l_dmf);
    std::string& get(uint32_t meshIndex, uint32_t regionIndex);

    DoubleMeshField * dmf ;
    std::vector< std::vector< std::string>  > locData ;

    friend class DoubleMeshField ;
};

#endif	/* FIELDITERATOR_H */

