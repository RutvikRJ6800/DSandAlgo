class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for(int i=0; i<cols; i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1; i<rows; i++){
            for(int j=0; j<cols; j++){
                int case1=INT_MAX, case2=INT_MAX, case3=INT_MAX;

                if(j-1>=0){
                    case1 = dp[i-1][j-1];
                }
                if(j+1<cols){
                    case3 = dp[i-1][j+1];
                }
                case2 = dp[i-1][j];

                dp[i][j] = min(min(case1, case2), case3) + matrix[i][j]; // take min of all posible adj cell of prev row
            }
        }

        int ans = INT_MAX;
        for(int i=0; i<cols; i++){
            ans = min(ans, dp[rows-1][i]);
        }

        return ans;
    }
};