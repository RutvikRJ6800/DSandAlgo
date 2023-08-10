// https://codeforces.com/contest/161/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> tree[50001];
vector<vector<int>> dp1(50001, vector<int>(501, 0));
vector<vector<int>> dp2(50001, vector<int>(501, 0));
int n, k;
// vector<vector<int>> dp(200001, vector<int>(2, 0));
void dfs1(int src, int par, int dist){
    for(int child: tree[src]){
        if(child != par){
            dfs1(child, src, k);
        }
    }

    dp1[src][0] = 1;

    for(int d=1; d<=dist; d++){
        dp1[src][d] = 0;
        for(int child: tree[src]){
            if(child != par){
                dp1[src][d] += dp1[child][d-1];
            }
        }
    }

    return;
}

void dfs2(int src, int par, int dist){
    
    for(int d=0; d<=dist; d++){
        dp2[src][d] = dp1[src][d];
    }

    if(par != 0){
        dp2[src][1] += dp2[par][0];
        for(int d=2; d<=dist; d++){
            dp2[src][d] += dp2[par][d-1] - dp1[src][d-2];
        }
    }
    
    
    for(int child: tree[src]){
        if(child != par){
            dfs2(child, src, dist);
        }
    }

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    // cin>>n;
    t=1;
    while(t--){
        // int n;
        cin>>n>>k;
        for(int i=1; i<n; i++){
            int a, b;
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        
        dfs1(1, 0, k);
        dfs2(1, 0, k);

        ll sum = 0;
        for(int i=1; i<=n; i++){
            sum += dp2[i][k];
        }

        cout<<sum/2;
    }
    return 0;
}
