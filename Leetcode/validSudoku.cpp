class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<int> num(10,0);
        for(int i=0; i<9; i++){
            
            for(int j=0; j<9; j++){
//                 thid shell is starting of the subsudoku
                if((i%3==0) && (j%3==0)){
                    for(int m=1; m<num.size(); m++)num[m]=0;            
                    for(int m=i;m<i+3; m++){
                        for(int n=j; m<j+3; n++){
                            if(board[m][n]!='.')num[board[m][n]-'0']++;
                        }
                    }
                }
                
                if(board[i][j]=='.')continue;
                else if(num[board[i][j]-'0']>1)return false;
                else{
//                     check row 
                    for(int m=0; m<9; m++){
                        if(board[i][m]=='.')continue;
                        if(j!=m && (board[i][j]-'0')==(board[i][m]-'0'))return false;
                    
                    }
                    // check col 
                    for(int m=0; m<9; m++){
                        if(board[m][j]=='.')continue;
                        if(j!=m && (board[i][j]-'0')==(board[m][j]-'0'))return false;
                    
                    }
                }
                
                
            }
        }
            return true;
    }
};