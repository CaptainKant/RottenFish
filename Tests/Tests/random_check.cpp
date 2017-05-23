//
// Created by Emmanuel Cervetti on 01/10/2016.
//

#include "gtest/gtest.h"
#include "../../Src/XorShiftMarsagliaBitsReserve.h"

TEST(random_check,random_moy) {
    XorShiftMarsagliaBitsReserve *randOperator = new XorShiftMarsagliaBitsReserve();
    int nbExperiences = 10000 ;
    double somme = 0 ;
    for (int i = 0; i < nbExperiences; i++) {
        somme+=randOperator->rand(6) ;
    }
    double moy = somme / (double) nbExperiences ;
    ASSERT_GT(moy,0.4);
    ASSERT_LT(moy,0.6);
    delete randOperator ;
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
    ASSERT_GT(reussites,5);
    ASSERT_LT(reussites,15);
    delete randOperator ;
}

TEST(random_check,random_dist_2) {
    XorShiftMarsagliaBitsReserve *randOperator = new XorShiftMarsagliaBitsReserve();
    int nbExperiences = 100 ;
    double val = 0 ;
    int reussites = 0 ;
    for (int i = 0; i < nbExperiences; i++) {
        val =randOperator->rand(30) ;
        if(val < 0.1 ) {
            reussites++ ;
        }
    }
    ASSERT_GT(reussites,5);
    ASSERT_LT(reussites,15);
    delete randOperator ;
}

TEST(random_check,random_dist_3) {
    XorShiftMarsagliaBitsReserve *randOperator = new XorShiftMarsagliaBitsReserve();
    int nbExperiences = 100 ;
    double val = 0 ;
    int reussites = 0 ;
    for (int i = 0; i < nbExperiences; i++) {
        val =randOperator->rand(30) ;
        if(val > 0.9 ) {
            reussites++ ;
        }
    }
    ASSERT_GT(reussites,5);
    ASSERT_LT(reussites,15);
    delete randOperator ;
}

TEST(random_check,random_moy2) {
    XorShiftMarsagliaBitsReserve *randOperator = new XorShiftMarsagliaBitsReserve();
    int nbExperiences = 10000 ;
    double somme = 0 ;
    for (int i = 0; i < nbExperiences; i++) {
        somme+=randOperator->rand(30) ;
    }
    double moy = somme / (double) nbExperiences ;
    ASSERT_GT(moy,0.45);
    ASSERT_LT(moy,0.55);
    delete randOperator ;
}

