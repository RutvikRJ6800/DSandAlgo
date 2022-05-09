#include<bits/stdc++.h>
using namespace std;

bool validSuffle(string x, string y, string z){
// approch using freq map
    unordered_map<char,int> m;
    if(x.size()+y.size()!=z.size()){
        return false;
    }

    for(size_t i=0; i<x.size(); i++){
        m[x[i]]++;
    }

    for(size_t i=0; i<y.size(); i++){
        m[y[i]]++;
    }

    for(size_t i=0; i<z.size(); i++){
        --m[z[i]];
    }

    for(auto i=m.begin(); i!=m.end(); i++){
        if(i->second != 0){
            return false;
        }
    }
    return true;



    // sorting approch
    // if(x.size()+y.size()!=z.size()){
    //     return false;
    // }

    // sort(x.begin(),x.end());
    // sort(y.begin(),y.end());
    // sort(z.begin(),z.end());

    // int i=0,j=0,k=0;
    // while(k<z.size()){
    //     if(i<x.size() && x[i]==z[k]){
    //         i++;
    //         k++;
    //     }
    //     else if(j<y.size() && y[j]==z[k]){
    //         j++;
    //         k++;
    //     }
    //     else{
    //         return false;
    //     }
    // }
    // return true;
}

int main(){

    cout<<validSuffle("XY","12","Y21Y");//0
    cout<<validSuffle("XY","12","1XY2");//1
    cout<<validSuffle("XY","12","Y1X2");//1
    return 0;
}