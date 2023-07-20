// https://leetcode.com/problems/path-with-minimum-effort/description/


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> minDiff(m, vector<int>(n, 1e9));
            
        
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        minDiff[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int currNodeDiff = it.first;
            int x = it.second.first;
            int y = it.second.second;

            for(int k=0; k<4; k++){
                int newx = x + dx[k];
                int newy = y + dy[k];

                if(newx>=0 && newx<m && newy >=0 && newy < n){
                    if(minDiff[newx][newy] > max(minDiff[x][y], abs(heights[x][y] - heights[newx][newy]))){
                       minDiff[newx][newy] = max(minDiff[x][y], abs(heights[x][y] - heights[newx][newy])); 
                       pq.push({minDiff[newx][newy], {newx, newy}});

                    //    for(auto vec: minDiff){
                    //         for(auto num: vec){
                    //             cout<<num<<", ";
                    //         }
                    //         cout<<endl;
                    //     }
                    }
                }

                // cout<<endl;
            }
            
        }

        // for(auto vec: minDiff){
        //     for(auto num: vec){
        //         cout<<num<<", ";
        //     }
        //     cout<<endl;
        // }

        return minDiff[m-1][n-1];

    }
};