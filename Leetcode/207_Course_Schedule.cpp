// uncommented code --> uses dfs
// commented code --> uses bfs
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

// Using BFS
/*
class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false); // ith index denote that ith node is once visited
        
        vector<int> adj[numCourses];
        for(size_t i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
//             dir v --> u
                adj[v].push_back(u);
        }
        
        vector<int> indegree(numCourses,0); // stores indegree of each vertices.
	    
	    // find indegree of each node on initial configuration
	    for(int i=0; i<numCourses; i++){
	        for(int j=0; j<adj[i].size(); j++){
	            indegree[adj[i][j]]++;
	        }
	    }
	    
	    // kind of multi source bfs algo
	    // at start add node into queue whose indegree is zero.
	    queue<int> qq;
	    for(int i=0; i<numCourses; i++){
	        if(indegree[i] == 0){
	            qq.push(i);
	        }
	    }
	    
	    vector<int> ans;
	    
	    while(!qq.empty()){
	        int node = qq.front();
	        ans.push_back(node);
	        qq.pop();
	        
	        for(auto it: adj[node]){
	            // decrease indegree of adj node's 
	            //and if updated indegree is zero then add it into queue
	            if(--indegree[it] == 0) qq.push(it); 
	        }
	    }
    
        if(ans.size() == numCourses) // toposort has all vertices so no cycle
            return true;
        else return false;
        
        
    }
};
*/