#include"leetcode921.cpp"
#include<gtest/gtest.h>
#include<iostream>
#include<stdexcept>
using namespace std;

TEST(Leetcode1047Test, solution){
    EXPECT_EQ(1, (new Solution())->minAddToMakeValid(")"));
}