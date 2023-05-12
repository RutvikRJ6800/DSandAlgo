#include<bits/stdc++.h>
using namespace std; 


bool check(int m, string s, string t, int num[]){
    int size = s.size();
    bool mask[size] = {0};
    for(int i=0; i<=m; i++){
        mask[num[i] - 1] = 1;
    }

    string after_deletions = "";
    for(int i=0; i<size; i++){
        if(!mask[i]){
            after_deletions += s[i];
        }
    }

    // check if t is there in s
    int sizep = after_deletions.size();
    int sizet = t.size();

    int i=0, j=0;
    while(i<sizep && j < sizet){
        if(after_deletions[i] == t[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }

    if(j == sizet) return true;
    else return false;
}
int main() 
{ 
    string s, t;
    cin>>s>>t;
    int size = s.size();
    int num[size];

    for(int i = 0; i<size; i++){
        cin>>num[i];
    }
    int l = 0, r = size;
    while(l<=r){
        int m = l + (r-l)/2;
        cout<<m<<endl;
        bool res = check(m, s, t, num);
        if(res){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }

    cout<<"ans:"<<l;

}