/* 
 * File:   DoubleMeshField.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 15 juin 2011, 22:33
 */

#include <stdexcept>
#include <iostream>
#include <sstream>
#include "DoubleMeshField.h"
#include "Mesh/Mesh.h"
#include "Exceptions/InputConsistency.h"

using namespace std;

DoubleMeshField::DoubleMeshField(vector< pair_MeshOption >& l_meshes) {
    lock = true;
    for (unsigned i = 0; i < l_meshes.size(); i++) {
        meshes.push_back(l_meshes[i].first);
        options.push_back(l_meshes[i].second);
    }
    mappings.resize(l_meshes.size());
    sizes.resize(l_meshes.size(), 0);
    buildFullMeshesMapping();
}

DoubleMeshField::DoubleMeshField(const DoubleMeshField& orig) {
    throw runtime_error("DoubleMeshField::DoubleMeshField(const DoubleMeshField& orig) : Unimplemented method");
}

DoubleMeshField DoubleMeshField::operator=(const DoubleMeshField& orig) {
    throw runtime_error("DoubleMeshField::operator=(const DoubleMeshField& orig) : Unimplemented method");
}

DoubleMeshField::~DoubleMeshField() {
}

unsigned DoubleMeshField::numberOfMeshes() {
    return meshes.size();
}
Mesh * DoubleMeshField::getMesh(unsigned meshIndex) {
    if (meshIndex>=meshes.size()) {
        throw runtime_error("DoubleMeshField::getMesh(unsigned meshIndex) : index out of bound");
    }
    return meshes[meshIndex] ;
}

FieldIterator DoubleMeshField::getIterator() {
    return FieldIterator(this);
}

void DoubleMeshField::buildFullMeshesMapping() {
    lock = true;
    for (unsigned meshIndex = 0; meshIndex < meshes.size(); meshIndex++) {
        if (options[meshIndex] == FULL) {
            mappings[meshIndex].clear();
            for (unsigned r = 0; r < meshes[meshIndex]->size(); r++) {
                string rname = meshes[meshIndex]->getRegion(r)->getName();
                mappings[meshIndex][rname] = r;
            }
            sizes[meshIndex] = mappings[meshIndex].size();
        }
    }
}

void DoubleMeshField::buildFamily(unsigned meshIndex, vector<string> regionsName, string familyName) {
    lock = true;
    if (meshIndex > meshes.size())
        throw InputConsistency(5, LOG_INP_CONS_E("mesh index is out of range"));
    if (options[meshIndex] != LAZY)
        throw InputConsistency(5, LOG_INP_CONS_E("FULL mesh does not support builFamily functionality"));
    if (mappings[meshIndex].find(familyName) != mappings[meshIndex].end())
        throw InputConsistency(6, LOG_INP_CONS_E(string("Region ") + familyName + " is already mapped"));
    for (unsigned r = 0; r < regionsName.size(); r++) {
        if (meshes[meshIndex]->getRegion(regionsName[r]) == 0)
            throw InputConsistency(6, LOG_INP_CONS_E(string("Region ") + regionsName[r] + " is a fictive region: operation forbidden"));
        if (mappings[meshIndex].find(regionsName[r]) != mappings[meshIndex].end())
            throw InputConsistency(6, LOG_INP_CONS_E(string("Region ") + regionsName[r] + " is already mapped"));
    }

    for (unsigned r = 0; r < regionsName.size(); r++) {
        string rname = regionsName[r];
        mappings[meshIndex][rname] = sizes[meshIndex];
    }
    mappings[meshIndex][familyName] = sizes[meshIndex];
    sizes[meshIndex]++;
}

void DoubleMeshField::clearFamilies() {
    lock = true;
    for (unsigned meshIndex = 0; meshIndex < meshes.size(); meshIndex++) {
        if (options[meshIndex] == LAZY) {
            mappings[meshIndex].clear();
            sizes[meshIndex] = 0;
        }
    }
}

void DoubleMeshField::buildData() {
    lock = true;
    unsigned size = 1;
    data.clear();
    for (unsigned i = 0; i < meshes.size(); i++) {
        size *= sizes[i];
    }
    if (size > 0) {
        data.resize(size, 0.);
    } else throw InputConsistency(7, LOG_INP_CONS_E("mapping has not be done on every mesh"));
    lock = false;
}

unsigned DoubleMeshField::getDataIndex(vector<string> & coord) {
    if (lock == true)
        throw runtime_error("DoubleMeshField::getDataIndex(vector<string> coord) : DoubleMeshField is locked");
    if (coord.size() != meshes.size()) {
        stringstream err ;
        err<<"DoubleMeshField::getDataIndex(vector<string> coord) : coord and DoubleMeshFiel are not size compatible : ";
        err<<coord.size()<<" vs "<<meshes.size();
        throw runtime_error(err.str());
    }
    int idx = 0;
    for (unsigned meshIndex = 0; meshIndex < meshes.size(); meshIndex++) {
        idx = idx * sizes[meshIndex];
        string & s_it = coord[meshIndex];
        if (mappings[meshIndex].find(s_it) == mappings[meshIndex].end()) {
            stringstream err;
            err << "DoubleMeshField::getDataIndex(vector<string> coord) : coord contains unknwon region id [ mesh=";
            err << meshIndex << ", cell=" << s_it << "]";
            throw runtime_error(err.str().c_str());
        }
        idx += mappings[meshIndex][s_it];
    }
    return idx;
}

void DoubleMeshField::getDataIndexes(FieldIterator & it, vector<unsigned> & indexes) {
    if (lock == true)
        throw runtime_error("DoubleMeshField::getDataIndexes(FieldIterator & it, vector<int> & indexes) : DoubleMeshField is locked");

    indexes.clear();
    vector< vector< string > > & path = it.getPath();
    for (unsigned i = 0; i < path.size(); i++) 
        indexes.push_back(getDataIndex(path[i])) ;
    
}

void DoubleMeshField::setDouble(FieldIterator & it, double d) {
    if (lock == true)
        throw runtime_error("DoubleMeshField::setDouble(FieldIterator * it, double d) : DoubleMeshField is locked");

    vector<unsigned> indexes;
    getDataIndexes(it, indexes);
    for (unsigned idx = 0; idx < indexes.size(); idx++) data[indexes[idx]] = d;
}

double DoubleMeshField::getDouble(FieldIterator & it) {
    if (lock == true)
        throw runtime_error("DoubleMeshField::getDouble(FieldIterator * it) : DoubleMeshField is locked");
    if (it.isWideIterator()) {
        throw runtime_error("DoubleMeshField::getDouble(FieldIterator * it) : wide Iterator has no meaning ");
    }

    vector<unsigned> indexes;
    getDataIndexes(it, indexes);
    return data[indexes[0]];
}
