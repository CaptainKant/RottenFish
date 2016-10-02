//
// Created by Emmanuel Cervetti on 30/09/2016.
//

#include "gtest/gtest.h"
#include "../../RottenFish/new_experiences.h"
#include "../../RottenFish/RottenFish.h"

TEST(loading_check,test_compile) {
    EXPECT_EQ(true,true);
}

TEST(loading_check,load_without_error) {
    load_all_poisson();
    EXPECT_EQ(true,true);
}

TEST(loading_check,instanciation_rottenfish) {
    RottenFish::getInstance();
    EXPECT_FLOAT_EQ(true,true);
}

TEST(loading_check,rottenfish_verif_val1) {
    RottenFish *r = RottenFish::getInstance();
    EXPECT_FLOAT_EQ(r->getVal(2,17,4),(float) 0.5568876351669);
}

TEST(loading_check,rottenfish_verif_val2) {
    RottenFish *r = RottenFish::getInstance();
    EXPECT_FLOAT_EQ(r->getVal(17,8,15),(float) 1.052734375);
}



