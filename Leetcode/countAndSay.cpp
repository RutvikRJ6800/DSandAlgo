// https://leetcode.com/problems/count-and-say/
#include<bits/stdc++.h>
using namespace std;

string count(string s){
    size_t n = s.length();
    size_t i=0;
    string output="";
    int count=0;

    for(i=0; i<n; i++){
        count++;
        // if subsequent chars are not same then break and store frequency and element pair
        if(i==n-1 || s[i]!=s[i+1]){
            output.push_back(count+'0');
            output.push_back(s[i]);
            count =0;
        }

    }
    return output;
    
}

string say(int num){
    if(num==1){
        return "1";
    }
    return count(say(num-1));
}

int main(){

    cout<<say(9);
    return 0;
}