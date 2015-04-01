#include "gtest/gtest.h"
#include <vector>
#include <iostream>
#include <utility> // swap
#include <algorithm> // reverse
#include <cstdlib> // exit

using namespace std;

void printPerms(vector<vector<int>> perms);
void printPerm(vector<int> perm);

/*
 * http://en.wikipedia.org/wiki/Permutation#Algorithms_to_generate_permutations
 * section: Generation in lexicographic order
 *
 * @input should in ascending order
 */

vector<int>::iterator findK(vector<int> currentPerm);
vector<int>::iterator findL(vector<int> currentPerm, vector<int>::iterator iterK);

vector<vector<int>> permLexicOrder(vector<int> input) {
    vector<vector<int>> perms;
    auto iterK = input.end();
    do {
        iterK = findK(input);
        auto iterL = findL(input, iterK);
        std::cout<<*iterK << " " <<*iterL <<std::endl;
        auto tmpkkk = iterK;
        std::swap(*iterK, *iterL);
        std::cout <<*(iterK-2) <<" "
            <<*(iterK-1) 
            <<" " <<*iterK 
            //<< " " <<*iterL 
            <<" " <<*(iterK+1)<<std::endl;
        std::cout<<(iterK == tmpkkk) <<std::endl;
        std::cout<<input[0] <<input[1]<<input[2]<<input[3]<<std::endl;
        printPerm(input);
        std::reverse(++iterK, input.end());
        printPerm(input);
        perms.push_back(input);
        break;
    } while (iterK != input.end());

    return perms;
}

vector<int>::iterator findK(vector<int> currentPerm) {
    auto iter = currentPerm.rbegin();
    while(iter != currentPerm.rend()) {
        if (*iter > *(++iter)) {
            // convert reverse iter to normal iter
            // rbegin().base() == end(); so remember "-1"
            return iter.base() - 1; 
        }
    }

    return currentPerm.end();
}

vector<int>::iterator findL(vector<int> currentPerm, vector<int>::iterator iterK) {
    auto iter = currentPerm.rbegin();
    while (iter != currentPerm.rend()) {
        if (*iter > *iterK) {
            return iter.base() - 1;
        } else {
            ++iter;
        }
    }
    
    std::exit(1); // should not arrive here
    return currentPerm.end();
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
    auto result = permLexicOrder(vector<int>({1,2,3,4}));
    printPerms(result);
}



