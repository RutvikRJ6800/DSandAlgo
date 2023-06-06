// https://leetcode.com/problems/number-of-enclaves/description/
class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<bool>> &visited, vector<vector<int>>& grid){
        visited[i][j] = 1;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            if(x >=0 && x < m && y >= 0 && y < n && !visited[x][y] && grid[x][y] == 1){
                dfs(x, y, m, n, visited, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        for(int i=0; i<m; i++){
            if(grid[i][0] == 1){
                dfs(i, 0, m, n, visited, grid);
            }

            if(grid[i][n-1] == 1){
                dfs(i, n-1, m, n, visited, grid);
            }
        }

        for(int i=0; i<n; i++){
            if(grid[0][i] == 1){
                dfs(0, i, m, n, visited, grid);
            }

            if(grid[m-1][i] == 1){
                dfs(m-1, i, m, n, visited, grid);
            }
        }

        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // cout<<visited[i][j]<<", ";
                if(grid[i][j] == 1 && !visited[i][j]){
                    cnt++;
                }
            }
            // cout<<endl;
        }

        
        return cnt;
    }
};