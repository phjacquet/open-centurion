/*
 * File:   Library.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 *
 * Created on 12 juin 2011, 22:34
 */

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
#include "Library.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/DiscreteMesh.h"
#include "Mesh/CartesianOneDimMesh.h"
#include "Exceptions/InputConsistency.h"
#include "Field/DoubleMeshField.h"
#include "Sections/DefaultTotalCrossSection.h"
#include "Sections/DefaultScatteringCrossSection.h"
#include "Sections/NuFissionCrossSection.h"
#include "Sections/FissionDistribution.h"

using namespace std;

Library::Library(const string& fileName) {
    logStream.open("Library.log") ;
    energyMesh = NULL ;
    discreteMesh = NULL ;
    spatialOneRegionMesh = NULL ;
    if (!loadLibraryRootFile(fileName))
        throw InputConsistency(8, LOG_INP_CONS_E("Library loading failed - step 1\n"+
                               fileName+
                               "\nFor detailed log report, check Library.Log"));

    if (!loadEnergyMeshLibraryFile(libraries["Neutron-CrossSection-EnergyMesh-base"]))
        throw InputConsistency(9, LOG_INP_CONS_E("Library loading failed - step 2\n"+
                               libraries["Neutron-CrossSection-EnergyMesh-base"]+
                               "\nFor detailed log report, check Library.Log"));

    double spatialNodes[] = {0., 1.};
    spatialOneRegionMesh = new CartesianOneDimMesh(spatialNodes, 2);
}

Library::~Library() {
    logStream.close() ;
    for (map< string,ProblemCrossSections* >::iterator it = problemMicroXS.begin(); it!=problemMicroXS.end(); it++)
        delete it->second;
    if (energyMesh != NULL) delete energyMesh ;
    if (spatialOneRegionMesh != NULL) delete spatialOneRegionMesh ;
    if (discreteMesh != NULL) delete discreteMesh ;

}

EnergyMesh * Library::getEnergyMesh() {
    return energyMesh ;
}

DiscreteMesh * Library::getDiscreteMesh() {
    return discreteMesh ;
}

vector<CrossSection *> Library::setOfTotalMicroXS(vector< string > & nucleiList) {
    vector<CrossSection *> micros;
    string rootLibName = "Neutron-CrossSection-" ;
    for (unsigned n = 0; n < nucleiList.size(); n++) {
        string keyLib = rootLibName+nucleiList[n] ;
        if ( problemMicroXS.find(nucleiList[n]) == problemMicroXS.end()) {
            if (! loadCrossSectionLibraryFile(libraries[keyLib]) ) {
                string err = "Library::setOfTotalMicroXS( vector< string > & nucleiList ) : library loading failed\nWas loading nucleus library "+
                keyLib+":" + libraries[keyLib]+
                "\nFor detailed log report, check Library.Log";
                throw InputConsistency(10, LOG_INP_CONS_E(err));
            }
        }
        if ( problemMicroXS.find(nucleiList[n]) != problemMicroXS.end()) {
            micros.push_back( problemMicroXS[nucleiList[n]]->getXS(ProblemCrossSections::TOTAL) );
        } else  {
            throw InputConsistency(11, LOG_INP_CONS_E("Library::setOfTotalMicroXS( vector< string > & nucleiList ) : it contains unknwon nucleus name :"+nucleiList[n])) ;
        }
    }
    return micros ;
}

bool Library::loadLibraryRootFile(const std::string& fileName) {
    // TODO: Library::loadLibraryRootFile(const std::string& fileName) : not implemented yet ;

    string root = "C:\\Users\\Sab_n_Phil\\Documents\\CBProjects\\Centurion_v0\\Libraries\\Light\\" ;

    libraries["RootPath"] = root ;

    libraries["Neutron-CrossSection-EnergyMesh-base"] = root+"EnergyMesh.xml" ;
    libraries["Neutron-CrossSection-EnergyMesh-dec1"] = "file.dat" ;
    libraries["Neutron-CrossSection-EnergyMesh-dec2"] = "file.dat" ;
    libraries["Neutron-CrossSection-EnergyMesh-dec3"] = "file.dat" ;

    libraries["Neutron-CrossSection-U235"] = root+"U235.xml" ;
    libraries["Neutron-CrossSection-O16"]  = root+"O16.xml" ;

    discreteMesh = new DiscreteMesh(2) ;

    return 1 ;
}



bool Library::loadEnergyMeshLibraryFile(const std::string& fileName) {
    try {
        logStream<<"Reading :"<<fileName<<endl;
        boost::property_tree::ptree pt ;
        boost::property_tree::read_xml(fileName, pt);
        boost::property_tree::ptree & v= pt.get_child("data.mesh") ;

        string   name         = v.get("<xmlattr>.name","MESH") ;
        unsigned groupsNumber = v.get("<xmlattr>.groupsNumber",0);
        string   unit         = v.get("<xmlattr>.unit","eV") ;
        logStream<<"Mesh Name is :"<<name<<endl;
        logStream<<"Number Of Groups is :"<<groupsNumber<<endl;
        logStream<<"Energy Mesh Unity is :"<<unit<<endl;
        if (groupsNumber == 0) return 0;

        vector<double> groupBoundaries(groupsNumber+1) ;
        stringstream data ( v.data() ) ;
        BOOST_FOREACH( double &gb, groupBoundaries ) data>>gb ;
        energyMesh=new EnergyMesh(&groupBoundaries[0], groupsNumber + 1);

        return 1 ;
    } catch (const exception & e) {
        logStream << "Boost exception has been caught in loadEnergyMeshLibraryFile() : "<<endl<<e.what() << endl;
        return 0;
    }
}

bool Library::loadCrossSectionLibraryFile(const std::string& fileName) {
    try {
        logStream<<"Reading :"<<fileName<<endl;
        boost::property_tree::ptree pt ;
        boost::property_tree::read_xml(fileName, pt);
        boost::property_tree::ptree & v= pt.get_child("data.medium") ;

        string   name = v.get("<xmlattr>.name","") ;
        string   mesh = v.get("<xmlattr>.mesh","");
        double   temp = v.get("<xmlattr>.temperature",0.0);
        logStream<<"Medium Name is :"<<name<<endl;
        logStream<<"Relative Mesh is :"<<mesh<<endl;
        logStream<<"Relative Temperature is :"<<temp<<endl;
        if ( name == "" || mesh == "" ) return 0;


        ProblemCrossSections * pbXS = new ProblemCrossSections() ;
        problemMicroXS[name] = pbXS ;
        pbXS->newTotalXS( new DefaultTotalCrossSection(energyMesh,spatialOneRegionMesh) ) ;
        pbXS->newScatXS( new DefaultScatteringCrossSection(energyMesh,discreteMesh,spatialOneRegionMesh) ) ;
        pbXS->newNuFissXS( new NuFissionCrossSection(energyMesh,spatialOneRegionMesh) ) ;
        pbXS->newFissDistXS( new FissionDistribution(energyMesh,spatialOneRegionMesh) ) ;
        unsigned scatOrder = 2 ;
        vector< vector<double> > scatteringXS( scatOrder, vector<double>(energyMesh->size()*energyMesh->size()) ) ;

        BOOST_FOREACH( boost::property_tree::ptree::value_type & section , v.get_child("for_macro_computation") ) {
            if (section.first == "section") {
                string   type  = section.second.get("<xmlattr>.type","") ;
                unsigned rang  = section.second.get("<xmlattr>.rang",1);
                string   unit  = section.second.get("<xmlattr>.unit","barn") ;
                unsigned order = section.second.get("<xmlattr>.order",0) ;
                logStream<<"Type  is :"<<type<<endl;
                logStream<<"Unit  is :"<<unit<<endl;
                logStream<<"Order is :"<<order<<endl;

                stringstream data ( section.second.data() ) ;
                logStream<<"Data is :"<<data.str()<<endl;

                CrossSection * xs = NULL;
                if (type == "TOTAL") xs = pbXS->getXS(ProblemCrossSections::TOTAL) ;
                if (type == "FISSION") xs = pbXS->getXS(ProblemCrossSections::NUFISSION) ;
                if (rang==1 && xs!=NULL) {
                    xs->collapseSpatialRegions("-",vector<string>(1,"0")) ;
                    xs->getData()->buildData() ;
                    FieldIterator fit=xs->getData()->getIterator() ;
                    for (unsigned g=0; g<energyMesh->size() ; g++) {
                        stringstream sit ;
                        sit<<g<<";-" ;
                        double d;
                        data>>d ;
                        cout<<sit.str()<<endl;
                        xs->getData()->setDouble(fit(sit.str()),d) ;
                    }
                }
                if (rang==2) {
                    for (unsigned g=0; g<energyMesh->size() ; g++) {
                        for (unsigned gp=0; gp<energyMesh->size() ; gp++) {
                            double d;
                            data>>d ;
                            scatteringXS[order].push_back(d) ;
                        }
                    }
                }
            }
        }

        CrossSection * xs = pbXS->getXS(ProblemCrossSections::SCATTERING) ;
        xs->collapseSpatialRegions("-",vector<string>(1,"0")) ;
        xs->getData()->buildData() ;
        FieldIterator fit=xs->getData()->getIterator() ;
        for (unsigned l=0; l<scatteringXS.size() ; l++) {
            for (unsigned g=0; g<energyMesh->size() ; g++) {
                for (unsigned gp=0; gp<energyMesh->size() ; gp++) {
                    stringstream sit ;
                    sit<<g<<";"<<gp<<";"<<"D"<<l<<";-" ;
                    cout<<sit.str()<<endl;
                    xs->getData()->setDouble(fit(sit.str()),scatteringXS[l][g*energyMesh->size()+gp]) ;
                }
            }
        }

        return 1 ;
    } catch (const exception & e) {
        logStream << "Boost exception has been caught in loadCrossSectionLibraryFile() : " <<endl<< e.what() << endl;
        return 0;
    }


    return 1 ;
}

