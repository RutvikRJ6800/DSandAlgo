bool solve(int x, int y, vector<vector<char>>& board, map<char,int> row[],map<char,int> col[],map<char,int> sub[]){
        if(x==9 && y == 0)return true;
//         if shell is vacant
        
        else if(board[x][y]=='.'){
            for(char i='1'; i<='9';i++){
                if(sub[x/3*3 + y/3][i]==1){cout<<"a"<<endl;continue;}
                else if(row[x][i]==1){cout<<"b"<<endl;continue;}
                else if(col[y][i]==1){cout<<"c"<<endl;continue;}
                else{//we can put i here in the shell 
                    board[x][y]=i;
                    
                    cout<<"x: "<<x<<"y: "<<y<<"i="<<i<<endl;
                    
                    sub[x/3*3 + y/3][i]=1;
                    row[x][i]=1;
                    col[y][i]=1;
                    
                    bool ans;
                    if(y==8){
                        ans=solve(x+1,(y+1)%9,board, row, col, sub);
                    }
                    else{
                        ans=solve(x,(y+1)%9,board, row, col, sub);
                    }
                    if(ans==true)return true;
                    
                    board[x][y]='.';
                    
                    sub[x/3*3 + y/3][i]=0;
                    row[x][i]=0;
                    col[y][i]=0;
                    
                    
                }
            }
            return false;
        }
        else{
            bool ans;
            if(y==8){
                ans=solve(x+1,(y+1)%9,board, row, col, sub);
            }
            else{
                ans=solve(x,(y+1)%9,board, row, col, sub);
            }
            if(ans==true)return true;
            else return false;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
//         preset maps
        map<char,int> row[9], col[9], sub[9];
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    sub[i/3*3 + i/3][board[i][j]]=1;
                    row[i][board[i][j]]=1;
                    col[j][board[i][j]]=1;
                }
            }
        }
        
        solve(0,0,board, row, col, sub);
    
        // call fun
    }


int main()