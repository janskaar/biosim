#pragma once

class Herbivore {
    public:
        Herbivore( int a, double w, herbivoreParam& p );

        void setWeight( double weight );
        void setAge( int age );
        void ageOneYear();
        double eat( double fodder );
        void printParams();
        void setParam( herbivoreParam& param );
        void updateFitness(); 
        double getAge();
        double getWeight();
        double getFitness();

    private:
        double fitness;
        int age;
        double weight;
        herbivoreParam& param;
};


