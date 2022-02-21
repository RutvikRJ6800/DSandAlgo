// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4332/0000000000942404
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fun(vector <int> &vec, int m){
    
    int sum=0;
    
    size_t len = vec.size();
    
    for(size_t i=0; i<len; i++){
        
        sum += vec[i];
        
    }
    
    int res = sum%m;
    
    return res;
    
}

int main() {
    
    int t,r;
    r=1;
    cin>>t;
    while(t--){
        
        int n,m;
        cin>>n;
        cin>>m;
        vector <int> candy(n);
        for(int i=0; i<n; i++){
            cin>>candy[i];
        }
        
        int result =fun(candy,m);
        cout<<"Case #"<<r<<": "<<result<<endl;
        r++;

   }
    
    return 0;
  
}