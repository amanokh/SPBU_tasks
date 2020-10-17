#include "../../main.cpp"
#include <vector>
#include "../lib/googletest/include/gtest/gtest.h"


TEST(basic_check, 1d_to_2d){
    vector<int> a = {1,3,5,6,7,8,8,9,9,76,89,90};
    vector<vector<int>> b = {{1,3,5},{6,7,8},{8,9,9},{76,89,90}};

    EXPECT_EQ(convert(a, 4, 3), b);

}
TEST(basic_check, 2d_to_1d){
    vector<int> a = {1,3,5,6,7,8,8,9,9,76,89,90};
    vector<vector<int>> b = {{1,3,5},{6,7,8},{8,9,9},{76,89,90}};

    EXPECT_EQ(convert(b), a);
}

