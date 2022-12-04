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


/*
// using DFS
class Solution {
public:
    bool startDFS(int node, vector<int>&color, vector<vector<int>>& graph){
        for(auto it: graph[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node]; // color with contradict color to node
                bool res = startDFS(it, color, graph);
                if(!res) return false; // if found odd length cycle then return false;
            }
            else if(color[node] == color[it]) return false;
        }
        
        return true; // no odd length cycle found so return true.
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        
        for(int i=0; i<V; i++){
            if(color[i]==-1){
                color[i] = 1;
                bool res = startDFS(i, color, graph);
                if(!res) return false;
            }
        }
        
        return true;
    }
};

*/