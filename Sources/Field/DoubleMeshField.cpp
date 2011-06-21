/* 
 * File:   DoubleMeshField.cpp
 * Author: Philippe Jacquet <contact@philippe-jacquet.com>
 * 
 * Created on 15 juin 2011, 22:33
 */

#include "DoubleMeshField.h"

using namespace std;


DoubleMeshField::DoubleMeshField(vector< pair< Mesh*, OptionMeshField> >& l_meshes) {
}

DoubleMeshField::DoubleMeshField(const DoubleMeshField& orig) {
}

DoubleMeshField::~DoubleMeshField() {
}

void DoubleMeshField::buildFamily(Mesh* mesh, vector<string> regionsName, string familyName) {
    
}