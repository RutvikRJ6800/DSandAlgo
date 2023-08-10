#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> tree[200001];
int dp[200001][20];

void dfs(int src, int par){
    dp[src][0] = par;

    for(int d=1; d<20; d++){
        if(dp[src][d-1] != -1){
            dp[src][d] = dp[dp[src][d-1]][d-1];
        }
        else
        dp[src][d] = -1;
    }

    for(int child: tree[src]){
        if(child != par){
            dfs(child, src);
        }
    }
}

int resolveQuery(int node, int d){
    if(node == -1 || d==0){
        return node;
    }

    for(int i=19; i>=0; i--){
        if(d>=(1<<i)){
            return resolveQuery(dp[node][i], d - (1<<i));
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    // cin>>n;
    t=1;
    while(t--){
        int n, q;
        cin>>n>>q;
        
        for(int i=2; i<=n; i++){
            int a;
            cin>>a;
            tree[i].push_back(a);
            tree[a].push_back(i);
        }
        // cout<<"fun";
        dfs(1, -1);
        // cout<<"here";
        for(int i=0; i<q; i++){
            int a, b;
            cin>>a>>b;
            cout<<resolveQuery(a, b)<<endl;
        }
    }
    return 0;
}
