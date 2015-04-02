/*
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * 
 * For example,
 *     [1,1,2] have the following unique permutations:
 *     [1,1,2], [1,2,1], and [2,1,1].
 */

// Tag:

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> perms;
        
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        buildKeyMap(num, map1, map2);

        vector<int> transformed;
        transformed.reserve(num.size());
        for(auto e: num) {
            transformed.push_back(map1[e]);
        }
        unordered_set<int> pset;
        permHeapUniq(transformed, num.size(), pset);

        convertPerms(pset, map2, perms, num.size());
        return perms;
    }

    void buildKeyMap(const vector<int> &num, unordered_map<int, int> &map1,
            unordered_map<int, int> &map2) {
        for (auto e: num) {
            map1[e] = 1;
        }

        int i = 1;
        for (auto &kv: map1) {
            kv.second = i;
            map2[i] = kv.first;
            ++i;
        }
    }

    void permHeapUniq(vector<int> &input, int n, unordered_set<int> &perms) {
        if (n == 1) {
            perms.insert(calcKey(input));
            return;
        }

        for (int i = 0; i < n; ++i) {
            permHeapUniq(input, n-1, perms);
            if (n % 2 == 1) {
                std::swap(input[0], input[n-1]);
            } else {
                std::swap(input[i], input[n-1]);
            }
        }
    }

    int calcKey(const vector<int> &input) {
        int i = 0;
        for (auto e: input) {
            i = i*10 + e;
        }
        return i;
    }

    void convertPerms(const unordered_set<int> &pset, /*const*/ unordered_map<int, int> &kmap, 
            vector<vector<int>> &perms, int size) {
        vector<int> perm;
        perm.reserve(size);
        for (auto p: pset) {
            while(int t = p % 10) {
                perm.push_back(kmap[t]);
                p = p / 10;
            }
            perms.push_back(perm);
            perm.clear();
        }
    }
    
};

// tests begin
void printPerms(const vector<vector<int>> &perms) {
    cout <<perms.size() <<" permutations:" <<endl;
    for (auto p: perms) {
        for (auto e: p) {
            cout <<e <<" ";
        }
        cout << endl;
    }
}

TEST(Problem47Test, Test1) {
    Solution s;
    vector<vector<int>> perms;

    vector<int> input1 = {1,2,3};
    perms = s.permuteUnique(input1);
    printPerms(perms);

    vector<int> input2 = {31,22,31};
    perms = s.permuteUnique(input2);
    printPerms(perms);
}
