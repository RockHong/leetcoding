/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than [ n/2 ] times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 */

#include "gtest/gtest.h"
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <thread>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        // error: no such usage, since vector<int>::iterator and 
        // vector<int>::const_iterator are two different member type
        // auto const iter = num.begin(); 
        // fix 1
        vector<int>::const_iterator iter = num.begin();
        // fix 2, use typedef
        // fix 3
        // const vector<int> & cNum = num;
        // auto iter = cNum.begin();

        auto end = num.end();
        int candidate;
        int next;
        int blood = 0;

        while (iter != end) {
            if (blood == 0) {
                candidate = *(iter++);
                ++blood;
            } else {
                next = *(iter++);
                if (next == candidate) {
                    ++blood;
                } else {
                    --blood;
                }
            }
        }

        return candidate;
    }
};

// tests begin
const int majority = -1;

vector<int> generateInput(bool half) {
    static int sleep = 100;
    sleep += 100;
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep));

    unsigned long seed = std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1);
    std::default_random_engine e(seed);
    std::cout <<"seed is: " <<seed <<endl;

    int max_size = 30;
    int min_size = 15;
    std::uniform_int_distribution<int> d(min_size,max_size);
    int size = d(e);
    std::cout <<"array size is: " <<size <<endl;
    int mSize = 0;
    if (half) {
        mSize = size/2 + 1;
    } else {
        std::uniform_int_distribution<int> d2(size/2 + 1,max_size);
        mSize = d2(e);
    }
    std::cout <<"majority size is: " <<mSize <<endl;
    std::uniform_int_distribution<int> d3(1,size - mSize);
    
    vector<int> v(size, majority);
    for (int i = mSize; i < size; ++i) {
        v[i] = d3(e);
    }

    std::shuffle(v.begin(), v.end(), e);

    std::cout <<"generated input is: " <<endl <<"  ";
    vector<int>::const_iterator iter = v.begin();
    while(iter != v.end()) {
        std::cout <<*(iter++) <<" ";
    }
    std::cout<<endl;

    return v;
}

TEST(Problem169Test, Test1) {
    vector<int> v;
    for(int i = 0; i < 6; ++i) {
        v = generateInput(-1);
        Solution s;
        EXPECT_EQ(majority, s.majorityElement(v));
    }

    std::cout <<"--- 'half' cases --- " <<endl;
    for(int i = 0; i < 6; ++i) {
        v = generateInput(true);
        Solution s;
        EXPECT_EQ(majority, s.majorityElement(v));
    }

}
