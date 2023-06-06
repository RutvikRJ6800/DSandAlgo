// https://leetcode.com/problems/is-graph-bipartite/description/
class Solution {
public:
    bool startDFS(int node, vector<int>&color, vector<vector<int>>& graph){
        for(auto it: graph[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                bool res = startDFS(it, color, graph);
                if(!res) return false;
            }
            else if(color[node] == color[it]) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                color[i] = 1;
                queue<int> q;
                q.push(i);

                while(!q.empty()){
                    int size = q.size();

                    while(size--){
                        int node = q.front();
                        int c = color[node];
                        q.pop();

                        for(auto adjNode: graph[node]){
                            if(color[adjNode] == -1){
                                color[adjNode] = 1 - c;
                                q.push(adjNode);
                            }
                            else if(color[adjNode] == c){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};