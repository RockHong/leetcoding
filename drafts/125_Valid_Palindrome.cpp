/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * 
 * For example,
 *     "A man, a plan, a canal: Panama" is a palindrome.
 *     "race a car" is not a palindrome.
 * 
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 * For the purpose of this problem, we define empty string as valid palindrome.
 */

#include "gtest/gtest.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        return Palindrome_1(s);
    }
    
    // way 1
    bool isPalindrome_1(string s) {
        if (s.empty()) {
            return true;
        }

        auto iter = s.begin();
        // iterator and reverse_iterator cannot compare with each other "easily"
        // auto riter = s.rbegin();
        auto riter = --s.end();

        while (iter < riter) {
            if (!isAlphaNum(*iter)) {
                iter++;
                continue;
            }
            if (!isAlphaNum(*riter)) {
                //riter++;
                riter--;
                continue;
            }
            if (!isEqual(*iter,  *riter)) {
                return false;
            }
            iter++;
            //riter++;
            riter--;
        }
        return true;
    }

    bool isAlphaNum(string::const_reference c) {
        static const int a = static_cast<int>('a');
        static const int z = static_cast<int>('z');
        static const int A = static_cast<int>('A');
        static const int Z = static_cast<int>('Z');
        static const int ZERO = static_cast<int>('0');
        static const int NINE = static_cast<int>('9');
        
        int cint = static_cast<int>(c);

        if (cint >= a && cint <= z) {
            return true;
        }
        if (cint >= A && cint <= Z) {
            return true;
        }
        if (cint >= ZERO && cint <= NINE) {
            return true;
        }
        return false;
    }

    bool isEqual(string::const_reference c1, string::const_reference c2) {
        static const int a = static_cast<int>('a');
        static const int A = static_cast<int>('A');
        static const int Z = static_cast<int>('Z');
        static const int delta = A - a;

        if (c1 == c2) {
            return true;
        }

        if (c1 >= A && c1 <= Z) {
            return c1 - delta == c2;
        }

        if (c2 >= A && c2 <= Z) {
            return c2 -delta == c1;
        }

        return false;
    }

    // way 2, use a stack and a queue
};

// tests begin
// ""
// "aa"
// "aba"
// "aA"
// "123"
