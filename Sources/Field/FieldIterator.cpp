/* 
 * File:   FieldIterator.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 16 juin 2011, 01:34
 */
#include <stdexcept>
#include <sstream>
#include "FieldIterator.h"
#include "DoubleMeshField.h"
#include <cstdarg>

#include <iostream>

using namespace std ;

FieldIterator::FieldIterator(DoubleMeshField * l_dmf) {
    dmf=l_dmf ;
    locData.resize(dmf->numberOfMeshes()) ;
}

FieldIterator::FieldIterator(const FieldIterator& orig) {
    locData = orig.locData ;
    dmf = orig.dmf ;
}

FieldIterator::~FieldIterator() {
}

FieldIterator & FieldIterator::operator()( const string & expression ) {
    const int bufferMaxSize = expression.size() ;
    stringstream ss_expression(expression) ;
    string hl_extract ;
    int meshIdx = 0 ;
    while (!ss_expression.eof())  {
        char hl_buffer[bufferMaxSize] ;
        ss_expression.getline(hl_buffer, bufferMaxSize, ';') ;
        hl_extract = hl_buffer ;
        if (hl_extract.find(",") != string::npos) {
            stringstream ss_hl_extract(hl_extract) ;
            throw runtime_error("FieldIterator::operator()( const string & expression ) : expression with multiple regions are not suported yet") ;
        }
        else {
            locData[meshIdx].clear() ;
            locData[meshIdx].push_back(hl_extract);
        }
        meshIdx ++ ;
    }      
    return *this ;
}


string&  FieldIterator::get(int meshIndex, int regionIndex) {
    return locData[meshIndex][regionIndex] ;
}
