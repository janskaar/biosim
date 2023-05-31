#pragma once
#include<vector>
#include "animal.h"
#include "parameters.h"


class Lowland {
    public:
        Lowland( lowlandParam& p );

//        void setFmax( float x );

        void resetF();

        void insertHerbivores( Herbivore herb );

        void insertHerbivores( std::vector<Herbivore*>& new_herbs );

        void feedHerbivores();

        void printAnimals();

        void annualCycle();

        void updateFitness();

    private:
        float f;
        std::vector<Herbivore*> herbivores;
        lowlandParam& param;
};        


