/* 
 * File:   Library.h
 * Author: Sab_n_Phil
 *
 * Created on 12 juin 2011, 22:34
 */

#ifndef LIBRARY_H
#define	LIBRARY_H
#include <string>
#include <map>
#include "Sections/ProblemCrossSections.h"

class Library {
public:
    Library(const std::string& fileName);
    virtual ~Library();
private:
    Library(const Library& orig);
    Library& operator=(const Library& );
    
    std::map<std::string, ProblemCrossSections> problemMicroXS ;
};

#endif	/* LIBRARY_H */

