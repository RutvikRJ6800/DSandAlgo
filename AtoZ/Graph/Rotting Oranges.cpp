// https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = -1;
        int m = grid.size(), n = grid[0].size();
        int nonrottenInitial = 0, nonrotttenAfter = 0;

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
                
        queue<pair<int, int>> q;

        for(int i = 0; i< m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) nonrottenInitial++;
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            cnt++;

            while(size--){
                auto [x, y] = q.front();
                q.pop();

                for(int k=0 ; k<4; ++k){
                    int newx = x + dx[k];
                    int newy = y + dy[k];

                    if(newx < m && newy < n  && newx >= 0 && newy >=0 && grid[newx][newy] == 1 ){
                        nonrotttenAfter++;
                        grid[newx][newy] = 2;
                        q.push({newx, newy});
                    }
                }
            }
        }
    

        // cout<<cnt;
        if(nonrotttenAfter != nonrottenInitial) return -1;
        return cnt-1 >= 0 ? cnt -1: 0;
        


    }
};