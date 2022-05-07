#include<bits/stdc++.h>
using namespace std;



int main(){

    string s;
    cin>>s;
    long long sum = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]>=97 && s[i]<=122){
            sum += s[i] -32;
        }
        else{
            sum -= s[i] + 32;
        }
    }

    for(int i=sum-1 ; i>1; i--){
        if(sum%i ==0){
            cout<<"no prime";
            // return true;
        }
    }
    // return false;
    cout<<"Prime";

    return 0;
}