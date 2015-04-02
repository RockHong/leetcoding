/*
 * Given a collection of numbers, return all possible permutations.
 * 
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

// Tag:

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> solutions;
        vector<int> candidate;

        if (num.empty()) {
            return solutions;
        }

        //permute_bt(num, solutions, candidate);
        permHeap(num, num.size(), solutions);

        return solutions;
    }

    // Heap's alg
    void permHeap(vector<int> &input, int n, vector<vector<int>> &output) {
        if (n == 1) {
            output.push_back(input);
            return;
        }

        for (int i = 0; i < n; ++i) {
            permHeap(input, n-1, output);
            if (n % 2 == 1) {
                std::swap(input[0], input[n-1]);
            } else {
                std::swap(input[i], input[n-1]);
            }
        }
    }


    // backtracking
    // permutation is like 8-queen problem with less constraint, just being in
    // different rows and columns
    void permute_bt(const vector<int> &num, vector<vector<int>> &solutions, vector<int> &candidate) {
        static auto size = num.size();

        if (reject(candidate)) {
            return;
        }
        if (pass(candidate, size)) {
            solutions.push_back(candidate);
            return;
        }
        if (candidate.size() == size) {
            return;
        }

        for (int i = 0; i < size; ++i) {
            candidate.push_back(num[i]);
            permute_bt(num, solutions, candidate);
            candidate.pop_back();
        }

    }

    bool reject(const vector<int> &candidate) {
        auto size = candidate.size();
        if (size == 0) {
            return false;
        }
        
        int last = candidate.back();
        for (int i = 0; i < size - 1; ++i) {
            if (candidate[i] == last) {
                return true;
            }
        }
        return false;
    }

    bool pass(const vector<int> &candidate, int size) {
        if (candidate.size() != size) {
            return false;
        }

        int last = candidate.back();
        for (int i = 0; i < size - 1; ++i) {
            if (candidate[i] == last) {
                return false;
            }
        }
        return true;
    }

};

// tests begin
void printPerms(vector<vector<int>> perms) {
    for (auto p: perms) {
        for (auto i: p) {
            std::cout<<i <<" ";
        }
        std::cout<<std::endl;
    }
}

TEST(Problem46Test, TestPermHeap) {
    Solution s;
    vector<int> num = {1,2,3};
    vector<vector<int>> perms;

    perms = s.permute(num);
    printPerms(perms);
}
