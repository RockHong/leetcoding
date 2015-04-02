#include "gtest/gtest.h"
#include <vector>
#include <iostream>
#include <utility> // swap
#include <algorithm> // reverse
#include <cstdlib> // exit

using namespace std;

void printPerms(vector<vector<int>> perms);
void printPerm(vector<int> perm);

/*** Generation in lexicographic order ***/

/*
 * http://en.wikipedia.org/wiki/Permutation#Algorithms_to_generate_permutations
 * section: Generation in lexicographic order
 *
 * @input should in ascending order
 */

vector<int>::iterator findK(vector<int> &currentPerm);
vector<int>::iterator findL(vector<int> &currentPerm, vector<int>::iterator iterK);

vector<vector<int>> permLexicOrder(vector<int> input) {
    vector<vector<int>> perms;
    perms.push_back(input);

    auto iterK = input.end();
    do {
        iterK = findK(input);
        if (iterK == input.end()) {
            break;
        }
        auto iterL = findL(input, iterK);
        std::swap(*iterK, *iterL);
        std::reverse(++iterK, input.end());
        perms.push_back(input);
    } while (1);

    return perms;
}

// pass by ref. we do not want a copy on pass-in argument, which
// makes the returned iterator meaningless
vector<int>::iterator findK(vector<int> &currentPerm) {
    auto iter = currentPerm.rbegin();
    while(iter + 1 != currentPerm.rend()) {
        if (*iter > *(iter+1)) {
            // convert reverse iter to normal iter
            // rbegin().base() == end(); so remember "-1"
            return (iter+1).base() - 1; 
        }
        ++iter;
    }

    return currentPerm.end();
}

vector<int>::iterator findL(vector<int> &currentPerm, vector<int>::iterator iterK) {
    auto iter = currentPerm.rbegin();
    while (iter != currentPerm.rend()) {
        if (*iter > *iterK) {
            return iter.base() - 1;
        } else {
            ++iter;
        }
    }
    
    std::cout <<"error happens, terminated" <<std::endl;
    std::exit(1); // should not arrive here
    return currentPerm.end();
}



/*** Generation with minimal changes: Heap's algorithm ***/
/*
 * http://en.wikipedia.org/wiki/Permutation#Generation_with_minimal_changes
 * "any two consecutive permutations in its output differ by swapping two adjacent values."
 *
 * "One advantage of this method is that the small amount of change \
 *   from one permutation to the next allows the method to be implemented \
 *   in constant time per permutation. "
 */
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

// tests begin
void printPerms(vector<vector<int>> perms) {
    for (auto p: perms) {
        for (auto i: p) {
            std::cout<<i <<" ";
        }
        std::cout<<std::endl;
    }
}

void printPerm(vector<int> perm) {
    for (auto p: perm) {
        std::cout<<p <<" ";
    }
    std::cout<<std::endl;
}

TEST(PermutationsCppTest, permLexicOrderTest) {
    auto result = permLexicOrder({1,2,3});
    printPerms(result);
}

TEST(PermutationsCppTest, permHeapTest) {
    vector<vector<int>> output;
    vector<int> input = {1,2,3};
    permHeap(input, 3, output);
    printPerms(output);
}

