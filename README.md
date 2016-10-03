RottenFish : Random Poisson Distribution
=====================

Licence
---------------------------------------
RottenFish is under [MIT Licence](https://fr.wikipedia.org/wiki/Licence_MIT) and is written By Emmanuel Cervetti

Abstract
---------------------------------------

RottenFish is a very fast Poisson Distribution **(X,K)** approximate implementation for normal and *extreme* values.

* Number of occurences K up to 2^32 (non inclusive)
* X down to 2^-16 (non inclusive)

The main goal is to provide a very fast random generator that follow a Poisson Distribution usable for real time critical need.

For example, a constant average of only ~0.2 ns per random value is needed on a i5-4258U CPU @ 2.40GHz (2014 dual core laptop)


It's not intended to be monte-carlo critical accurate, but to give a credible magnitude approximation.
May be totaly suitable for videogames, CGI, ...

The library works using precomputed data tables (~4K of data) .
With some bit-like magnitude and linear interpolation, it try to give you the best values matching your experiment variables.

The random generator service underlying is a Xor Shift "Marsaglia", a good implementation for speed targeting.


 EXAMPLE USE when static linked
 -----------------------------------
    #include <iostream>
    #include "Src/RottenFish.h"
 
    RottenFish *rottenFishOperator = RottenFish::getInstance();
    /*
     * Load the Poisson variables
     */
    int k = 111042 ;
    double x = 0.07 ;
    rottenFishOperator->loadExperience(x,k);
    
    /*
     * Enjoy yourself !
     */
     
    //If I launch 111042 arrows towards a target , on a 7 % area of this target, I could have.....
    std::cout << "If I launch " << k << " arrows towards a target , on a "<< 100*x << " % area of this target, I could have..... ";
    
    //7831 arrows. 
    std::cout <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;
    
    //Or 7748 arrows.
    std::cout << "Or " <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;
    
    //Or 7757 arrows.
    std::cout << "Or " <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;
    
    //Or 7790 arrows.
    std::cout << "Or " <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;
    
    //Or 7708 arrows.
    std::cout << "Or " <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;
    
    //Or 7864 arrows.
    std::cout << "Or " <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;
    
    //Or 7693 arrows.
    std::cout << "Or " <<  rottenFishOperator->getSimulation() << " arrows." << std::endl;
