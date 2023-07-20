// https://practice.geeksforgeeks.org/problems/number-of-islands/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    vector<int> rank, parent;
    public:

    DisjointSet(int V){
        rank.resize(V+1, 0);
        parent.resize(V+1);

        for(int i=0; i<V+1; i++){
            parent[i] = i;
        }
    }

    int findUnionParent(int u){
       if(parent[u] == u)
            return u;
       else
            return parent[u] = findUnionParent(parent[u]);
    }

    void unionByRank(int u, int v){
        int ultimateParentU = findUnionParent(u);
        int ultimateParentV = findUnionParent(v);

        if(ultimateParentU == ultimateParentV) return;

        // do union of u and v
        if(rank[u] < rank[v]){
            parent[ultimateParentU] = ultimateParentV;
        }
        else if(rank[u] > rank[v]){
            parent[ultimateParentV] = ultimateParentU;
        }
        else if(rank[u] == rank[v]){
            parent[ultimateParentV] = ultimateParentU;
            rank[u]++;
        }
    }
};



class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m+1);
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int cnt = 0;
        
        vector<int> ans;
        
        for(auto op: operators){
            int i=op[0], j=op[1];
            
            if(visited[i][j]){
                ans.push_back(cnt);
                continue;
            }
            
            int oldNode = m*i + j;
            cnt++;
            visited[i][j] = 1;
            
            // cout<<"New Node: ("<<i<<","<<j<<")"<<endl;
            
            for(int k=0; k<4; k++){
                int newi = i+dx[k];
                int newj = j+dy[k];
                
                int newNode = m*newi + newj;
                
                if(newi >=0 && newj >=0 && newi < n && newj < m && visited[newi][newj]){
                    // apply merging and reduce size;
                    int parOld = ds.findUnionParent(oldNode);
                    int parNew = ds.findUnionParent(newNode);
                    
                    // cout<<"("<<newi<<","<<newj<<"), oldNodePar: "<<parOld<<", newNodePar: "<<parNew<<endl;
                    if(parOld != parNew){
                        ds.unionByRank(oldNode, newNode);
                        cnt--;
                    }
                    // cout<<"count: "<<cnt<<endl;
                    
                }
            }
            // cout<<cnt<<" ";
            ans.push_back(cnt);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends