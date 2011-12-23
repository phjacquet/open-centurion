/*
 * File:   DefaultCrossSection.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:17
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "DefaultTotalCrossSection.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/Mesh.h"
#include "Field/DoubleMeshField.h"
#include "SetOfXS.h"
#include "Exceptions/InputConsistency.h"

using namespace std;

DefaultTotalCrossSection::DefaultTotalCrossSection(EnergyMesh * energyMesh, Mesh * spatialMesh) {
    vector< pair_MeshOption_t > meshes;
    meshes.push_back(pair_MeshOption_t(energyMesh, DoubleMeshField::FULL));
    meshes.push_back(pair_MeshOption_t(spatialMesh, DoubleMeshField::LAZY));
    data = new DoubleMeshField(meshes);
    xsType = SetOfXS::TOTAL ;
}

DefaultTotalCrossSection::DefaultTotalCrossSection(const DefaultTotalCrossSection& orig) {
    throw runtime_error("DefaultTotalCrossSection::DefaultTotalCrossSection(const DefaultTotalCrossSection& orig) : Unimplemented method");
}

DefaultTotalCrossSection::~DefaultTotalCrossSection() {
    delete data;
}

void DefaultTotalCrossSection::collapseSpatialRegions(const string & name,
                                                      const std::vector< std::string > & regionsName) {
    data->buildFamily(1, regionsName, name);
}

DoubleMeshField * DefaultTotalCrossSection::getData() {
    return data ;
}

void DefaultTotalCrossSection::buildData() {
    data->buildData();
}

void DefaultTotalCrossSection::calculateMacro(const string & mediumName,
                                             map< SetOfXS::E_XS, vector<CrossSection*> > mmicroXS,
                                              const vector< double > & concentrations) {
    if (mmicroXS.find(SetOfXS::TOTAL)==mmicroXS.end())
        throw InputConsistency(20, LOG_INP_CONS_E("DefaultTotalCrossSection::calculateMacro(...) : mmicroXS does not contain required micros XS"));
    vector<CrossSection*> & microXS = mmicroXS[SetOfXS::TOTAL] ;
    FieldIterator it = data->getIterator() ;
    data->setDouble( it(":;"+mediumName) , 0.0 );
    vector<double*> dM = data->getDoubles(it(":;"+mediumName)) ;
    for (unsigned n=0; n<microXS.size(); n++) {
        vector<double *> dm = microXS[n]->getData()->getDoubles(it(":;-")) ;
        if (dM.size()!=dm.size())
            throw InputConsistency(14, LOG_INP_CONS_E("DefaultTotalCrossSection::calculateMacro(...) : medium "+
                                                      mediumName+
                                                      " is not compatible with one of micro cross sections"));
        for (unsigned g=0; g<data->getMesh(0)->size(); g++) {
            *dM[g]+=(*dm[g])*concentrations[n] ;
        }
    }
}

string DefaultTotalCrossSection::toString(const string & option) {
    stringstream ss;
    ss<<"<DefaultTotalCrossSection>"<<endl;
    ss<<data->toString(option)<<endl;
    ss<<"</DefaultTotalCrossSection>"<<endl;
    return ss.str() ;
}
