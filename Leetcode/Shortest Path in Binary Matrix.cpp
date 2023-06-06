// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<vector<bool>> visited(m, vector<bool>(m, 0));

        queue<pair<int, pair<int, int>>> q;
        if(!grid[0][0]){
            q.push({1,{0, 0}});
            visited[0][0] = 1;
        }

        int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        int res = -1;
        while(!q.empty()){
            auto [level, coord] = q.front();
            auto [x, y] = coord;
            q.pop();

            if(x == m-1 && y == m-1){
                res = level;
                break;
            }

            for(int k=0; k<8; k++){
                int newx = x + dx[k];
                int newy = y + dy[k];

                if(newx >= 0 && newx < m && newy >= 0 && newy < m && !visited[newx][newy] && !grid[newx][newy]){
                    // add new coord into queue
                    q.push({level + 1, {newx, newy}});
                    visited[newx][newy] = 1;
                }
            }

        }
        return res;
    }
};