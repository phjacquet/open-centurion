/*
 * File:   FieldIterator.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 16 juin 2011, 01:34
 */

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cstdarg>
#include "FieldIterator.h"
#include "DoubleMeshField.h"

using namespace std;

FieldIterator::FieldIterator(DoubleMeshField * l_dmf) {
    dmf = l_dmf;
    locData.resize(dmf->numberOfMeshes());
    wideIterator = false;
}

FieldIterator::FieldIterator(const FieldIterator& orig) {
    locData = orig.locData;
    dmf = orig.dmf;
    wideIterator = orig.wideIterator;
    path = orig.path;
}

FieldIterator::~FieldIterator() {
}

FieldIterator & FieldIterator::operator()(const string & expression) {
    stringstream ss_expression(expression);
    string hl_extract;
    unsigned meshIdx = 0;
    while (!ss_expression.eof()) {
        std::getline(ss_expression, hl_extract, ';');
        if (hl_extract.find(",") != string::npos) {
            stringstream ss_hl_extract(hl_extract);
            string ll_extract;
            locData[meshIdx].clear();
            while (!ss_hl_extract.eof()) {
                std::getline(ss_hl_extract, ll_extract, ',');
                locData[meshIdx].push_back(ll_extract);
            }
        } else {
            if (meshIdx >= locData.size()) {
                throw runtime_error("FieldIterator::operator()( const string & expression ) : expression is too long");
            }
            locData[meshIdx].clear();
            if (hl_extract == ":") {
                locData[meshIdx] = dmf->getMesh(meshIdx)->getListOfRegionsNames();
            } else {
                locData[meshIdx].push_back(hl_extract);
            }
        }
        meshIdx++;
    }
    computePath();
    return *this;
}

unsigned FieldIterator::size(unsigned meshIndex) {
    return locData[meshIndex].size();
}

string& FieldIterator::get(unsigned meshIndex, unsigned regionIndex) {
    return locData[meshIndex][regionIndex];
}

bool FieldIterator::isWideIterator() {
    return wideIterator;
}

void FieldIterator::computePath() {
    path.clear();
    vector<unsigned> multiplicity;
    multiplicity.push_back(1);
    if (locData.size() == 0) throw runtime_error("FieldIterator::computePath() : Iterator is empty");
    for (unsigned i = 0; i < locData.size(); i++)
        multiplicity.push_back(locData[i].size() * multiplicity.back());

    unsigned multiplicityBack = multiplicity.back() ;
    unsigned locDataSize = locData.size() ;
    path.resize(multiplicityBack,vector<string*>(locDataSize));

    unsigned i,k,j,l,pathIndex,multiplicity_i,repet ;
    for ( i = 0; i < locDataSize; i++) {
        pathIndex = 0;
        multiplicity_i = multiplicity[i] ;
        for ( k = 0; k < multiplicity_i; k++) {
            for ( j = 0; j < locData[i].size(); j++) {
                repet = multiplicityBack / multiplicity[i+1] ;
                for ( l = 0; l < repet; l++) {
                    path[pathIndex][i]=&locData[i][j];
                    pathIndex++;
                }
            }
        }
    }
}

vector< vector< string *> > & FieldIterator::getPath() {
    return path;
}

string FieldIterator::toString() {
    stringstream ss;
    ss << "FieldIterator path : { ";
    if (path.size() > 1)
        for (unsigned i = 0; i < path.size() - 1; i++) {
            ss << "[";
            for (unsigned j = 0; j < path[i].size() - 1; j++) {
                ss << path[i][j] << ";";
            }
            if (path[i].size() > 0) ss << path[i].back();
            ss << "],";
        }
    if (path.size() > 0) {
        ss << "[";
        for (unsigned j = 0; j < path.back().size() - 1; j++) {
            ss << path.back()[j] << ";";
        }
        if (path.back().size() > 0) ss << path.back().back();
        ss << "]";
    }
    ss << " }";
    return ss.str();
}
