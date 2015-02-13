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

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> solutions;
        vector<int> candidate;

        if (num.empty()) {
            return solutions;
        }

        permute_bt(num, solutions, candidate);

        print(solutions[0]);
        print(solutions[1]);
        return solutions;
    }

    // backtracking
    // permutation is like 8-queen problem with less constraint, just being in
    // different rows and columns
    void permute_bt(const vector<int> &num, vector<vector<int>> &solutions, vector<int> &candidate) {
        static auto size = num.size();

        if (reject(candidate)) {
            cout <<"reject ";
            print(candidate);
            return;
        }
        if (pass(candidate, size)) {
            cout <<"pass" ;
            print(candidate);
            solutions.push_back(candidate);
            cout <<"got it ";
            print(solutions.back());
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

    // tmp
    void print(const vector<int> &v) {
        auto iter = v.begin();
        auto end = v.end();
        while (iter != end) {
            cout <<*(iter++) << " ";
        }
        cout <<endl;
    }

    // todo: no bt version
};

// tests begin
TEST(Problem46Test, Test1) {
//int main(int argc, char **argv) {
    Solution s;
    vector<int> num;
    num.push_back(0);
    num.push_back(1);
    //num.push_back(2);

    s.permute(num);
}
