// https://www.interviewcake.com/question/cpp/reverse-string-in-place?course=fc1&section=array-and-string-manipulation
include <iostream>
#include <string>
#include <bits/stdc++.h>
// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

void reverse(string& str)
{
    // reverse the input string in place
    
    // reverse(str.begin(),str.end()); OR
    
    if(str.empty()){
        return;
    }
    
    size_t leftIndex =0;
    size_t rightIndex = str.length()-1;
    
    while(leftIndex < rightIndex){
        swap(str[leftIndex],str[rightIndex]);
        leftIndex++;
        rightIndex--;
    }

}

// tests

const lest::test tests[] = {
    {CASE("empty string") {
        const string expected;
        string actual;
        reverse(actual);
        EXPECT(actual == expected);
    }},
    {CASE("single character string") {
        const string expected("A");
        string actual("A");
        reverse(actual);
        EXPECT(actual == expected);
    }},
    {CASE("longer string") {
        const string expected("EDCBA");
        string actual("ABCDE");
        reverse(actual);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}