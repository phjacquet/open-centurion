/* 
 * File:   Geometry.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 12 juin 2011, 22:32
 */
#include <stdexcept>
#include "Geometry.h"
#include "Library.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/EnergyMesh.h"
#include "Mesh/Region.h"
#include "Sections/DefaultTotalCrossSection.h"
#include "Sections/DefaultScatteringCrossSection.h"
#include "Sections/NuFissionCrossSection.h"
#include "Sections/FissionDistribution.h"

using namespace std;

Geometry::Geometry(Mesh * l_spatialMesh, Library * l_library) {
    spatialMesh = l_spatialMesh ;
    library = l_library ;
    energyMesh = library->getEnergyMesh();
    buildXS();
}
    
Geometry::~Geometry() {
}


Geometry::Geometry(const Geometry& orig) {
    throw runtime_error("Geometry::Geometry(const Geometry& orig)") ;
}

Geometry Geometry::operator=(const Geometry& orig) {
    throw runtime_error("Geometry::Geometry operator=(const Geometry& orig)") ;
}

void Geometry::fill(const string & name, 
                    const vector<string> & regionsName, 
                    const vector< pair< string,double > > & medium) {
    vector<string> nucleiList ;
    vector<double> nucleiConcentrations ;
    for (unsigned n = 0; n < medium.size(); n++ ) {
        nucleiList.push_back(medium[n].first) ;
        nucleiConcentrations.push_back(medium[n].second) ;
    }
    pbMacXS.getXS(ProblemCrossSections::TOTAL)->collapseSpatialRegions(name, regionsName) ;
    pbMacXS.getXS(ProblemCrossSections::TOTAL)->calculateMacro( name, library->setOfTotalMicroXS(nucleiList), nucleiConcentrations ) ;
}

ProblemCrossSections * Geometry::getXS() {
    return &pbMacXS;
}

void Geometry::buildXS() {
    pbMacXS.newTotalXS( new DefaultTotalCrossSection(energyMesh,spatialMesh) ) ;
    pbMacXS.newScatXS( new DefaultScatteringCrossSection(energyMesh,spatialMesh) ) ;
    pbMacXS.newNuFissXS( new NuFissionCrossSection(energyMesh,spatialMesh) ) ;
    pbMacXS.newFissDistXS( new FissionDistribution(energyMesh,spatialMesh) ) ;
}