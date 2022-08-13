#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,h,m;
        cin>>n>>h>>m;
        vector<pair<int,int>> vp;
        for(int i=0; i<n; i++){
            int th,tm;
            cin>>th;
            cin>>tm;
            vp.push_back(make_pair(th,tm));

        }

        sort(vp.begin(),vp.end());

        bool found=false;
        int nexth,nextm;
        int i=0;
        for(i=0; i<n; i++){
            if(vp[i].first >= h){
                found=true;
                nexth=vp[i].first;
                nextm=vp[i].second;
                break;
            }
        }

        int ansh,ansm;
        if(found==true){
            if(m==0 || vp[i].first==h){
                ansh = vp[i].first-h;
                ansm = vp[i].second-m;
            }
            else{
                ansh = vp[i].first-h-1;
                ansm = 60 - m + vp[i].second;
            }

        }
        else{
            if(m==0){
                ansh = 24 - h + vp[0].first;
                ansm = vp[0].second;
            }
            else{
                ansh = 24 - h -1 + vp[0].first;
                ansm = 60 - m + vp[0].second;
            }
        }
        if(ansm >= 60){
            ansh++;
            ansm-=60;
        }
        cout<<ansh<<" "<<ansm<<endl;    


    }
    
}