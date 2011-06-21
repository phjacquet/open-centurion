/* 
 * File:   DoubleMeshField.h
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 15 juin 2011, 22:33
 */

#ifndef DOUBLEMESHFIELD_H
#define	DOUBLEMESHFIELD_H

#include <vector>
#include <map>
#include "FieldIterator.h"
#include "Mesh/Mesh.h"

class DoubleMeshField {
public:
    enum OptionMeshField{
        FULL,
        LAZY
    };
    DoubleMeshField(std::vector< std::pair< Mesh*, OptionMeshField> >& l_meshes);
    DoubleMeshField(const DoubleMeshField& orig);
    virtual ~DoubleMeshField();
    FieldIterator iterator() ;
    void buildFamily(Mesh* mesh, std::vector<std::string> regionsName, std::string familyName) ;
    void setDouble(FieldIterator & it, double d);
    double & getDouble(FieldIterator & it);
    DoubleMeshField & focus(FieldIterator & it);
    DoubleMeshField & clearFocus(FieldIterator & it);
    
    DoubleMeshField operator=(const DoubleMeshField& orig);
    
private:
    std::vector<Mesh *> meshes ;
    std::vector<OptionMeshField> options ;
    std::vector< std::map<std::string,int> > mappings ;
    std::vector<double> data ;
};

#endif	/* DOUBLEMESHFIELD_H */

