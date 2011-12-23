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

class Mesh ;

class DoubleMeshField {
public:
    enum OptionMeshField{
        FULL,
        LAZY
    };
    DoubleMeshField(std::vector< std::pair< Mesh*, OptionMeshField> >& l_meshes);
    DoubleMeshField(const DoubleMeshField& orig);
    virtual ~DoubleMeshField();
    unsigned numberOfMeshes() ;
    Mesh * getMesh(unsigned meshIndex) ;
    FieldIterator iterator() ;
    void buildFamily(unsigned meshIndex, std::vector<std::string> regionsName, std::string familyName) ;
    void buildData() ;
    void clearFamilies() ;
    void setDouble(FieldIterator & it, double d);
    double& getDouble(FieldIterator & it);
    std::vector<double *> getDoubles(FieldIterator & it) ;
    DoubleMeshField & focus(FieldIterator & it);
    DoubleMeshField & clearFocus(FieldIterator & it);
    FieldIterator getIterator() ;

    DoubleMeshField operator=(const DoubleMeshField& orig);

    virtual std::string toString(std::string option="")  ;

private:
    void buildFullMeshesMapping() ;
    unsigned getDataIndex(std::vector<std::string*> & coord) ;
    void getDataIndexes(FieldIterator & it, std::vector<unsigned> & indexes) ;

    std::vector<Mesh *> meshes ;
    std::vector<OptionMeshField> options ;
    std::vector<unsigned> sizes ;
    std::vector< std::map<std::string,int> > mappings ;
    std::map< std::string, std::pair< unsigned, std::vector < std::string > > > regionsUnions ;
    std::vector<double> data ;
    bool lock ;
};

typedef  std::pair< Mesh*, DoubleMeshField::OptionMeshField> pair_MeshOption_t ;

#endif	/* DOUBLEMESHFIELD_H */

