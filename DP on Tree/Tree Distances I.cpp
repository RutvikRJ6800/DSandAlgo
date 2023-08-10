#include<bits/stdc++.h>
using namespace std;

vector<int> tree[200001];
// vector<vector<int>> dp(200001, vector<int>(2, 0));
int finalAns = 0;
void dfs(int src, int par, vector<int> &arr1, int currDist){
    arr1[src] = currDist;

    for(int child: tree[src]){
        if(child != par){
            dfs(child, src, arr1, currDist + 1);
        }
    }
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
        
        vector<int> arr1(n+1), distWith1(n+1), distWith2(n+1), ans(n+1);
        dfs(1, 0, arr1, 0);

        int end1 = -1, dist = INT_MIN;
        for(int i=0; i<arr1.size(); i++){
            if(dist<arr1[i]){
                dist = arr1[i];
                end1 = i;
            }
        }

        // cout<<arr1.size();

        dfs(end1, 0, distWith1, 0);
        int end2 = -1;
        dist = INT_MIN;
        for(int i=0; i<distWith1.size(); i++){
            if(dist<distWith1[i]){
                dist = distWith1[i];
                end2 = i;
            }
        }


        dfs(end2, 0, distWith2, 0);
        for(int i=1; i<distWith2.size(); i++){
            cout<<max(distWith1[i], distWith2[i])<<" ";
        }

        
    }
    return 0;
}
