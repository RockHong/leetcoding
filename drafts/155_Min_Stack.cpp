/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * 
 *  push(x) -- Push element x onto stack.
 *  pop() -- Removes the element on top of the stack.
 *  top() -- Get the top element.
 *  getMin() -- Retrieve the minimum element in the stack.
 */

// leetcode has strict memory limitation on this problem,
#include "gtest/gtest.h"
#include <iostream>
// Lesson: since we don't want the random-access ability, so use list to save memory
#include <list> 
#include <limits>
#include <tuple>
#include <utility>

using namespace std;

class MinStack {
public:
    void push(int x) {
        if (_v.size() == 0) {
            _v.push_back(x);
            _v.push_back(x); // min
        } else {
            if (x < _v.back()) {
                _v.push_back(x);
                _v.push_back(x); // min
            } else {
                int min = _v.back();
                _v.push_back(x);
                _v.push_back(min);
            }
        }
    }

    void pop() {
        // TODO: what to do if empty?
        if (_v.size() == 0) {
            return;
        }

        _v.pop_back();
        _v.pop_back();
    }

    int top() {
        // TODO: what to do if empty?
        if (_v.size() == 0) {
            return numeric_limits<int>::max();
        }

        auto iter = _v.rbegin();
        return *(++iter);
    }

    int getMin() {
        // TODO: what to do if empty?
        if (_v.size() == 0) {
            return numeric_limits<int>::max();
        }

        return _v.back();
    }
private:
    // list<int> _v;
    // list<int> _minHistory;
    // list<tuple<int, int>> _v;
    // list<pair<int, int>> _v;
    list<int> _v;
};

// tests begin
TEST(Problem155Test, TestPushPop) {
    MinStack s;
    s.push(1);
    EXPECT_EQ(1, s.top());
    
    s.push(2);
    s.pop();
    s.push(3);
    EXPECT_EQ(3, s.top());
}

TEST(Problem155Test, TestGetMin) {
    MinStack s;
    s.push(1);
    EXPECT_EQ(1, s.getMin());

    s.push(2);
    EXPECT_EQ(1, s.getMin());

    s.push(0);
    EXPECT_EQ(0, s.getMin());

    s.pop();
    EXPECT_EQ(1, s.getMin());
}

