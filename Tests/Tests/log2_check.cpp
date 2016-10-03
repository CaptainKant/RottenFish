//
// Created by Emmanuel Cervetti on 02/10/2016.
//

#include <cmath>
#include "gtest/gtest.h"
#include "../../Src/Log2.h"

TEST(log2_check,log2_spectre_1000) {
    Log2 *opLog2 = new Log2;
    for (int $i = 0; $i < 1000; $i++) {
        ASSERT_EQ(opLog2->log2($i),(unsigned int)log2($i));
    }

}
