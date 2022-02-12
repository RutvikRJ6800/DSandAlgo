// https://www.interviewcake.com/question/cpp/permutation-palindrome?course=fc1&section=hashing-and-hash-tables
#include <iostream>
#include <string>

// C++11 lest unit testing framework
#include "lest.hpp"
#include<bits/stdc++.h>

using namespace std;

bool hasPalindromePermutation(const string& str)
{
    // check if any permutation of the input is a palindrome
    unordered_set <char> alphabets;
    int unseenAlphabets = 0;
    for(auto a:str){
        if(alphabets.find(a)==alphabets.end()){
            alphabets.insert(a);
            unseenAlphabets++;
        }
        else{
            unseenAlphabets--;
        }
    }
    if(abs(unseenAlphabets)>1){
        return false;
    }
    else{
        return true;
    }

}


















// tests

const lest::test tests[] = {
    {CASE("permutation with odd number of chars") {
        const auto result = hasPalindromePermutation("aabcbcd");
        EXPECT(result == true);
    }},
    {CASE("permutation with even number of chars") {
        const auto result = hasPalindromePermutation("aabccbdd");
        EXPECT(result == true);
    }},
    {CASE("no permutation with odd number of chars") {
        const auto result = hasPalindromePermutation("aabcd");
        EXPECT(result == false);
    }},
    {CASE("no permutation with even number of chars") {
        const auto result = hasPalindromePermutation("aabbcd");
        EXPECT(result == false);
    }},
    {CASE("empty string") {
        const auto result = hasPalindromePermutation("");
        EXPECT(result == true);
    }},
    {CASE("one character string") {
        const auto result = hasPalindromePermutation("a");
        EXPECT(result == true);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}