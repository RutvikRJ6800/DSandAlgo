// https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size(), n = isConnected[0].size();
        vector<int> adjList[m];
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        int cnt = 0;
        vector<int> vis(m, 0);
        for(int i = 0; i<m; i++){
            if(!vis[i]){
                cnt++;
                // do bfs traversal
                
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    for(auto it: adjList[node]){
                        if(!vis[it]){
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
};