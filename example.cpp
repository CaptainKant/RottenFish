#include <iostream>
#include "Src/RottenFish.h"

int main() {

    /*
        * Initialisation of the singleton operator
        */
    RottenFish *rottenFishOperator = RottenFish::getInstance();



    auto testExp = [rottenFishOperator ] (double moyenneAttendue ,int tirage, int nbExp) -> void {
        rottenFishOperator->loadExperienceFromExpected(moyenneAttendue,nbExp);
        auto cred = rottenFishOperator->getCredibily(tirage);
        std::cout << " obs " << tirage << "nbExp" << nbExp << " moy attendue" << moyenneAttendue
                     << " Credibility " << cred <<  std::endl;
    };


    auto rnd = new XorShiftMarsagliaBitsReserve();

    auto tab1on2pow = new double[64] ;
    unsigned int puiss2 = 2 ;
    tab1on2pow[0] = 1 ;
    tab1on2pow[1] = 1/2 ;
    for (auto i = 2; i < 64; i++) {
        puiss2 *= 2 ;
        tab1on2pow[i] = 1.0/ (double) puiss2 ;
    }

    for (auto i = 0; i < 32000; i++) {
        auto n = 10;

        rottenFishOperator->loadExperienceFromExpected(i*tab1on2pow[n],i);
        auto min = rottenFishOperator->getMinTirageAcceptable();
        std::cout << "1/2^" << n << " a une borne inf acceptable = " << min <<  " avec "<< i <<  " tirages" << std::endl ;
        rottenFishOperator->loadExperienceFromExpected(i*tab1on2pow[n+1],i);
        auto cred = rottenFishOperator->getCredibily(min);
        std::cout << "Dans ce cadre, cette valeur est crédible pour n+1 avec un score de " << cred <<  std::endl ;
        if (cred < 0.01) {
            std::cout << "1/2^" << n << " peut etre credible a partir de " << i << " iterations " << std::endl ;
            return 1 ;
        }

    }
    std::cout << "Sortie sans rien trouver" << std::endl ;;
    return 1 ;

    //testExp(0.5,1,2);
    //testExp(0.25,1,2);
    testExp(300,400,800);

    return 1 ;

    //hypothese 1 : la valeur est fonction d'une seule variable (et pas de deux)
    //nbPlus - nbMoins > 0 => ko , pas forcément ça dépend de l'entropie source
    //nbPlus - nbMoins = 0 => chance
    //quel est la probabilité que en fait la valeur soit fonction de deux variables, et que j'ai pas vu passer le truc ?

    //On observer le nombre de 1 (inversée si not)
    //Constante : Résultat d'une cible entière
    //Corellée 1-var : On devrait voir le résultat d'une demi cible
    //Corellée 2-var : On devrait voir le résultat d'un quart de cible
    //Corellée 3-var : On devrait voir le résultat d'un quart de cible

    





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