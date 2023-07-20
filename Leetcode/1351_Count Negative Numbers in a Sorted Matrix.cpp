// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // n^2 solution is easy
        
        int m = grid.size(), n = grid[0].size() , i=0, j=n-1, cnt = 0;

        while(i < m && j >= 0){
            if(grid[i][j] < 0){
                cout<<i<<","<<j<<":"<<(m-i)<<endl;
                cnt += (m - i);
                j--;

            }
            else{
                i++;
            }
        }

        return cnt;     
    }
};