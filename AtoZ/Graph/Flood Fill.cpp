// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        int m = image.size(), n = image[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));


        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = 1;

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        image[sr][sc] = color;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto [x, y] = q.front();
                q.pop();

                for(int k=0; k<4; k++){
                    int newx = x + dx[k];
                    int newy = y + dy[k];

                    if(newx >=0 && newx < m && newy >= 0 && newy < n && visited[newx][newy] == 0 &&image[newx][newy] == oldColor){
                        visited[newx][newy] = 1;
                        image[newx][newy] = color;
                        q.push({newx, newy});
                    }
                }
            }
        }

        return image;
    }
};