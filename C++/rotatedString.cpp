// Write a Code to check whether one string is a rotation of another
// 
#include<bits/stdc++.h>
using namespace std;

bool rotatedString(string s, string goal){
// KMP algorithm
    if(s.size()!=goal.size()){
        return false;
    }

    string temp=s+s;
    if(temp.find(goal)!=string::npos){
        return true;
    }
    return false;





// queue approch
    // if(s.size()!=goal.size()){
    //     return false;
    // }

    // queue<char> q,q1;
    // for(int i=0; i<s.size(); i++){
    //     q.push(s[i]);
    //     q1.push(goal[i]);
    // }

    // int i=0;
    // while (i<s.size())
    // {
    //     if(q==q1){
    //         return true;
    //     }
    //     char c=q.front();
    //     q.pop();
    //     q.push(c);
    //     i++;
    // }

    return false;


    // substring approach
    // if(s==goal){
    //     return true;
    // }

    // int i=1;
    // int n=s.size();
    // while(i<n-1){
    //     s = s.substr(1) + s[0];
    //     i++;
    //     if(s==goal){
    //         return true;
    //     }
    // }
    // return false;

}


int main(){

    cout<<rotatedString("abcde","cdeab");
    // cout<<rotatedString("abcde","cdebb");
    return 0;
}