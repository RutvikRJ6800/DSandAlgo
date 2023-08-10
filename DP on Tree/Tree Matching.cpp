#include<bits/stdc++.h>
using namespace std;

vector<int> tree[200001];
vector<vector<int>> dp(200001, vector<int>(2, 0));

void solve(int src, int par){
    vector<int> prefix, suffix;
    dp[src][0] = dp[src][1] = 0;
 
    bool leaf = 1;
    for(int child : tree[src])
    {
        if(child != par)
        {
            leaf = 0;
            solve(child, src);
        }
    }
    
    if(leaf) return; // if leaf node then return;
    for(int child: tree[src]){
        if(child != par){
            prefix.push_back(max(dp[child][0], dp[child][1]));
            suffix.push_back(max(dp[child][0], dp[child][1]));
        }
    }
    
    for(int i=1; i<(int)prefix.size(); i++)
        prefix[i] += prefix[i-1];
    for(int i = (int)suffix.size() - 2; i >= 0; i--)
        suffix[i] += suffix[i+1];

    dp[src][0] = suffix[0];
    
    int c_no = 0;
    for(int child : tree[src])
    {
        if(child == par)continue;
 
        int leftChildren = (c_no == 0) ? 0 : prefix[c_no - 1];
        int rightChildren = (c_no == (int)suffix.size() - 1) ? 0 : suffix[c_no + 1];
 
        dp[src][1] = max(dp[src][1], 1 + leftChildren + rightChildren + dp[child][0]);
        c_no++;
    }
    // cout<<"Node: "<<src<<", Par: "<<par<<": take:"<<dp[src][1]<<": not take:"<<dp[src][0]<<endl;
    return;

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    // cin>>n;
    t=1;
    while(t--){
        int n;
        cin>>n;


        for(int i=1; i<n; i++){
            int a, b;
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        
        solve(1, 0);
        
        cout<<max(dp[1][0], dp[1][1]);
    }
    
    
    
    return 0;
}

/*
10
1 2
1 3
1 4
2 5
2 6
3 7
3 8
4 9
4 10
*/