#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int n,temp;
    cin>>n;
    temp=n;
    vector<int> v(n);
    map<int,int> m;
    for(int i=0;i<n; i++){
        int inp;
        cin>>inp;
        v.push_back(inp);
        m[inp]++;
    }

    int res=0;

    while(temp>(n/2)){
        res++;
        int max=-9999,maxI=-1;

        for(int i=0; i<m.size(); i++){
            if(max<m[i]){
                max=m[i];
                maxI=i;
            }
        }
        temp= temp-max;
        m.erase(max);
        cout<<"temp: "<<temp<<"n: "<<n<<endl;
    }
    cout<<res;
    return 0;
}
