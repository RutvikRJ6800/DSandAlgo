class Solution {
public:
    bool cycle = false;
    void dfsHelper(int start, vector<int> adj[], vector<bool> &visited, vector<bool> &exploring){
        exploring[start] = 1; // start is in the execution stack so mark it as exploring
        
        for(auto it: adj[start]){
            if(exploring[it]==1){ // if any adj node of the curr node is mark as exploring means it is present in current execution stack and that basically form a cycle.
                cycle = true;
            }
            if(!visited[it]){
                visited[it] = 1;
                dfsHelper(it, adj, visited, exploring);
            }
        }
        
        exploring[start] = false; // we now removing start node from the execution stack
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false); // ith index denote that ith node is once visited
        vector<bool> exploring(numCourses, false); // ith index denote that ith node is currentlly in stack if value exploring[i] == 1 else not
        
        vector<int> adj[numCourses];
        for(size_t i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
//             dir v --> u
                adj[v].push_back(u);
        }
        
        
        for(int i=0; i<numCourses; i++){ // loop needed to explore all the nodes of graph
            if(!visited[i]){
                dfsHelper(i, adj, visited, exploring);
            }
        }
        
        // if cycle == true ---> not posible to cover courses
        // if cycle == false ---> we can cover all the courses
        return (!cycle);
        
        
    }
};