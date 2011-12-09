/* 
 * File:   Mesh.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 13 juin 2011, 01:43
 */

#include "Mesh.h"

using namespace std ;

Mesh::Mesh() {
}

Mesh::Mesh(const Mesh& orig) {
}

Mesh::~Mesh() {
}

vector<string> Mesh::getListOfRegionsNames() {
    vector<string> list ;
    for (unsigned i=0; i<size();i++) list.push_back(getRegion(i)->getName()) ;
    return list ;
}