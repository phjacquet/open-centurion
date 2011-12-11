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

class DoubleMeshField;

class FieldIterator {
public:
    FieldIterator(const FieldIterator& orig);
    virtual ~FieldIterator();
    FieldIterator & operator()(const std::string & expression);
    bool isWideIterator();
    void computePath();
    std::vector< std::vector< std::string*> > &  getPath() ;
    std::string toString();
    
private:
    FieldIterator(DoubleMeshField * l_dmf);
    unsigned size(unsigned meshIndex);
    std::string& get(unsigned meshIndex, unsigned regionIndex);

    DoubleMeshField * dmf;
    std::vector< std::vector< std::string> > locData;
    std::vector< std::vector< std::string*> > path;
    bool wideIterator;

    friend class DoubleMeshField;
};

#endif	/* FIELDITERATOR_H */

