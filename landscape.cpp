#include<iostream>
#include<vector>
#include "parameters.h"
#include "landscape.h"

Lowland::Lowland( lowlandParam& p ): param(p) {
    resetF();
}

// void Lowland::setFmax( float x ) {
//     param->fmax = x; 
// }

void Lowland::resetF() {
    f = param.fmax;
}

void Lowland::insertHerbivores( Herbivore new_herb ) {
    herbivores.push_back(&new_herb);
}

void Lowland::insertHerbivores( std::vector<Herbivore*>& new_herbs ) {
    new_herbs[0]->printParams();
    herbivores.insert( herbivores.begin() , new_herbs.begin() , new_herbs.end() );
}

void Lowland::feedHerbivores() {
    herbivores[0]->printParams();
    for ( Herbivore* herb : herbivores ) {
        double eaten = herb->eat(f);
        f -= eaten;
        if ( f <= 0 ) {
            break;
        }
    }
}

void Lowland::printAnimals() {
    std::cout << "Number of animals: " << herbivores.size() << std::endl;
    int i{0};
    for ( Herbivore* herb : herbivores ) {
        std::cout << "Herbivore " << i << std::endl;
        std::cout << "age: " << herb->getAge() << std::endl;
        std::cout << "weight: " << herb->getWeight() << std::endl;
        std::cout << "fitness: " << herb->getFitness() << std::endl;
    }
}

void Lowland::updateFitness() {
    for ( Herbivore* herb : herbivores ) {
        herb->updateFitness();
    }
}


void Lowland::annualCycle() {
    updateFitness();    
    feedHerbivores();    
}


