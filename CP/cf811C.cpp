#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string ans="";
        map<int,int> m;

        while(n!=0){
            int i=9;
            while(m.find(i)!=0){
                cout<<"size" <<m.size()<<endl;
                i--;
            }
            ans.push_back(i);
            m[i]=1;
            n-=i;
        }
        reverse(ans);
        cout<<ans<<endl;

    }
    return 0;
}