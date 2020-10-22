#include "../../polynom.cpp"
#include "../lib/googletest/include/gtest/gtest.h"


TEST(basic_check, poly_sum) {
    Polynom p1 = {0};
    Polynom p2 = {0};
    Polynom p4 = {4,2};
    Polynom p5 = {8,-4};
    Polynom p6 = {-12, 2};

    EXPECT_EQ(p1+p2, p2);
    EXPECT_EQ(p1+p4, p4);
    EXPECT_EQ(p4+p5+p6, p2);
}

TEST(basic_check, poly_substract) {
    Polynom p1 = {0};
    Polynom p2 = {0};
    Polynom p4 = {4,2};
    Polynom p5 = {8,-4};
    Polynom p6 = {-12, 2};

    EXPECT_EQ(p1-p2, p2);
    EXPECT_EQ(p4-p1, p4);
    EXPECT_EQ(p4+p5-p6, p1-p6-p6);
}

TEST(basic_check, poly_scalar_multiply) {
    Polynom p1 = {0};
    Polynom p2 = {0};
    Polynom p4 = {4,2};
    Polynom p5 = {-8,-4};
    Polynom p6 = {-12, 2};

    EXPECT_EQ(-2 * p4, p5);
    EXPECT_EQ(0 * p6, p1);
}

TEST(basic_check, poly__multiply) {
    Polynom p1 = {0};
    Polynom p2 = {1};
    Polynom p4 = {4,2};
    Polynom p5 = {-8,-4};
    Polynom p6 = {-32, -32, -8};

    EXPECT_EQ(p5 * p4, p6);
    EXPECT_EQ(p1 * p6, p1);
    EXPECT_EQ(p2 * p6, p6);

}
