#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;
    int i=0,l = s.size();
    stack<char> st;
    while(i<l){
        if(s[i]>='a' && s[i]<='z'){
            i++;
        }
        else{
            if(s[i]==')'){
                if(!st.empty() && st.top()=='(')st.pop();
                else{
                    st.push(')');
                }
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            i++;
        }
    }
    
    int second = st.size();
    int first = 0;
    for(i=0; i<l; i++){
        if(s[i]=='(' || s[i]==')'){
            first++;
        }
    }
    first = first-second;
    cout<<first<<" "<<second;
    return 0;
}
