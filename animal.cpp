#include <iostream>

//using namespace std;
class Herbivore {
    public:
        Herbivore( int age, double weight ) {
            std::cout << "INSIDER HERBIVORE CONSTRUCTOR" << "\n";
        }

        void setWeight( double weight );
        void setAge( int age );
        void age();
        double eat( double fodder );

    private:
        int age;
        double weight;
};


void Herbivore::setWeight( double w ) {
        std::cout << "SETTING WEIGHT" << w << std::endl;
        weight = w;
}

void Herbivore::setAge( int a ) {
        std::cout << "SETTING WEIGHT" << a << std::endl;
        age = a;
}

void Herbivore:age() {






int main() {
    Herbivore herb(10, 5.);
    herb.setAge(100);
    herb.setWeight(1.);
    return 0;
}
