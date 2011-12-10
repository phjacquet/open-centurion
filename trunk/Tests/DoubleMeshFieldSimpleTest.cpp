/* 
 * File:   DoubleMeshFieldTest.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 21 juin 2011, 23:16:45
 */

#include <stdlib.h>
#include <iostream>
#include <sstream>

#include <stdint.h>
#include <stdexcept>
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
    
    delete mesh1 ;
    delete mesh2 ;
}

void ioTest() {
    double gb[] = {18.0E6, 1E0, 1.0E-11};
    double nodes[] = {0., 5., 10., 20., 21.}; 
    Mesh * mesh1 = new EnergyMesh(gb, 3);
    Mesh * mesh2 = new CartesianOneDimMesh(nodes, 5);

    vector< pair< Mesh*, DoubleMeshField::OptionMeshField> > meshes ;
    meshes.push_back(pair< Mesh*, DoubleMeshField::OptionMeshField>(mesh1, DoubleMeshField::FULL)) ;
    meshes.push_back(pair< Mesh*, DoubleMeshField::OptionMeshField>(mesh2, DoubleMeshField::LAZY)) ;
    DoubleMeshField dmf(meshes);
    vector<string> reg ;
    try {
        reg.clear() ;
        reg.push_back("0") ;
        reg.push_back("1") ;
        dmf.buildFamily(1, reg, "A") ;
        reg.clear() ;
        reg.push_back("2") ;
        reg.push_back("3") ;
        dmf.buildFamily(1, reg, "B") ;

        FieldIterator fit = dmf.getIterator();

        fit("0,1,2;0") ;
        cout<<fit.toString()<<endl ;
        
        cout << "subtest 1" << endl;
        dmf.buildData() ;
        cout << "passed" << endl;
        
        cout << "subtest 2" << endl;
        double expectedResult1[2][4]={ {0,0,0,0},{0,0,0,0} } ;
        
        for (unsigned i=0; i < 2; i++)
            for (unsigned j=0; j < 4; j++) {
                stringstream ss ;
                ss<<i<<";"<<j ;cout<<ss.str()<<" - >"<<fit(ss.str()).toString()<<endl ;
                if (dmf.getDouble(fit(ss.str())) != expectedResult1[i][j])
                    throw runtime_error("Initialization Exception") ;
            }
        cout << "passed" << endl;
        
        cout << "subtest 3" << endl;
        double expectedResult2[2][4]={ {1.,1.,0,0},{0,0,0,0} } ;
        dmf.setDouble(fit("0;0"),1.) ;
        for (unsigned i=0; i < 2; i++)
            for (unsigned j=0; j < 4; j++) {
                stringstream ss ;
                ss<<i<<";"<<j ;
                if (dmf.getDouble(fit(ss.str())) != expectedResult2[i][j])
                    throw runtime_error("set value Exception") ;
            }
        cout << "passed" << endl;
        
        cout << "subtest 4" << endl;
        double expectedResult3[2][4]={ {1.,1.,0,0},{5.,5.,0,0} } ;
        dmf.setDouble(fit("1;A"),5.) ;
        for (unsigned i=0; i < 2; i++)
            for (unsigned j=0; j < 4; j++) {
                stringstream ss ;
                ss<<i<<";"<<j ;
                if (dmf.getDouble(fit(ss.str())) != expectedResult3[i][j])
                    throw runtime_error("set value Exception") ;
            }
        cout << "passed" << endl;
        
        cout << "subtest 5" << endl;
        double expectedResult4[2][4]={ {3.,3.,2,2},{5.,5.,0,0} } ;
        dmf.setDouble(fit("0;B"),2.) ;
        dmf.setDouble(fit("0;1"),3.) ;
        for (unsigned i=0; i < 2; i++)
            for (unsigned j=0; j < 4; j++) {
                stringstream ss ;
                ss<<i<<";"<<j ;
                if (dmf.getDouble(fit(ss.str())) != expectedResult4[i][j])
                    throw runtime_error("double set value Exception") ;
            }
        cout << "passed" << endl;
        
        cout << "subtest 6a" << endl;
        double expectedResult6a[2][4]={ {0,0,0,0}, {0,0,0,0} } ;
        dmf.setDouble(fit(":;:"),0.) ;
        for (unsigned i=0; i < 2; i++)
            for (unsigned j=0; j < 4; j++) {
                stringstream ss ;
                ss<<i<<";"<<j ;
                cout<<ss.str()<<": "<<dmf.getDouble(fit(ss.str())) << endl;
                if (dmf.getDouble(fit(ss.str())) != expectedResult6a[i][j])
                    throw runtime_error("double set value Exception") ;
            }
        cout << "passed" << endl;
        
        cout << "subtest 6b" << endl;
        double expectedResult6b[2][4]={ {5,5,1,1}, {5,5,1,1} } ;
        dmf.setDouble(fit(":;A"),5.) ;
        dmf.setDouble(fit(":;B"),1.) ;
        for (unsigned i=0; i < 2; i++)
            for (unsigned j=0; j < 4; j++) {
                stringstream ss ;
                ss<<i<<";"<<j ;
                cout<<ss.str()<<": "<<dmf.getDouble(fit(ss.str())) << endl;
                if (dmf.getDouble(fit(ss.str())) != expectedResult6b[i][j])
                    throw runtime_error("double set value Exception") ;
            }
        cout << "passed" << endl;
        
        cout << "subtest 6c" << endl;
        double expectedResult6c[2][4]={ {0,0,0,0}, {5,5,1,1} } ;
        dmf.setDouble(fit("0;:"),0.) ;
        for (unsigned i=0; i < 2; i++)
            for (unsigned j=0; j < 4; j++) {
                stringstream ss ;
                ss<<i<<";"<<j ;
                cout<<ss.str()<<": "<<dmf.getDouble(fit(ss.str())) << endl;
                if (dmf.getDouble(fit(ss.str())) != expectedResult6c[i][j])
                    throw runtime_error("double set value Exception") ;
            }
        cout << "passed" << endl;
        
        cout << "subtest 7" << endl;
        double expectedResult7[2][4]={ {0,0,0,0},{1,1,1,1} } ;
        dmf.clearFamilies() ;
        reg.clear() ;
        reg.push_back("0") ;
        reg.push_back("1") ;
        reg.push_back("2") ;
        reg.push_back("3") ;
        dmf.buildFamily(1, reg, "ALL") ;
        dmf.buildData() ;
        dmf.setDouble(fit("1;ALL"),1.) ;
        for (unsigned i=0; i < 2; i++)
            for (unsigned j=0; j < 4; j++) {
                stringstream ss ;
                ss<<i<<";"<<j ;
                if (dmf.getDouble(fit(ss.str())) != expectedResult7[i][j])
                    throw runtime_error("clearFamilies Exception") ;
            }
        cout << "passed" << endl;
  
    }    catch (const exception & e) {
        cout << e.what() << endl;
        cout << "%TEST_FAILED% time=0 testname=ioTest (DoubleMeshFieldTest) message=Unexpected Exception" << endl;
    } 
    
    delete mesh1 ;
    delete mesh2 ;
}

int main(int argc, char** argv) {
    try {
        std::cout << "%SUITE_STARTING% DoubleMeshFieldTest" << std::endl;
        std::cout << "%SUITE_STARTED%" << std::endl;

        std::cout << "%TEST_STARTED% constructorTest (DoubleMeshFieldTest)" << std::endl;
        constructorTest();
        std::cout << "%TEST_FINISHED% time=0 constructorTest (DoubleMeshFieldTest)" << std::endl;

        std::cout << "%TEST_STARTED% ioTest (DoubleMeshFieldTest)" << std::endl;
        ioTest();
        std::cout << "%TEST_FINISHED% time=0 ioTest (DoubleMeshFieldTest)" << std::endl;


        std::cout << "%SUITE_FINISHED% time=0" << std::endl;
		cin>>argc ;
    }    catch (const exception & e) {
        cout << e.what() << endl;
    }
    return (EXIT_SUCCESS);
}

