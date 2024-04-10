#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "pch.h"
using namespace std;

int maxsubarray(vector<int>& a) {
    int n = a.size();
    int maxcnt = 0;
    int cursum = 0;
    int i = 0;
    for ( i = 0; i < n; i++) {
        cursum = max(0, cursum + a[i]);
        maxcnt = max(maxcnt, cursum);
    }
    return maxcnt;
}

// 测试用例:单个0
TEST(testmaxsubarray, deal0) {
    std::vector<int> only0 = { 0 };
    EXPECT_EQ(maxsubarray(only0), 0);
}

// 测试用例:全0
TEST(testmaxsubarray, dealall0) {
    std::vector<int> all0 = { 0, 0, 0 ,0 ,0 ,0 };
    EXPECT_EQ(maxsubarray(all0), 0);
}

// 测试用例:空
TEST(testmaxsubarray, dealempty) {
    std::vector<int> null = {};
    EXPECT_EQ(maxsubarray(null), 0);
}

// 测试用例：全为负数
TEST(testmaxsubarray, dealbelow0) {
    std::vector<int> below0 = { -11, -23, -30, -8 };
    EXPECT_EQ(maxsubarray(below0), 0);
}

// 测试用例：全为正数
TEST(testmaxsubarray, dealover0) {
    std::vector<int> over0 = { 16, 18, 10, 9 };
    EXPECT_EQ(maxsubarray(over0), 53);
}

// 测试用例：既有正数，又有负数
TEST(testmaxsubarray, dealmix) {
    std::vector<int> mix = { 36, -5, 15, -17, 10, -5 };
    EXPECT_EQ(maxsubarray(mix), 46);
}

// 测试用例:单个数
TEST(testmaxsubarray, dealsingle) {
    std::vector<int> singlebelow0 = { -10 };
    EXPECT_EQ(maxsubarray(singlebelow0), 0);

    std::vector<int> singleover0 = { 12 };
    EXPECT_EQ(maxsubarray(singleover0), 12);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}