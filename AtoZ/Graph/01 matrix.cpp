// https://leetcode.com/problems/01-matrix/description/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
    
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int dist = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            dist++;

            while(size--){
                auto [x, y] = q.front();
                q.pop();

                for(int k=0; k<4;k++){
                    int newx = x + dx[k];
                    int newy = y + dy[k];

                    if(newx>=0 && newx < m && newy >=0 && newy < n){
                        if(mat[newx][newy] == 1 && visited[newx][newy] == 0){
                            // cout<<x<<" , "<<y<<" : "<<newx<<" . "<<newy<<endl;
                            visited[newx][newy] = 1;
                            mat[newx][newy] = dist;
                            q.push({newx, newy});
                        }
                    }
                }

            }
        }

        return mat;
    }
};