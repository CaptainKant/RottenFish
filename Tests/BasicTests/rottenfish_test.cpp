//
// Created by Emmanuel Cervetti on 02/10/2016.
//

#include "gtest/gtest.h"
#include "../../RottenFish/RottenFish.h"


TEST(rottenfish_check,indexes) {
    RottenFish *rottenFishOperator = RottenFish::getInstance();
    unsigned int m_index ;
    unsigned int n_index ;
    rottenFishOperator->setIndex(1536,2048,m_index,n_index);

    ASSERT_EQ(n_index,11);
    ASSERT_EQ(m_index,17);

    rottenFishOperator->setIndex(8192,131072,m_index,n_index);

    ASSERT_EQ(n_index,17);
    ASSERT_EQ(m_index,3);

    rottenFishOperator->setIndex(32,128,m_index,n_index);
    ASSERT_EQ(n_index,7);
    ASSERT_EQ(m_index,1);

    rottenFishOperator->setIndex(45,156,m_index,n_index);
    ASSERT_EQ(n_index,7);
    ASSERT_EQ(m_index,0);

    delete(rottenFishOperator) ;
}


TEST(rottenfish_check,average_one) {
    RottenFish *rottenFishOperator = RottenFish::getInstance();

    rottenFishOperator->loadExperienceFromExpected(45,156);

    int nbExperiences = 1000 ;
    int somme = 0 ;
    int simulation ;
    for (int i = 0; i < nbExperiences; i++) {
        simulation = rottenFishOperator->getSimulation();
        somme+=simulation;
    }
    double moy = somme / nbExperiences ;

    ASSERT_GE(moy,42);
    ASSERT_GE(58,moy);

    delete(rottenFishOperator) ;
}

TEST(rottenfish_check,average_two) {
    RottenFish *rottenFishOperator = RottenFish::getInstance();

    rottenFishOperator->loadExperienceFromExpected(0.03,1);

    int nbExperiences = 1000 ;
    int somme = 0 ;
    int simulation ;
    for (int i = 0; i < nbExperiences; i++) {
        simulation = rottenFishOperator->getSimulation();
        somme+=simulation;
    }
    double moy = (double) somme / (double) nbExperiences ;

    ASSERT_GE(moy,0.02);
    ASSERT_GE(0.04,moy);

    delete(rottenFishOperator) ;
}


TEST(rottenfish_check,average_three) {
    RottenFish *rottenFishOperator = RottenFish::getInstance();

    rottenFishOperator->loadExperienceFromExpected(8653100,8653159);

    int nbExperiences = 100 ;
    int somme = 0 ;
    int simulation ;
    for (int i = 0; i < nbExperiences; i++) {
        simulation = rottenFishOperator->getSimulation();
        somme+=simulation;
    }
    double moy = somme / nbExperiences ;

    ASSERT_GE(moy,8653000);
    ASSERT_GE(8653200,moy);

    delete(rottenFishOperator) ;
}