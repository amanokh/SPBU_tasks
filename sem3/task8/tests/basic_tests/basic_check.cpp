#include "../../polynom.cpp"
#include "../lib/googletest/include/gtest/gtest.h"


TEST(basic_check, poly_sum) {
    std::list<int> a = {1,3,4,5,0,2};
    std::list<int> b = {4,0,0,2};



    Polynom p1 = {0};
    Polynom p2 = {0};
    Polynom p3 = {};
    Polynom p4 = {4,2};
    Polynom p5 = {8,-4};
    Polynom p6 = {-12, 2};

EXPECT_EQ(p1+p2, p3);
EXPECT_EQ(p1+p3, p3);
    EXPECT_EQ(p4+p5+p6, p2);


}
