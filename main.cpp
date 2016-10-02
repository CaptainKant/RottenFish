#include <iostream>
#include "RottenFish/RottenFish.h"

int main() {

    RottenFish *rottenFishOperator = RottenFish::getInstance();

    rottenFishOperator->loadExperienceFromExpected(0.03,1);

    int nbExperiences = 100 ;
    int somme = 0 ;
    int simulation ;
    for (int i = 0; i < nbExperiences; i++) {
        simulation = rottenFishOperator->getSimulation();
        std::cout << "Sim : " << simulation << std::endl;
        somme+=simulation;
    }
    double moy = somme / nbExperiences ;

    std::cout << "moy : " << moy << std::endl;

    delete(rottenFishOperator) ;

    return 0;
}