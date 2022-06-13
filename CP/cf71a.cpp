#include<bits/stdc++.h>
using namespace std;


int main(){
   
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string ans;
        if(s.size()<=10){
            cout<<s<<endl;
        }
        else{
            int i=0,cnt=0;
            while(i<s.size()-1){
                if(i==0){
                    ans.push_back(s[i]);
                }
                else{
                     cnt++;
                }
                i++;
            }
            string num="";
            while(cnt){
                num.push_back(cnt%10+'0');
                cnt /=10;
            }
            reverse(num.begin(),num.end());
            ans=ans+num;
            ans.push_back(s[i]);
            cout<<ans<<endl; 
        }
    }
    
}