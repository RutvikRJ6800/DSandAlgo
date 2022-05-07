#include<bits/stdc++.h>
using namespace std;

int main(){

    while(true){
        string s;
        cin>>s;

        if(s==""){
            break;
        }
        
        char c;
        for(size_t i=0; i<s.size(); i++){
            c = toupper(s[i]);
            cout<<c;
        }
        cout<<endl;

    }
    
    return 0;
}