// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int i, int j, int basei, int basej, vector<vector<bool>> &visited, vector<vector<int>> &grid, vector<pair<int, int>> &coords){
        // mark curr (i, j) as visited
        visited[i][j] = 1;

        // remove base x and y from the shape and put into the coords
        coords.push_back({i-basei, j-basej});

        // apply dfs on the adjacent cells
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int k=0; k<4; k++){
            int newx = i + dx[k];
            int newy = j + dy[k];

            if(newx >= 0 && newx < grid.size() && newy >=0 && newy < grid[0].size() && !visited[newx][newy] && grid[newx][newy]){
                dfs(newx, newy, basei, basej, visited, grid, coords);
            }
        }

    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        set<vector<pair<int, int>>> uniqueShape;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j]){
                    vector<pair<int, int>> coords;
                    dfs(i, j, i, j, visited, grid, coords);
                    if(uniqueShape.find(coords) == uniqueShape.end()){
                        uniqueShape.insert(coords);
                    }
                }
            }
        }

        return uniqueShape.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends