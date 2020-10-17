#include "../../main.cpp"
#include "../lib/googletest/include/gtest/gtest.h"

string s = "    df     dfgdfg      df    asd    df     .";

string cleanSpaces_res = cleanSpaces(s);
string except_last_res = except_last(cleanSpaces_res);
string reverse_res = reverse_word(except_last_res);


TEST(basic_check, cleanSpaces) {
    string cleanSpaces_check = "df dfgdfg df asd df";
    EXPECT_EQ(cleanSpaces_res, cleanSpaces_check);
}
TEST(basic_check, except_last){
    string except_last_check = "dfgdfg asd";
    EXPECT_EQ(except_last_check, except_last_res);
}
TEST(basic_check, reverse){
    string reverse_check = "gfdgfd dsa";
    EXPECT_EQ(reverse_res, reverse_check);
}
