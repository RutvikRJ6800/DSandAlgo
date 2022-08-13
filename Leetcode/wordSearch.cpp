class Solution {
public:
    
    bool fun(vector<vector<char>> &board, string &word, int i, int j,int m, int n, int idx){
        
        // if word's curr idx equal to board's i and j;
        if(board[i][j]==word[idx]){
            // if this curr idx was the last of word then stop rec and return true             
            if(idx == word.size()-1){
                return true;
            }
            
//             else mark * at board's i and j idx and check for other neigbour possitions
            char temp = board[i][j];
            board[i][j]='*';
            if(i+1<m){
                bool res1 = fun(board, word, i+1,j,m,n,idx+1);
                if(res1 == true)return true;
            }
            if(i-1>=0){
                bool res2 = fun(board, word, i-1,j,m,n,idx+1);
                if(res2 == true)return true;
            }
            if(j+1<n){
                bool res3 = fun(board, word, i,j+1,m,n,idx+1);
                if(res3 == true)return true;
            }
            if(j-1>=0){
                bool res4 = fun(board, word, i,j-1,m,n,idx+1);
                if(res4 == true)return true;
            }
            
//             if not any neigbour match further then backtrack and return false
            board[i][j]=temp;
            return false;
        }
        
//         if not match of curr word idx and board's i and j then return false and backtrack.
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
//         start checking from all posible idx pairs until one call return true 
        for(int x=0; x<m; x++){
            for(int y=0; y<n; y++){

                bool res = fun(board, word, x,y,m,n,0);
                if(res==true)return true;    
            }
        }
        return false;
    }
};