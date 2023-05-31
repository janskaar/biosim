#include <iostream>
#include <vector>
#include <cmath>
#include "parameters.h"
#include "animal.h"



Herbivore::Herbivore( int a, double w, herbivoreParam& p ): param(p) {
    age = a;
    weight = w;
}

void Herbivore::setWeight( double w ) {
        weight = w;
}

void Herbivore::setParam( herbivoreParam & p ) {
        param = p;
}

void Herbivore::setAge( int a ) {
        age = a;
}

void Herbivore::ageOneYear() {
    ++age;
}

double Herbivore::eat( double fodder ) {
    double eaten;
    if ( fodder < param.appetite ) {
        eaten = fodder;
        weight += fodder;
    }
    else {
        eaten = param.appetite;
        weight += param.appetite;
    }
    return eaten;
}

void Herbivore::printParams() {
}


void Herbivore::updateFitness() {
    double a_factor;
    double w_factor;

    a_factor =  1 / (1 + exp(param.phi_age * (age - param.a_half)));
    w_factor =  1 / (1 + exp(-param.phi_weight * (weight - param.w_half)));

    fitness = a_factor * w_factor;
    std::cout << "Updating fitness: " << fitness << std::endl;
    std::cout << "a_factor: " << a_factor << std::endl;
    std::cout << "w_factor: " << w_factor << std::endl;
    std::cout << "weight: " << weight << std::endl;
    std::cout << "phi_weight: " << param.phi_weight << std::endl;
    std::cout << "w_half: " << param.w_half << std::endl;
}

double Herbivore::getAge() {
    return age;
}

double Herbivore::getWeight() {
    return weight;
}

double Herbivore::getFitness() {
    return fitness;
}





