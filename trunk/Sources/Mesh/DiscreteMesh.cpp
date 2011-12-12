/*
 * File:   DiscreteMesh.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 décembre 2011, 0h44
 */

#include <cstdio>
#include <stdexcept>
#include <sstream>
#include <basetsd.h>
#include <stdlib.h>
#include "DiscreteMesh.h"
#include "Exceptions/InputConsistency.h"

using namespace std ;

DiscreteMesh::DiscreteMesh(unsigned size)  {
    if (size==0)
        throw InputConsistency(1,LOG_INP_CONS_E("Null size for DiscreteMesh"));
    regions.clear() ;
    regions.reserve(size) ;
    for (unsigned i=0; i<size; i++) {
        stringstream ss ;
        ss<<"D"<<i ;
        regions.push_back( DiscreteRegion(ss.str()) );
    }
}

DiscreteMesh::DiscreteMesh(const DiscreteMesh& orig) {
    throw runtime_error("DiscreteMesh::DiscreteMesh(const DiscreteMesh& orig) : Unimplemented method") ;
}

DiscreteMesh::~DiscreteMesh() {
}

Region* DiscreteMesh::getRegion(unsigned n) {
    return &regions[n] ;
}

Region* DiscreteMesh::getRegion(std::string s) {
    unsigned n ;
    stringstream ss(s) ;
    ss>>n ;
    if (n>=regions.size()) return 0 ;
    else return &regions[n] ;
}

unsigned DiscreteMesh::size()  {
    return regions.size();
}

string DiscreteMesh::toString() {
    stringstream ss ;
    ss<<"DiscreteMesh\n" ;
    for (unsigned i=0; i<regions.size()-1; i++) {
        ss<<regions[i].toString()<<";";
    }
    ss<<regions.back().toString() ;
    return ss.str();
}
