// https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool colZero = false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    if(j==0) colZero = true;
                    else
                        matrix[0][j] = 0;
                    matrix[i][0] = 0;
                        
                }
            }
        }
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(j==0){
                    if(colZero) matrix[i][j] = 0;
                }
                else{
                    if(!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
                }
            }
        }
    }
};