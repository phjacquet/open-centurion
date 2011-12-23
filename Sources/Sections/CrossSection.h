/*
 * File:   CrossSection.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 juin 2011, 23:14
 */

#ifndef CROSSSECTION_H
#define	CROSSSECTION_H

#include <map>
#include <vector>
#include <string>
#include "SetOfXS.h"

class DoubleMeshField ;

class CrossSection {
public:
    CrossSection();
    CrossSection(const CrossSection& orig);
    virtual ~CrossSection();
    virtual SetOfXS::E_XS getType()  ;
    virtual void collapseSpatialRegions(const std::string & name, const std::vector< std::string > & regionsName) = 0 ;
    virtual void calculateMacro(const std::string & mediumName, std::map< SetOfXS::E_XS, std::vector<CrossSection*> >  microXS, const std::vector< double > & concentrations ) = 0 ;
    virtual DoubleMeshField * getData() = 0;
    virtual void buildData() =0;
    virtual std::string toString(const std::string & option="")  ;
protected:
    SetOfXS::E_XS xsType ;
};

#endif	/* CROSSSECTION_H */

