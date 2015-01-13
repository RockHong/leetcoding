/*
 * Given an integer n, return the number of trailing zeroes in n!.
 * Note: Your solution should be in logarithmic time complexity.
 */

#include "gtest/gtest.h"
#include <iostream>
#include <limits>

using namespace std;

int trailingZeroes(int n) {
    if (n <= 0) {
        return 0;
    }
    
    int m = n/5;
    int ret = m;
    while(m >= 5) {
        n = m;
        m = n/5;
        ret += m;
    }
    return ret;
}

// tests begin
// n should large than 0
int brutal(int n) {
    // int sum = 1; // int is so short for brutal...
    long long sum = 1; // long long is guaranteed to be 64bit. long long is also too short for '25'
    //static const long long TRUNCATE = 1'000'000'000'000'000; // gcc  4.8.3 not supports this c++ 14 feature
    static const long long TRUNCATE = 1000000000000000; 

    for (int i = 1; i <= n; ++i) {
        sum %= TRUNCATE;
        sum *= i;
    }
    // ::max() is constexpr
    //cout<<"n is " <<n <<", sum is " <<sum 
    //    <<", int limitation is " <<numeric_limits<int>::max() 
    //    <<", long long limitation is " <<numeric_limits<long long>::max() 
    //    <<endl;

    int ret = 0;
    while (sum%10 == 0) {
        sum /= 10;
        ++ret;
    }
    return ret;
}

TEST(TrailingZeroesTest, Test1) {
    EXPECT_EQ(0, trailingZeroes(-1));
    EXPECT_EQ(0, trailingZeroes(0));
    EXPECT_EQ(0, trailingZeroes(1));

    // actually "EXPECT_EQ(?, trailingZeroes(25));" is a special case,
    // but it may be hard to think about this special number.
    // here are some clues: in trailingZeroes()'s implementation, '5' 
    // is a special number. we can easily come out with -1, 0 and 1, 
    // which are not multiple of 5; also 5 and 10 are easily come out,
    // which are multiple of 5. how about 25, which is 5 multiple 5,
    // 'double special'!
    // if 25 is hard to come out, sometimes feed your testing function
    // with input 'more than enough' will help let bug surface.
    for (int i = 2; i < 50; ++i) {
        EXPECT_EQ(brutal(i), trailingZeroes(i));
    }
}

