/* 
 * File:   DoubleMeshField.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 15 juin 2011, 22:33
 */

#include <stdexcept>
#include <iostream>
#include "DoubleMeshField.h"
#include "Exceptions/InputConsistency.h"

using namespace std;


DoubleMeshField::DoubleMeshField(vector< pair< Mesh*, OptionMeshField> >& l_meshes) {
    lock = true ;
    for (uint32_t i = 0; i< l_meshes.size() ; i++) {
        meshes.push_back(l_meshes[i].first) ;
        options.push_back(l_meshes[i].second) ;
    }
    mappings.resize(l_meshes.size()) ;
    sizes.resize(l_meshes.size(),0) ;
    buildFullMeshesMapping() ;
}

DoubleMeshField::DoubleMeshField(const DoubleMeshField& orig) {
    throw runtime_error("DoubleMeshField::DoubleMeshField(const DoubleMeshField& orig) : Unimplemented method") ;
}

DoubleMeshField::~DoubleMeshField() {
}

void DoubleMeshField::buildFullMeshesMapping() {
    lock = true ;
    for (uint32_t meshIndex = 0; meshIndex< meshes.size() ; meshIndex++) {
        if (options[meshIndex] == FULL) {
            mappings[meshIndex].clear() ;
            for (uint32_t r = 0; r < meshes[meshIndex]->size() ; r++) {
                string rname = meshes[meshIndex]->getRegion(r)->getName() ;
                cout<<r<<":"<<rname<<endl;
                mappings[meshIndex][rname] = r ;
            }
            sizes[meshIndex] = mappings[meshIndex].size() ;
        }
    }
}

void DoubleMeshField::buildFamily(uint32_t meshIndex, vector<string> regionsName, string familyName) {
    lock = true ;
    if (meshIndex > meshes.size())
        throw InputConsistency(5,LOG_INP_CONS_E("mesh index is out of range")) ;
    if (options[meshIndex] != LAZY) 
        throw InputConsistency(5,LOG_INP_CONS_E("FULL mesh does not support builFamily functionality")) ;
    if (mappings[meshIndex].find(familyName) != mappings[meshIndex].end() ) 
        throw InputConsistency(6,LOG_INP_CONS_E(string("Region ")+familyName+ " is already mapped")) ;
    for (uint32_t r = 0; r < regionsName.size() ; r++) {
        if (mappings[meshIndex].find(regionsName[r]) != mappings[meshIndex].end() ) 
            throw InputConsistency(6,LOG_INP_CONS_E(string("Region ")+regionsName[r]+ " is already mapped")) ;
    }
    
    if (options[meshIndex] == LAZY) {
        for (uint32_t r = 0; r < regionsName.size() ; r++) {
            string rname = regionsName[r] ;
            mappings[meshIndex][rname] = sizes[meshIndex] ;
        }
        mappings[meshIndex][familyName] = sizes[meshIndex] ;
        sizes[meshIndex] ++ ;
    }
}

void DoubleMeshField::clearFamilies() {
    lock = true ;
    for (uint32_t meshIndex = 0; meshIndex< meshes.size() ; meshIndex++) {
        if (options[meshIndex] == LAZY) {
            mappings[meshIndex].clear() ;
        }
    }
}

void DoubleMeshField::buildData() {
    lock = true ;
    uint32_t size = 1 ;
    data.clear() ;
    for (uint32_t i = 0; i < meshes.size() ; i++) {
        size *= sizes[i] ;
    }
    if (size>0) {
        data.resize(size,0.); 
    }
    else throw InputConsistency(7,LOG_INP_CONS_E("mapping has not be done on every mesh")) ;
}


void DoubleMeshField::setDouble(FieldIterator & it, double d) {
    if (lock == true)
        throw runtime_error("DoubleMeshField::setDouble(FieldIterator & it, double d) : DoubleMeshField is locked") ;
    int idx = 0;
    for (uint32_t meshIndex = 0; meshIndex< meshes.size() ; meshIndex++) {
        idx = idx*sizes[meshIndex];
        idx += mappings[meshIndex][it.get(meshIndex,0)] ;
    }
    data[idx] = d ;
}
double DoubleMeshField::getDouble(FieldIterator & it) {
    return 0 ;
}
