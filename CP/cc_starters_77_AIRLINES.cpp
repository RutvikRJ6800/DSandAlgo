#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, z;
        cin>>x>>y>>z;
        int capacity = 10 * x;

        if(y > capacity){
            cout<<(capacity*z)<<endl;
        }
        else{
            cout<<(y*z)<<endl;
        }

    }
    return 0;
}