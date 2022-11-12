class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 means not colored yet;
        
        
        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                queue<int> qq;
        
                qq.push(i);
                color[i] = 0;

                while(!qq.empty()){
                    int node = qq.front();
                    qq.pop();

                    for(auto it: graph[node]){
                        if(color[it] == -1){
                            color[it] = (color[node] == 0 ? 1:0);
                            qq.push(it);
                        }
                        else if(color[it] == color[node]){
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
        
    }
};