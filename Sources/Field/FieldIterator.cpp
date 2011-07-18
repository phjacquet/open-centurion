/* 
 * File:   FieldIterator.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 16 juin 2011, 01:34
 */
#include <stdexcept>
#include "FieldIterator.h"
#include "DoubleMeshField.h"
#include <cstdarg>

using namespace std ;

FieldIterator::FieldIterator(DoubleMeshField * l_dmf) {
    dmf=l_dmf ;
}

FieldIterator::FieldIterator(const FieldIterator& orig) {
    locData = orig.locData ;
    dmf = orig.dmf ;
}

FieldIterator::~FieldIterator() {
}

FieldIterator & FieldIterator::operator()( vector< string>  reg) {
    for (int nArg=0; nArg < reg.size() ; nArg++)
        locData[nArg].push_back(reg[nArg]);
    return *this ;
}


string&  FieldIterator::get(int meshIndex, int regionIndex) {
    return locData[meshIndex][regionIndex] ;
}
