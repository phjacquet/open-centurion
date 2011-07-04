/* 
 * File:   FieldIterator.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 16 juin 2011, 01:34
 */
#include <stdexcept>
#include "FieldIterator.h"
using namespace std ;

FieldIterator::FieldIterator(string s0, string s1) {
    locData.resize(2) ;
    locData[0].push_back(s0) ;
    locData[1].push_back(s1) ;
}

FieldIterator::FieldIterator(const FieldIterator& orig) {
    throw runtime_error("FieldIterator::FieldIterator(const FieldIterator& orig) : Unimplemented method") ;
}

FieldIterator::~FieldIterator() {
}

FieldIterator FieldIterator::create(string s0, string s1) {
    return FieldIterator(s0,s1);
}

string FieldIterator::get(int meshIndex, int regionIndex) {
    return locData[meshIndex][regionIndex] ;
}
