#include<bits/stdc++.h>
using namespace std;

void solve(int src, int par, vector<int> &ans, vector<int> tree[]){
    int subords = 0;

    for(int child: tree[src]){
        if(child != par){
            solve(child, src, ans, tree);
            subords += (1 + ans[child]);
        }
    }
    ans[src] = subords;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    // cin>>n;
    t=1;
    while(t--){
        int n;
        cin>>n;
        vector<int> ans(n+1);
        vector<int> tree[200001];

        for(int i=2; i<n+1; i++){
            int x;
            cin>>x;
            tree[x].push_back(i);
            tree[i].push_back(x);
        }
        solve(1, 0, ans, tree);
        
        for(int i=1; i<n+1; i++){
            cout<<ans[i]<<" ";
        }
    }
    
    
    
    return 0;
}