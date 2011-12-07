/* 
 * File:   CrossSection.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 juin 2011, 23:14
 */

#ifndef CROSSSECTION_H
#define	CROSSSECTION_H

#include <vector>
#include <string>

class CrossSection {
public:
    CrossSection();
    CrossSection(const CrossSection& orig);
    virtual ~CrossSection();
    virtual void collapseSpatialRegions(const std::string & name, const std::vector< std::string > & regionsName) = 0 ;
    
    virtual void calculateMacro(const std::string & mediumName, std::vector<CrossSection*> microXS, const std::vector< std::pair< std::string,double > > & medium ) ;
    

private:
};

#endif	/* CROSSSECTION_H */

