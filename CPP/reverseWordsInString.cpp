// https://www.interviewcake.com/question/cpp/reverse-words?course=fc1&section=array-and-string-manipulation
#include <iostream>
#include <string>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

void reverseCharacters(string &message, int prev, int curr){
    while(prev<curr){
        swap(message[prev],message[curr]);
        prev++;
        curr--;
    }
}

void reverseWords(string& message)
{
    // decode the message by reversing the words
    reverse(message.begin(),message.end());
    
    size_t len=message.length();
    int prevPos=0;
    for(int currPos=0; currPos<=message.length(); currPos++){
        if(currPos==message.length() || message[currPos]==' '){
            reverseCharacters(message,prevPos,currPos-1);
            prevPos = currPos +1;
        }
    }


}



// tests

const lest::test tests[] = {
    {CASE("one word") {
        const string expected = "vault";
        string actual = "vault";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("two words") {
        const string expected = "cake thief";
        string actual = "thief cake";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("three words") {
        const string expected = "get another one";
        string actual = "one another get";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("multiple words same length") {
        const string expected = "the cat ate the rat";
        string actual = "rat the ate cat the";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("multiple words different lengths") {
        const string expected = "chocolate bundt cake is yummy";
        string actual = "yummy is cake bundt chocolate";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("empty string") {
        const string expected;
        string actual;
        reverseWords(actual);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}