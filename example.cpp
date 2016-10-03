#include <iostream>
#include "Src/RottenFish.h"

int main() {

    /*
        * Initialisation of the singleton operator
        */
    RottenFish *rottenFishOperator = RottenFish::getInstance();
    /*
     * Load the Poisson variables
     */
    int k = 111042 ;
    double x = 0.07 ;
    rottenFishOperator->loadExperience(x,k);
    /*
     * Enjoy yourself
     */
    std::cout << "If I launch " << k << " arrows towards a target , on a "<< 100*x << " % area of this target, I could have..... ";
    std::cout <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;
    std::cout << "Or " <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;
    std::cout << "Or " <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;
    std::cout << "Or " <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;
    std::cout << "Or " <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;
    std::cout << "Or " <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;
    std::cout << "Or " <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;


    unsigned long int clickstart = clock();
    unsigned long int result = 0 ;
    unsigned long int number = 10000000 ;
    for(int i = 0 ; i < number ; i++ ) {
        result += rottenFishOperator->getSimulation() ;
    }
    std::cout << result << "Clocks " << ( clock() - clickstart ) << "cps " << CLOCKS_PER_SEC ;



}