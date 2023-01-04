class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<vector<int>>& graph, int node, vector<int> &currPath){
        currPath.push_back(node); // add this node to path
        if(node == graph.size()-1){ // 
            ans.push_back(currPath); // add path  to ans if this node is the last node
        }
        else{
            vector<int> v = graph[node];

            for(int i=0; i<v.size(); i++){ // else start traversing dfs way for all adj node of this node
                dfs(graph, v[i], currPath);
            }
        }

        currPath.pop_back();


    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v = graph[0];
        vector<int> currPath;
        currPath.push_back(0);
        for(int i=0; i<v.size(); i++){   // start dfs travesal from all adj of 0 node
            dfs(graph, v[i], currPath);
        }

        return ans;
    }
};