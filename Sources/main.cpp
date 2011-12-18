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

		vector< pair_MeshOption_t > meshes;
		meshes.push_back(pair_MeshOption_t(&energyMesh,  DoubleMeshField::FULL));
		meshes.push_back(pair_MeshOption_t(&energyMesh,  DoubleMeshField::FULL));
		meshes.push_back(pair_MeshOption_t(&spatialMesh, DoubleMeshField::FULL));

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

        string combustible1Regions[] = {"0","1","2","3","4"} ;
        string combustible2Regions[] = {"5"} ;
        string combustible3Regions[] = {"6","7","8","9"} ;

        vector< pair< string, double > > nucleiConcentration ;

        nucleiConcentration.clear() ;
        nucleiConcentration.push_back( pair<string,double>("U235", 0.5) ) ;
        nucleiConcentration.push_back( pair<string,double>("O16",  1.0) ) ;
        geometry.fill("combustible",combustible1Regions,5,nucleiConcentration);

        nucleiConcentration.clear() ;
        nucleiConcentration.push_back( pair<string,double>("O16", 0.1) ) ;
        geometry.fill("gaine",combustible2Regions,1,nucleiConcentration);

        nucleiConcentration.clear() ;
        nucleiConcentration.push_back( pair<string,double>("O16", 2.0) ) ;
        geometry.fill("modérateur",combustible3Regions,4,nucleiConcentration);

        geometry.buildMacros() ;

        cout<<geometry.toString()<<endl; ;

        delete spatialMesh;
        delete lib ;

        // End of Data File
    }    catch (const exception & e) {
        cout << e.what() << endl;
    }
    return 0;
}

