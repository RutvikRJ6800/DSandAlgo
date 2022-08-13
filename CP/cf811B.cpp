#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        map<int,int> m;
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        int dlt=0;

        for (int i = n-1; i >=0; i--){
            m[v[i]]++;
            
            if(m[v[i]]>=2){
                dlt = i+1;
                break;
            }
        }
        cout<<dlt<<endl;

    }
}
