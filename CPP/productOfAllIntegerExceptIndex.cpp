// https://www.interviewcake.com/question/cpp/product-of-other-numbers?course=fc1&section=greedy
#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& intVector)
{
    // make a vector with the products
    
    if(intVector.size()<2){
        throw invalid_argument("vector sould be of size 2 atlest");
    }
    
    vector<int> vec(intVector);
    
    for(size_t i = 0; i<intVector.size(); i++){
        
        int product = 1;
        
        for(size_t j =0; j<intVector.size(); j++){
            
            if(i==j)
            continue;
            
            else{
                product *= intVector[j];
            }
            
        }
        
        vec[i]=product;
    }
    

    return vec;
}


// tests

const lest::test tests[] = {
    {CASE("small vector") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({1, 2, 3});
        const auto expected = vector<int> {6, 3, 2};
        EXPECT(actual == expected);
    }},

    {CASE("longer vector") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({8, 2, 4, 3, 1, 5});
        const auto expected = vector<int> {120, 480, 240, 320, 960, 192};
        EXPECT(actual == expected);
    }},

    {CASE("vector has one zero") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({6, 2, 0, 3});
        const auto expected = vector<int> {0, 0, 36, 0};
        EXPECT(actual == expected);
    }},

    {CASE("vector has two zeros") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({4, 0, 9, 1, 0});
        const auto expected = vector<int> {0, 0, 0, 0, 0};
        EXPECT(actual == expected);
    }},

    {CASE("one negative number") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({-3, 8, 4});
        const auto expected = vector<int> {32, -12, -24};
        EXPECT(actual == expected);
    }},

    {CASE("all negative numbers") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({-7, -1, -4, -2});
        const auto expected = vector<int> {-8, -56, -14, -28};
        EXPECT(actual == expected);
    }},

    {CASE("error with empty vector") {
        EXPECT_THROWS(getProductsOfAllIntsExceptAtIndex({}));
    }},

    {CASE("error with one number") {
        EXPECT_THROWS(getProductsOfAllIntsExceptAtIndex({1}));
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}