/*
 * File:   InputConsistency.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 13 juin 2011, 03:22
 */

#ifndef INPUTCONSISTENCY_H
#define	INPUTCONSISTENCY_H

#include <exception>
#include <string>

#define LOG_INP_CONS_E(l) ( ("in "+string(__FILE__)+string(" :\n")+string(l)).c_str() )

class InputConsistency : public std::exception {
public:
    InputConsistency(int l_id = 0, const std::string& l_d = "", int l_lvl = 0) throw ();
    virtual const char* what() const throw () ;
    int getLevel() const throw () ;
    virtual ~InputConsistency() throw ();

private:
    int id; // NumÃƒÂ©ro de l'erreur.
    std::string description; // Description de l'erreur.
    int level; // Niveau de l'erreur.
	std::string whatMsg ;
};

#endif	/* INPUTCONSISTENCY_H */

