/*
 * File:   FissionDistribution.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 22:54
 */

#include <vector>
#include <stdexcept>
#include <sstream>
#include "FissionDistribution.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/Mesh.h"
#include "Field/DoubleMeshField.h"
#include "SetOfXS.h"
#include "Exceptions/InputConsistency.h"


using namespace std ;

FissionDistribution::FissionDistribution(EnergyMesh * energyMesh, Mesh * spatialMesh) {
    vector< pair_MeshOption_t > meshes ;
    meshes.push_back( pair_MeshOption_t(energyMesh,DoubleMeshField::FULL) ) ;
    meshes.push_back( pair_MeshOption_t(spatialMesh,DoubleMeshField::LAZY) ) ;
    data = new DoubleMeshField(meshes) ;
    xsType = SetOfXS::FISSION_DISTRIBUTION ;
}

FissionDistribution::FissionDistribution(const FissionDistribution& orig) {
    throw runtime_error("FissionDistribution::FissionDistribution(const FissionDistribution& orig) : Unimplemented method") ;
}

FissionDistribution::~FissionDistribution() {
    delete data ;
}

void FissionDistribution::collapseSpatialRegions(const string & name, const std::vector< std::string > & regionsName) {
    data->buildFamily(1,regionsName,name) ;
}

DoubleMeshField * FissionDistribution::getData() {
    return data ;
}

void FissionDistribution::buildData() {
    data->buildData();
}

void FissionDistribution::calculateMacro(const string & mediumName,
                                             map< SetOfXS::E_XS, vector<CrossSection*> > mmicroXS,
                                              const vector< double > & concentrations) {
    if (mmicroXS.find(SetOfXS::FISSION_DISTRIBUTION)==mmicroXS.end())
        throw InputConsistency(19, LOG_INP_CONS_E("FissionDistribution::calculateMacro(...) : mmicroXS does not contain required micros XS"));
    vector<CrossSection*> & microXS = mmicroXS[SetOfXS::FISSION_DISTRIBUTION] ;
    FieldIterator it = data->getIterator() ;
    data->setDouble( it(":;"+mediumName) , 0.0 );
    vector<double*> dM = data->getDoubles(it(":;"+mediumName)) ;
    for (unsigned n=0; n<microXS.size(); n++) {
        vector<double *> dm = microXS[n]->getData()->getDoubles(it(":;-")) ;
        if (dM.size()!=dm.size())
            throw InputConsistency(16, LOG_INP_CONS_E("FissionDistribution::calculateMacro(...) : medium "+
                                                      mediumName+
                                                      " is not compatible with one of micro cross sections"));
        for (unsigned g=0; g<data->getMesh(0)->size(); g++) {
            //*dM[g]+=
        }
    }
}

string FissionDistribution::toString(const string & option) {
    stringstream ss;
    ss<<"<FissionDistribution>"<<endl;
    ss<<data->toString(option)<<endl;
    ss<<"</FissionDistribution>"<<endl;
    return ss.str() ;
}
