#include<iostream>
#include<vector>
#include "parameters.h"
#include "landscape.h"
#include "animal.h"


int main() {
    herbivoreParam hparam;
    lowlandParam lparam;
    Lowland lowland(lparam);
    std::vector<Herbivore*> ini_herbs;
    ini_herbs.reserve(5);
    for ( int i = 0 ; i < 5 ; i++ ) {
        Herbivore herb(10, 5., hparam);
        ini_herbs.push_back( &herb );
    }
 
    ini_herbs[0]->printParams();
    lowland.insertHerbivores(ini_herbs); 
    for ( int i=0; i<20; i++ ) {
        lowland.annualCycle();
        lowland.printAnimals();
    }
    return 0;
}


