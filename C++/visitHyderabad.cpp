#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int fun(string s){
    int start=0,len,maxLength=-1;
    map<char,int> m;
     
    for(int i=0; i<26; i++){
        m['a'+i]=-1;
    }
    
    for(size_t end=0; end<s.size(); end++){
        if(m[s[end]]==-1){
//             char not repeating
            m[s[end]]=end;
            // len = end-start;
            // if(len>maxLength)maxLength=len;
        }
        else{
            start = m[s[end]]+1;
            m[s[end]]=end;
        }
        len = end-start+1;
        if(len>maxLength)maxLength=len;
    }
    if(maxLength==-1)return 1;
    return maxLength;
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;
    cout<<fun(s);
    return 0;
}
