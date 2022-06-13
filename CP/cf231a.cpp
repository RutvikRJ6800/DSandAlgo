#include<bits/stdc++.h>
using namespace std;


int main(){
   
    int t,ans=0;
    vector<vector<int>> vec;
    cin>>t;
    while(t--){
        vector<int> v(3);
        cin>>v[0]>>v[1]>>v[2];
        int cnt=0;
        for(int i=0; i<v.size(); i++){
            if(v[i]==1){
                cnt++;
            }
        }
        if(cnt>=2){
            ans++;
        }
    }
    cout<<ans<<endl;
}