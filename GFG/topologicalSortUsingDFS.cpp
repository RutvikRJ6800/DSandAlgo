class Solution
{
	public:
	// dfs function
	void dfs(int start, vector<int> adj[], vector<bool> &visited, stack<int> &st){
	    
	    for(auto it: adj[start]){
	        if(!visited[it]){
	            visited[it] = 1;
	            dfs(it, adj, visited, st);
	        }
	    }
	    st.push(start); // after exploring all its adj node push this start node in globalstack
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
		// same like standard dfs algorithm
		// *************************
	    vector<bool> visited(V,0);
	    stack<int> st;
	    
	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            visited[i] = 1;
	            dfs(i, adj, visited, st);
	        } 
	    }
		// *************************
	    
	    vector<int> ans;
	    
	    while(!st.empty()){ // reverse global stack
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};