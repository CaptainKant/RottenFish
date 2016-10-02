//
// Created by Emmanuel Cervetti on 01/10/2016.
//

#include "gtest/gtest.h"
#include "../../RottenFish/XorShiftMarsagliaBitsReserve.h"

TEST(random_check,random_moy) {
    XorShiftMarsagliaBitsReserve *randOperator = new XorShiftMarsagliaBitsReserve();
    int nbExperiences = 100 ;
    double somme = 0 ;
    for (int i = 0; i < nbExperiences; i++) {
        somme+=randOperator->rand(6) ;
    }
    double moy = somme / (double) nbExperiences ;
    ASSERT_TRUE(moy>0.4);
    ASSERT_TRUE(moy<0.6);
}

TEST(random_check,random_dist_1) {
    XorShiftMarsagliaBitsReserve *randOperator = new XorShiftMarsagliaBitsReserve();
    int nbExperiences = 100 ;
    double val = 0 ;
    int reussites = 0 ;
    for (int i = 0; i < nbExperiences; i++) {
        val =randOperator->rand(30) ;
        if(val > 0.3 && val < 0.4 ) {
            reussites++ ;
        }
    }
    ASSERT_TRUE(reussites>5);
    ASSERT_TRUE(reussites<15);
}

