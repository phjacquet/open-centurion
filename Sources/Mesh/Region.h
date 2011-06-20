/* 
 * File:   Region.h
 * Author: Sab_n_Phil
 *
 * Created on 13 juin 2011, 01:46
 */

#ifndef REGION_H
#define	REGION_H
#include <string>

class Region {
public:
    Region();
    Region(const Region& orig);
    virtual ~Region();
    virtual std::string toString() = 0 ;
    std::string & getName() ;
private:
    std::string name ;
};

#endif	/* REGION_H */

