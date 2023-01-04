// https://leetcode.com/problems/possible-bipartition/description/
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for(int i=0; i<dislikes.size(); i++){
            
            int p1 = dislikes[i][0]-1, p2 = dislikes[i][1]-1;
            adj[p1].push_back(p2);
            adj[p2].push_back(p1);
        }

        vector<int> color(n, -1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                color[i] = 0;
                queue<int> q;
                q.push(i);

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto it: adj[node]){
                        if(color[it] == -1){
                            // adj node it is not colored yet;
                            color[it] =  1 - color[node];
                            q.push(it);
                        }
                        else if(color[it] == color[node]) return false;
                    }
                }
            }
        }


        return true;
    }
};