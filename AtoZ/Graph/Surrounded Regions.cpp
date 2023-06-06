// https://leetcode.com/problems/surrounded-regions/description/
class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>> &board, vector<vector<bool>> &visited){
        visited[i][j] = 1;

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            if(x >=0 && x < m && y >= 0 && y < n && !visited[x][y] && board[x][y] == 'O'){
                dfs(x, y, m, n, board, visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        for(int i=0; i<m; i++){
            // traverse left border
            if(board[i][0] == 'O' && !visited[i][0]){
                dfs(i, 0, m, n, board, visited);
            }
            // traverse right border
            if(board[i][n-1] == 'O' && !visited[i][n-1]){
                dfs(i, n-1, m, n, board, visited);
            }
        }

        for(int i=0; i<n; i++){
            // traverse left border
            if(board[0][i] == 'O' && !visited[0][i]){
                dfs(0, i, m, n, board, visited);
            }
            // traverse right border
            if(board[m-1][i] == 'O' && !visited[m-1][i]){
                dfs(m-1, i, m, n, board, visited);
            }
        }


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};