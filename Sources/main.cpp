/* 
 * File:   main.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 1 juin 2011, 21:23
 */

#include <cstdlib>
#include <iostream>
#include "Mesh/CartesianOneDimMesh.h"
#include "Mesh/EnergyMesh.h"
#include "Material/Library.h"
#include "Material/Geometry.h"
#include "Solver/PijSolver.h"
#include "Exceptions/InputConsistency.h"

using namespace std;

int main(int argc, char** argv) { 
    try {
        // Beginning of Data File
        
        double spatialNodes[] = {0., 1., 2., 3., 4., 5., 6., 7., 8., 9., 10.};
        Mesh * spatialMesh = new CartesianOneDimMesh(spatialNodes, 11);
        Library *lib = new Library("none");
        Geometry geometry(spatialMesh, lib);
        vector<string> regionsName;
        vector< pair< string, double > > nucleiConcentration ;
        
        regionsName.clear(); nucleiConcentration.clear() ;
        regionsName.push_back("0");
        regionsName.push_back("1");
        regionsName.push_back("2");
        regionsName.push_back("3");
        regionsName.push_back("4");
        nucleiConcentration.push_back( pair<string,double>("U235", 0.1) ) ;
        nucleiConcentration.push_back( pair<string,double>("U238", 1.0) ) ;
        geometry.fill(regionsName,nucleiConcentration);
        
        regionsName.clear(); nucleiConcentration.clear() ;
        regionsName.push_back("5");
        nucleiConcentration.push_back( pair<string,double>("Fe56", 1.0) ) ;
        geometry.fill(regionsName,nucleiConcentration);
        
        regionsName.clear(); nucleiConcentration.clear() ;
        regionsName.push_back("6");
        regionsName.push_back("7");
        regionsName.push_back("8");
        regionsName.push_back("9");
        nucleiConcentration.push_back( pair<string,double>("H20", 1.0) ) ;
        geometry.fill(regionsName,nucleiConcentration);
        
        cout << spatialMesh->toString() << endl;
        cout << lib->getEnergyMesh()->toString()<<endl;
        
        delete spatialMesh;
        delete lib ;
        // End of Data File
    }    catch (const exception & e) {
        cout << e.what() << endl;
    }
    return 0;
}

