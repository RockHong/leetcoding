/*
 * Given an input string, reverse the string word by word.
 * 
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * 
 * click to show clarification.
 * 
 * Clarification:
 *   What constitutes a word?
 *     A sequence of non-space characters constitutes a word.
 *   Could the input string contain leading or trailing spaces?
 *     Yes. However, your reversed string should not contain leading or trailing spaces.
 *   How about multiple spaces between two words?
 *     Reduce them to a single space in the reversed string.
 */

#include "gtest/gtest.h"
#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s);

        int tokenBeg;
        int tokenEnd;
        int pos = 0;
        while (findToken(s, pos, tokenBeg, tokenEnd)) {
            reverse(s, tokenBeg, tokenEnd);
            pos = tokenEnd;
        }

        // trim
        trim(s);
    }

    void trim(string &s) {
        int tokenBeg;
        int tokenEnd;
        int nextToken = 0; // the scanning start point for next token
        int moved = 0;
        while (findToken(s, nextToken, tokenBeg, tokenEnd)) {
            if (moved != tokenBeg) {
                shift(s, tokenBeg - moved, moved, tokenBeg, tokenEnd - tokenBeg);
            }

            moved = moved + (tokenEnd - tokenBeg) + 1;
            nextToken = tokenEnd;
        }

        int i = 0;
        int size = s.size();
        i = size - 1;
        while (i >= 0 && s[i] == ' ') {
            s.pop_back();
            i--;
        }
    }

    void shift(string &s, int distance, int pos1, int pos2, int len) {
        if (distance <= 0) {
            return;
        }
        
        for (int i = 0; i < len; ++i) {
            s[pos1 + i] = s[pos2 + i];
            s[pos2 + i] = ' ';
        }
    }

    void reverse(string &s) {
        reverse(s, 0, s.size());
    }

    void reverse(string &s, int beg, int end) {
        int size = end - beg;
        int mid = size/2;
        for (int i = 0; i < mid; ++i) {
            int pos1 = beg + i;
            int pos2 = beg + size - 1 - i;
            auto tmp = s[pos1];
            s[pos1] = s[pos2];
            s[pos2] = tmp;
        }
    }

    // token is [beg, end)
    bool findToken(const string &s, int start, int &beg, int &end) {
        int i = start;
        int size = s.size();
        
        while (i < size && s[i] == ' ') i++;
        beg = i;

        while (i < size && s[i] != ' ') i++;
        end = i;

        if (beg == size) {
            return false;
        }
        return true;
    }
};

// tests begin
TEST(Problem151Test, Test1) {
    Solution s;

    // test building blocks...
    string str = "12345";

    s.reverse(str, 0, str.size());
    EXPECT_EQ("54321", str);

    str = "12345";
    s.reverse(str, 1, 3);
    EXPECT_EQ("13245", str);

    str = "1 ";
    s.reverse(str, 0, str.size());
    EXPECT_EQ(" 1", str);

    str = " 1";
    s.reverse(str, 1, str.size());
    EXPECT_EQ(" 1", str);


    int beg;
    int end;

    str = "123";
    EXPECT_EQ(true, s.findToken(str, 0, beg, end));
    EXPECT_EQ(0, beg);
    EXPECT_EQ(str.size(), end);

    str = " 1";
    EXPECT_EQ(true, s.findToken(str, 0, beg, end));
    EXPECT_EQ(1, beg);
    EXPECT_EQ(str.size(), end);

    str = " 1";
    s.trim(str);
    EXPECT_EQ("1", str);

    // 
    string str0;
    s.reverseWords(str0);
    EXPECT_EQ("", str0);

    string str1("");
    s.reverseWords(str1);
    EXPECT_EQ("", str1);

    string str2("     ");
    s.reverseWords(str2);
    EXPECT_EQ("", str2);

    string str3("the sky is blue");
    s.reverseWords(str3);
    EXPECT_EQ("blue is sky the", str3);

    string str4("   the sky is blue  ");
    s.reverseWords(str4);
    EXPECT_EQ("blue is sky the", str4);

    string str5("1 ");
    s.reverseWords(str5);
    EXPECT_EQ("1", str5);

    string str6("  1   2   ");
    s.reverseWords(str6);
    EXPECT_EQ("2 1", str6);
}
