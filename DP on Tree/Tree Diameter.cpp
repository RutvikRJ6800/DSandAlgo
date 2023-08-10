#include<bits/stdc++.h>
using namespace std;

vector<int> tree[200001];
// vector<vector<int>> dp(200001, vector<int>(2, 0));
int finalAns = 0;
int solve(int src, int par){
    vector<int> children, suffix;
    bool leaf = 1;
    for(int child : tree[src])
    {
        if(child != par)
        {
            leaf = 0;
            int ans = solve(child, src);
            if(ans != 0){
                children.push_back(ans);
            }
        }
    }
    if(leaf) return 1;

    if(children.size()==1){
        finalAns = max(finalAns, children[0]);
        return 1 + children[0];
    }
    else if(children.size() == 2){
        finalAns = max(finalAns, children[0] + children[1]);
        return 1 + max(children[0], children[1]);
    }
    else{
        int firstMax = INT_MIN, secondMax = INT_MIN;

        for(int i=0; i<children.size(); i++){
            if(firstMax < children[i]){
                secondMax = firstMax;
                firstMax = children[i];
            }
            else if(secondMax < children[i]){
                secondMax = children[i];
            }
        }
        finalAns = max(finalAns, secondMax + firstMax);
        return 1 + max(firstMax, secondMax);
    }


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
        cout<<finalAns;
    }
    return 0;
}
