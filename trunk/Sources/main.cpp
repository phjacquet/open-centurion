/* 
 * File:   main.cpp
 * Author: Phil
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
#include "Exception/InputConsistency.h"

using namespace std;

int main(int argc, char** argv) {
    try {
        // Beginning of Data File
        
        double spatialNodes[] = {0., 10., 20., 30.};
        Mesh * spatialMesh = new CartesianOneDimMesh(spatialNodes, 4);
        cout << spatialMesh->toString() << endl;
        
        // End of Data File
    }    catch (const exception & e) {
        cout << e.what() << endl;
    }
    return 0;
}

