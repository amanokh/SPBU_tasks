#include "../../main.cpp"
#include "../../main2.cpp"
#include "../../main3.cpp"
#include "../lib/googletest/include/gtest/gtest.h"


TEST(basic_check, task1_sort) {
    vector<pair<int, int>> a = {make_pair(1, 0), make_pair(0,1), make_pair(-1, 0)};
    vector<pair<int, int>> res = {make_pair(1,2), make_pair(2, 3)};

    EXPECT_EQ(dots_sort(a), res);
}
TEST(basic_check, task2_unique){
    vector<int> ints = {1,2,3,2,3,4};
    vector<string> res = {"NO","NO","NO","YES","YES","NO"};

    EXPECT_EQ(unique(ints), res);
}
TEST(basic_check, task3_dict){
    map<string, string> a = {{"Hello", "Hi"},{"Bye","Goodbye"},{"List", "Array"}};
    string word = "Goodbye";
    EXPECT_EQ(dictionary(a, word), "Bye");
}
