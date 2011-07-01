/* 
 * File:   FieldIterator.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 16 juin 2011, 01:34
 */

#include "FieldIterator.h"
using namespace std ;

FieldIterator::FieldIterator(string s0, string s1) {
    locData.resize(2) ;
    locData[0].pushback(s0)
}

FieldIterator::FieldIterator(const FieldIterator& orig) {
}

FieldIterator::~FieldIterator() {
}

string FieldIterator::string get(int meshIndex, int regionIndex) {
    return locData[meshIndex][regionIndex] ;
}
