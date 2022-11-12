class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // create visited matrix;
        vector<vector<bool>> visited(m, vector<bool>(n,0));
        int connectedComp = 0;
        
         int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((visited[i][j] == 0) && (grid[i][j] == '1')){
                    // cout<<i<<j<<endl;
                    connectedComp++;
                    // apply bfs traversal starting from this node
                    
                    // initialiase que for bfs
                    queue<pair<int,int>> qq;
                    qq.push(make_pair(i,j));
                    visited[i][j] = 1;
                    
                    while(!qq.empty()){
                        int x = qq.front().first;
                        int y = qq.front().second;
                        // cout<<"Qx"<<i<<"QY"<<j<<endl;
                        qq.pop();
                        
                        for(int k=0; k<4; k++){
                            int newX = x + dx[k];
                            int newY = y + dy[k];
                            // cout<<"Newx"<<newX<<"newY"<<newY<<endl;
                            
                            if(newX >=0 && newX<m && newY>=0 && newY<n && grid[newX][newY] == '1' && visited[newX][newY] == 0){
                                // cout<<"kx:"<<newX<<" kY:"<<newY<<endl;
                                visited[newX][newY] = 1;
                                qq.push(make_pair(newX, newY));
                            }
                        }
                    }
                    
                }
            }
        }
        
        return connectedComp;
        
    }
};