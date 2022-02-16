#include <iostream>
#include <vector>

// C++11 lest unit testing framework

#include "lest.hpp"

using namespace std;

int highestProductOf3(const vector<int>& vectorOfInts)
{
    // calculate the highest product of three numbers
    if(vectorOfInts.size()<3){
        // return error
        throw invalid_argument("atlease 3  size array required");
    }
    
    int highestProduct3, highestProduct2, lowestProduct2, lowest, highest;
    
    highestProduct2 = vectorOfInts[0]*vectorOfInts[1];
    lowestProduct2 = vectorOfInts[0]*vectorOfInts[1];
    
    lowest = vectorOfInts[0]<vectorOfInts[1]?vectorOfInts[0]:vectorOfInts[1];
    highest = vectorOfInts[0]>vectorOfInts[1]?vectorOfInts[0]:vectorOfInts[1];
    
    highestProduct3 = vectorOfInts[0]*vectorOfInts[1]*vectorOfInts[2];
    
    for(size_t i=2; i<vectorOfInts.size(); i++){
        int current = vectorOfInts[i];
        highestProduct3 = max(max(highestProduct3,current*highestProduct2),current*lowestProduct2);
        
        highestProduct2 = max(max(highestProduct2,current*highest),current*lowest);
        lowestProduct2 = min(min(lowestProduct2,current*highest),current*lowest);
        
        highest = max(highest, current);
        lowest = min(highest, current);
        
        
        
        
    }    
    return highestProduct3;
}


// tests

const lest::test tests[] = {
    {CASE("short vector") {
        const int actual = highestProductOf3({1, 2, 3, 4});
        const int expected = 24;
        EXPECT(actual == expected);
    }},

    {CASE("longer vector") {
        const int actual = highestProductOf3({6, 1, 3, 5, 7, 8, 2});
        const int expected = 336;
        EXPECT(actual == expected);
    }},

    {CASE("vector has one negative") {
        const int actual = highestProductOf3({-5, 4, 8, 2, 3});
        const int expected = 96;
        EXPECT(actual == expected);
    }},

    {CASE("vector has two negatives") {
        const int actual = highestProductOf3({-10, 1, 3, 2, -10});
        const int expected = 300;
        EXPECT(actual == expected);
    }},

    {CASE("vector is all negatives") {
        const int actual = highestProductOf3({-5, -1, -3, -2});
        const int expected = -6;
        EXPECT(actual == expected);
    }},

    {CASE("exception with empty vector") {
        EXPECT_THROWS(highestProductOf3({}));
    }},

    {CASE("exception with one number") {
        EXPECT_THROWS(highestProductOf3({1}));
    }},

    {CASE("exception with two numbers") {
        EXPECT_THROWS(highestProductOf3({1, 1}));
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}