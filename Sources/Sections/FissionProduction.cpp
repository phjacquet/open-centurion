/*
 * File:   FissionProduction.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:54
 */

#include <vector>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include "FissionProduction.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/Mesh.h"
#include "Field/DoubleMeshField.h"
#include "SetOfXS.h"
#include "Exceptions/InputConsistency.h"


using namespace std ;

FissionProduction::FissionProduction(EnergyMesh * energyMesh, Mesh * spatialMesh) {
    vector< pair_MeshOption_t > meshes ;
    meshes.push_back( pair_MeshOption_t(energyMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption_t(energyMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption_t(spatialMesh,DoubleMeshField::LAZY) ) ;
    data = new DoubleMeshField(meshes) ;
    xsType = SetOfXS::FISSION_PRODUCTION ;
}

FissionProduction::FissionProduction(const FissionProduction& orig) {
    throw runtime_error("FissionProduction::FissionProduction(const FissionProduction& orig) : Unimplemented method") ;
}

FissionProduction::~FissionProduction() {
    delete data ;
}

void FissionProduction::collapseSpatialRegions(const string & name, const std::vector< std::string > & regionsName) {
    data->buildFamily(2,regionsName,name) ;
}

DoubleMeshField * FissionProduction::getData() {
    return data ;
}

void FissionProduction::buildData() {
    data->buildData();
}

void FissionProduction::calculateMacro(const string & mediumName,
                                       map< SetOfXS::E_XS, vector<CrossSection*> > mmicroXS,
                                       const vector< double > & concentrations) {
    if (mmicroXS.find(SetOfXS::NUFISSION)==mmicroXS.end() || mmicroXS.find(SetOfXS::FISSION_DISTRIBUTION)==mmicroXS.end())
        throw InputConsistency(21, LOG_INP_CONS_E("FissionProduction::calculateMacro(...) : mmicroXS does not contain required micros XS"));

    vector<CrossSection*> & nufiss = mmicroXS[SetOfXS::NUFISSION] ;
    vector<CrossSection*> & fissdist = mmicroXS[SetOfXS::FISSION_DISTRIBUTION] ;

    FieldIterator itM = data->getIterator() ;
    data->setDouble( itM(":;:;"+mediumName) , 0.0 );
    vector<double*> dM = data->getDoubles(itM(":;:;"+mediumName)) ;
    for (unsigned n=0; n<concentrations.size(); n++) {
        FieldIterator itm = nufiss[n]->getData()->getIterator() ;
        vector<double *> dm_nufiss = nufiss[n]->getData()->getDoubles(itm(":;-")) ;
        vector<double *> dm_fissdist = fissdist[n]->getData()->getDoubles(itm(":;-")) ;
        if (dM.size()!=dm_nufiss.size()*dm_fissdist.size() )
            throw InputConsistency(18, LOG_INP_CONS_E( "FissionProduction::calculateMacro(...) : medium "+
                                                       mediumName+
                                                       " is not compatible with one of micro cross sections"));
        unsigned NG = data->getMesh(0)->size() ;
        for (unsigned g=0; g<NG; g++) {
            for (unsigned gp=0; gp<NG; gp++) {
                //cout<<*dm_fissdist[g]<<" * "<<*dm_nufiss[gp]<<" * "<<concentrations[n]<<endl;
                *dM[g*NG+gp]+=(*dm_nufiss[gp])*(*dm_fissdist[g])*concentrations[n] ;
            }
        }
    }
}

string FissionProduction::toString(const string & option) {
    stringstream ss;
    ss<<"<FissionProduction>"<<endl;
    ss<<data->toString(option)<<endl;
    ss<<"</FissionProduction>"<<endl;
    return ss.str() ;
}
