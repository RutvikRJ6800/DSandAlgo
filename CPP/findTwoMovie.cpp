// https://www.interviewcake.com/question/cpp/inflight-entertainment?course=fc1&section=hashing-and-hash-tables
#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"
#include<bits/stdc++.h>

using namespace std;

bool canTwoMoviesFillFlight(const vector<int>& movieLengths, int flightLength)
{
    // determine if two movies add up to the flight length
    bool status = false;
   // movieLengths.sort(movieLengths.begin(),movieLengths.end());
    unordered_map <int,int> map;
    for(size_t i=0; i<movieLengths.size(); i++){
        map[movieLengths[i]]=map[movieLengths[i]]+1;
    }
    int firstMovieLength,secondMovieLength;
    for(auto it:movieLengths){
        firstMovieLength = it;
        secondMovieLength = flightLength - firstMovieLength;
        if (secondMovieLength == firstMovieLength){
            if((map.find(firstMovieLength))->second>=2){
                status=true;
            }
            continue;
        }
        if(map.find(secondMovieLength)==map.end()){
            continue;
        }
        else{
            status = true;
            break;
        }
    }

    return status;
}

// tests

const lest::test tests[] = {
    {CASE("short flight") {
        const vector<int> movieLengths {2, 4};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 1) == false);
    }},
    {CASE("long flight") {
        const vector<int> movieLengths {2, 4};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == true);
    }},
    {CASE("only one movie half flight length") {
        const vector<int> movieLengths {3, 8};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == false);
    }},
    {CASE("two movies half flight length") {
        const vector<int> movieLengths {3, 8, 3};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == true);
    }},
    {CASE("lots of possible pairs") {
        const vector<int> movieLengths {1, 2, 3, 4, 5, 6};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 7) == true);
    }},
    {CASE("not using first movie") {
        const vector<int> movieLengths {4, 3, 2};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 5) == true);
    }},
    {CASE("multiple movies shorter than flight") {
        const vector<int> movieLengths {5, 6, 7, 8};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 9) == false);
    }},
    {CASE("only one movie") {
        const vector<int> movieLengths {6};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == false);
    }},
    {CASE("no movies") {
        const vector<int> movieLengths;
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == false);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}