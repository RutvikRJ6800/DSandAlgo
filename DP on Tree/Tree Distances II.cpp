#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> tree[200001];
vector<ll> subtreeAns(200001, 0);
vector<ll> subtreeNodes(200001, 0);
vector<ll> ans(200001, 0);
int n;
// vector<vector<int>> dp(200001, vector<int>(2, 0));
void dfs1(int src, int par){
    
    bool leaf = true;
    for(int child: tree[src]){
        if(child != par){
            leaf = false;
            dfs1(child, src);
        }
    }

    if(leaf){
        subtreeAns[src] = 0;
        subtreeNodes[src] = 1;
        return;
    }

    ll currSubtreeAns = 0, currSubtreeNode = 0;
    for(int child: tree[src]){
        if(child != par){
            currSubtreeAns += (subtreeAns[child] + subtreeNodes[child]);
            currSubtreeNode += subtreeNodes[child];
        }
    }

    subtreeAns[src] = currSubtreeAns;
    subtreeNodes[src] = 1 + currSubtreeNode;
    return;
}

void dfs2(int src, int par){
    
    if(par == 0){
        ans[src] = subtreeAns[src];
    }
    else{
        ll partialAns = ans[par] - (subtreeNodes[src] + subtreeAns[src]);
        ans[src] = subtreeAns[src] + partialAns + (n - subtreeNodes[src]);    
    }

    for(int child: tree[src]){
        if(child != par){
            dfs2(child, src);
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
        cin>>n;
        for(int i=1; i<n; i++){
            int a, b;
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        
        dfs1(1, 0);
        dfs2(1, 0);

        for(int i=1; i<=n; i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}
