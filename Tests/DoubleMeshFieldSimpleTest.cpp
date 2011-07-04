/* 
 * File:   DoubleMeshFieldTest.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 21 juin 2011, 23:16:45
 */

#include <stdlib.h>
#include <iostream>

#include <stdint.h>
#include "Field/DoubleMeshField.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/CartesianOneDimMesh.h"
using namespace std;
/*
 * Simple C++ Test Suite
 */

void constructorTest() {
    double gb[] = {18.0E6, 1E0, 1.0E-11};
    double nodes[] = {0., 5., 10., 20.}; 
    Mesh * mesh1 = new EnergyMesh(gb, 3);
    Mesh * mesh2 = new CartesianOneDimMesh(nodes, 4);
    cout << mesh1->toString() << endl;
    cout << mesh2->toString() << endl;
    
    vector< pair< Mesh*, DoubleMeshField::OptionMeshField> > meshes ;
    meshes.push_back(pair< Mesh*, DoubleMeshField::OptionMeshField>(mesh1, DoubleMeshField::FULL)) ;
    meshes.push_back(pair< Mesh*, DoubleMeshField::OptionMeshField>(mesh2, DoubleMeshField::LAZY)) ;
    std::cout << "DoubleMeshFieldTest constructorTest" << std::endl;
    DoubleMeshField dmf(meshes);
    std::cout << "DoubleMeshField built" << std::endl;
    vector<string> reg ;
    try {
        cout << "subtest 1" << endl;
        reg.clear() ;
        reg.push_back("0") ;
        reg.push_back("1") ;
        dmf.buildFamily(1, reg, "A") ;
        cout << "passed" << endl;
    }    catch (const exception & e) {
        cout << e.what() << endl;
        cout << "%TEST_FAILED% time=0 testname=constructorTest (DoubleMeshFieldTest) message=Unexpected Exception" << endl;
    }
    try {
        cout << "subtest 2" << endl;
        reg.clear() ;
        reg.push_back("0") ;
        reg.push_back("1") ;
        dmf.buildFamily(1, reg, "A") ;
        cout << "%TEST_FAILED% time=0 testname=constructorTest (DoubleMeshFieldTest) message=Unexpected Exception" << endl;
    }    catch (const exception & e) {
        cout << e.what() << endl;
        cout << "passed" << endl;
        }
    
    try {
        cout << "subtest 3" << endl;
        reg.clear() ;
        reg.push_back("2") ;
        dmf.buildFamily(1, reg, "A") ;
        cout << "%TEST_FAILED% time=0 testname=constructorTest (DoubleMeshFieldTest) message=Unexpected Exception" << endl;
    }    catch (const exception & e) {
        cout << e.what() << endl;
        cout << "passed" << endl;
        }

    try {
        cout << "subtest 4" << endl;
        reg.clear() ;
        reg.push_back("2") ;
        dmf.buildFamily(1, reg, "B") ;
        cout << "passed" << endl;
    }    catch (const exception & e) {
        cout << e.what() << endl;
        cout << "%TEST_FAILED% time=0 testname=constructorTest (DoubleMeshFieldTest) message=Unexpected Exception" << endl;
    }
}

void ioTest() {
    double gb[] = {18.0E6, 1E0, 1.0E-11};
    double nodes[] = {0., 5., 10., 20.}; 
    Mesh * mesh1 = new EnergyMesh(gb, 3);
    Mesh * mesh2 = new CartesianOneDimMesh(nodes, 4);

    vector< pair< Mesh*, DoubleMeshField::OptionMeshField> > meshes ;
    meshes.push_back(pair< Mesh*, DoubleMeshField::OptionMeshField>(mesh1, DoubleMeshField::FULL)) ;
    meshes.push_back(pair< Mesh*, DoubleMeshField::OptionMeshField>(mesh2, DoubleMeshField::LAZY)) ;
    DoubleMeshField dmf(meshes);
    vector<string> reg ;

    reg.clear() ;
    reg.push_back("0") ;
    reg.push_back("1") ;
    dmf.buildFamily(1, reg, "A") ;
    try {
        cout << "subtest 1" << endl;
        dmf.buildData() ;
        cout << "passed" << endl;
        cout << "subtest 2" << endl;
        cout<<dmf.getDouble(&FieldIterator::create("0","0"))<<endl;
        dmf.setDouble(&FieldIterator::create("0","0"),1.) ;
        cout<<dmf.getDouble(&FieldIterator::create("0","0"))<<endl;
        cout << "passed" << endl;
    }    catch (const exception & e) {
        cout << e.what() << endl;
        cout << "%TEST_FAILED% time=0 testname=ioTest (DoubleMeshFieldTest) message=Unexpected Exception" << endl;
    } 
}




int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% DoubleMeshFieldTest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% constructorTest (DoubleMeshFieldTest)" << std::endl;
    constructorTest();
    std::cout << "%TEST_STARTED% constructorTest (DoubleMeshFieldTest)" << std::endl;
    ioTest();
    std::cout << "%TEST_FINISHED% time=0 ioTest (DoubleMeshFieldTest)" << std::endl;

    
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

