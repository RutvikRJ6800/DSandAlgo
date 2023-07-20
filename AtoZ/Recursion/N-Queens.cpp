// https://leetcode.com/problems/n-queens/description/
class Solution {
public:
    bool isSafe(int n, int row, int col, vector<string> &board,vector<bool> &colMap, vector<bool> &topleftMap, vector<bool> &toprightMap){
        if(!colMap[col] && !topleftMap[row + col] && !toprightMap[(n-1) + (row-col)]) return true;
        else return false;
    }
    void solve(int n, int row, vector<string> &board, vector<vector<string>> &ans,vector<bool> &colMap, vector<bool> &topleftMap, vector<bool> &toprightMap){
        if(row == n){
            ans.push_back(board);
        }
        else{
            for(int col=0; col<n; col++){
                if(isSafe(n, row, col, board,colMap, topleftMap, toprightMap)){
                    // put q here
                    board[row][col] = 'Q';
                    colMap[col] = 1;
                    topleftMap[row + col] = 1;
                    toprightMap[(n-1) + (row-col)] = 1;

                    solve(n, row+1, board, ans, colMap, topleftMap, toprightMap);

                    // take out q;
                    board[row][col] = '.';
                    colMap[col] = 0;
                    topleftMap[row + col] = 0;
                    toprightMap[(n-1) + (row-col)] = 0;
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        vector<bool> colMap(n, 0);
        vector<bool> topleftMap(2*n - 1, 0);
        vector<bool> toprightMap(2*n - 1, 0);
        string s(n, '.');

        for(int i=0; i<n; i++){
            board[i] = s;
        }

        solve(n, 0, board, ans, colMap, topleftMap, toprightMap);

        return ans;
    }
};