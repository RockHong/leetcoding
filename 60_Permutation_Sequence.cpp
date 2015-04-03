/*
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 *        "123"
 *        "132"
 *        "213"
 *        "231"
 *        "312"
 *        "321"
 * Given n and k, return the kth permutation sequence.
 * 
 * Note: Given n will be between 1 and 9 inclusive.
 */

// Tag:

#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <list>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string p;
        list<char> table;
        for (int i = 0; i < n; ++i) {
            table.push_back((char)((int)'1' + i));
        }

        getPerm(n, k, p, table);

        return p;
    }

    int factorial(int n) {
        static int F[9] = {0};

        if (F[0] == 0) {
            F[0] = 1;
            for (int i = 1; i < 9; ++i) {
                F[i] = F[i-1]*(i+1);
            }
        }
        return F[n-1];
    }

    char getCharAndRemove(list<char> &table, int k) {
        auto iter = table.begin();
        int i = 0;
        while (iter != table.end()) {
            if (i == k) {
                char ch = *iter;
                table.erase(iter);
                return ch;
            }
            ++iter;
            ++i;
        }

        std::cerr <<"getChar(): error" <<std::endl;
        std::exit(1);
        return '?';
    }

    void getPerm(int n, int k, string &p, list<char> &table) {
        if (k < 1 || k > factorial(n)) {
            return;
        }

        if (n == 1) {
            p.push_back(*(table.begin()));
            return;
        }

        p.push_back(getCharAndRemove(table, (k-1) / factorial(n-1)));
        int k_2 = k % factorial(n-1);
        getPerm(n-1, k_2 == 0 ? factorial(n-1) : k_2, p, table);
    }   
};

// tests begin
TEST(Problem60Test, Test1) {
    Solution s;

    EXPECT_TRUE(s.getPermutation(3, 1) == "123");
    EXPECT_TRUE(s.getPermutation(3, 6) == "321");
    EXPECT_TRUE(s.getPermutation(3, 3) == "213");
    EXPECT_TRUE(s.getPermutation(3, 4) == "231");
    EXPECT_TRUE(s.getPermutation(3, 999) == "");
    EXPECT_TRUE(s.getPermutation(3, 0) == "");
    EXPECT_TRUE(s.getPermutation(9, 54494) == "248716395");
}


