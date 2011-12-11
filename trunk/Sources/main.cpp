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
#include "Field\DoubleMeshField.h"

using namespace std;

void testBuildDMF() {
		double energyBounds[1969];
		for (unsigned i = 0; i<1969; i++) energyBounds[i]=1968-i ;
		double spatialNodes[] = {0., 1., 2., 3., 4., 5., 6., 7., 8., 9., 10.};

		EnergyMesh energyMesh(energyBounds, 1969) ;
		CartesianOneDimMesh spatialMesh(spatialNodes, 11) ;

		vector< pair_MeshOption > meshes;
		meshes.push_back(pair_MeshOption(&energyMesh,  DoubleMeshField::FULL));
		meshes.push_back(pair_MeshOption(&energyMesh,  DoubleMeshField::FULL));
		meshes.push_back(pair_MeshOption(&spatialMesh, DoubleMeshField::FULL));

		DoubleMeshField dmf(meshes);
		dmf.buildData() ;
		FieldIterator i = dmf.getIterator() ;
		//i(":;:;1") ;
		//cout<<i("0;0,1,2,3;:").toString()<<endl;
}

int main(int argc, char** argv) {
    try {
        // Beginning of Data File

		testBuildDMF() ;

        double spatialNodes[] = {0., 1., 2., 3., 4., 5., 6., 7., 8., 9., 10.};
        Mesh * spatialMesh = new CartesianOneDimMesh(spatialNodes, 11);

		Library *lib = new Library("C:\\Users\\Sab_n_Phil\\Documents\\CBProjects\\Centurion_v0\\Libraries\\Light\\LibraryRoot.xml");
        Geometry geometry(spatialMesh, lib);

        cout << spatialMesh->toString() << endl;
        cout << lib->getEnergyMesh()->toString()<<endl;

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
        nucleiConcentration.push_back( pair<string,double>("016",  2.2) ) ;
        geometry.fill("combustible",regionsName,nucleiConcentration);

        regionsName.clear(); nucleiConcentration.clear() ;
        regionsName.push_back("5");
        nucleiConcentration.push_back( pair<string,double>("Fe56", 1.0) ) ;
        geometry.fill("gaine",regionsName,nucleiConcentration);

        regionsName.clear(); nucleiConcentration.clear() ;
        regionsName.push_back("6");
        regionsName.push_back("7");
        regionsName.push_back("8");
        regionsName.push_back("9");
        nucleiConcentration.push_back( pair<string,double>("H20", 1.0) ) ;
        geometry.fill("modérateur",regionsName,nucleiConcentration);



        delete spatialMesh;
        delete lib ;
		cin>>argc ;

        // End of Data File
    }    catch (const exception & e) {
        cout << e.what() << endl;
    }
    return 0;
}

