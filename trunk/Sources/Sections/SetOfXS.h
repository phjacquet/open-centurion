/*
 * File:   SetOfXS.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 juin 2011, 23:06
 */

#ifndef SETOFXS_H
#define	SETOFXS_H
#include <map>

class CrossSection ;

class SetOfXS {
public:
    SetOfXS();
    SetOfXS(const SetOfXS& orig);
    SetOfXS operator=(const SetOfXS& orig);
    virtual ~SetOfXS();
    void newXS(CrossSection * xs) ;
    enum E_XS {
        NONE=0,
        TOTAL=1,
        SCATTERING=2,
        NUFISSION=3,
        FISSION_DISTRIBUTION=4,
        FISSION_PRODUCTION=5
    };

    CrossSection * getXS(E_XS xs) ;
    virtual std::string toString(const std::string & option="")  ;
private:

    std::map<E_XS, CrossSection *> xsMap;
};

#endif	/* SETOFXS_H */

