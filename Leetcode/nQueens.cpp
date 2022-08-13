class Solution {
public:
    
    bool safe(int n,int row, int col, vector<int> topLeft, vector<int> topRight, vector<int> colVector){
        if(topLeft[n-1 + row-col]==1 || topRight[row+col]==1 || colVector[col]==1){
            return false;
        }
        return true;
    }
    void solver(int row, int n,vector<int> colVector, vector<int>topLeft, vector<int> topRight, vector<string> &board, vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(board);
            return;
        }

        int col=0;
        while(col<n){
            if(safe(n, row, col, topLeft, topRight, colVector)){
                //  set board and vectors
                topRight[col+row]=1;
                topLeft[n-1 + row-col]=1;
                colVector[col]=1;

                // put Queen
                board[row][col]='Q';

                solver(row+1, n, colVector, topLeft, topRight, board, ans);

                board[row][col] = '.';

                // reset board and vectors
                topRight[col+row]=0;
                topLeft[n-1 + row-col]=0;
                colVector[col]=0;
            }
            col++;
        }
    }    
        
    vector<vector<string>> solveNQueens(int n) {
        
        string s(n,'.');
        vector<string> board(n,s);
        vector<vector<string>> ans;
        vector<int> colVector(n,0);
        vector<int> topLeft(2*n -1,0);
        vector<int> topRight(2*n -1,0);

        solver(0,n,colVector,topLeft,topRight,board,ans);
        return ans;
    }
};