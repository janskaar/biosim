#include <iostream>
#include <vector>

class Herbivore {
    public:
        Herbivore( int age, double weight ) {
            std::cout << "INSIDER HERBIVORE CONSTRUCTOR" << std::endl;
            setAge(age);
            setWeight(weight);
        }

        void setWeight( double weight );
        void setAge( int age );
        void ageOneYear();
        double eat( double fodder );

    private:
        int age;
        double weight;
};

void Herbivore::setWeight( double w ) {
        std::cout << "SETTING WEIGHT " << w << std::endl;
        weight = w;
}

void Herbivore::setAge( int a ) {
        std::cout << "SETTING AGE " << a << std::endl;
        age = a;
}

void Herbivore::ageOneYear() {
    ++age;
    std::cout << age << std::endl;
}


class Lowland {
    public:
        Lowland();

        void setFmax( float x ) {
            fmax = x; 
        }

        void resetF() {
            f = fmax;
        }

        void insertHerbivore( Herbivore herb ) {
            std::cout << "Initial number of herbivores: " << herbivores.size() << std::endl;
            std::cout << "INSERTING HERBIVORE" << std::endl;
            herbivores.push_back(&herb);
            std::cout << "Final number of herbivores: " << herbivores.size() << std::endl;
        }

    private:
        float fmax;
        float f;
        std::vector<Herbivore*> herbivores;
};        


Lowland::Lowland() {
    std::cout << "INSIDE LOWLAND CONSTRUCTOR" << std::endl;
    setFmax(700.);
    resetF();
}

int main() {
    Lowland l;
    Herbivore herb(10, 5.);
    herb.setWeight(1.);
    l.insertHerbivore(herb);
    return 0;
}
