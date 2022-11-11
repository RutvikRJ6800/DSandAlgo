class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> qq;
        int nonRottenInitial = 0, nonRottenAfter = 0;
        int maxTime = INT_MIN;
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
         
        for(int i=0; i<grid.size(); i++){
            
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) nonRottenInitial++;
                else if(grid[i][j] == 2){
                    qq.push(make_pair(make_pair(i,j),0));
                }
            }
        }
        
        if(nonRottenInitial == 0) return 0;
        
        while(!qq.empty()){
            int i = qq.front().first.first;
            int j = qq.front().first.second;
            int currMax = qq.front().second;
            
            qq.pop();
            
            if(maxTime<currMax) maxTime = currMax;
            
            for(int k=0;k<4;k++){
                int newI = i + dx[k];
                int newJ = j + dy[k];
                
                if(0<=newI && newI < m && 0<=newJ && newJ<n && grid[newI][newJ] == 1){
                    qq.push(make_pair(make_pair(newI,newJ), currMax+1));
                    grid[newI][newJ] = 2;
                    nonRottenAfter++;
                }
                
                
            }
            
        }
    
        
        if(nonRottenInitial == nonRottenAfter){
            return maxTime;
        }
        else{
            return -1;
        }
    }
};