// https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int si = 0, sj = 0, elesConsidered = 0, totalEles = m*n;
        vector<int> ans;
        while(elesConsidered < totalEles){
            // cout<<si<<endl;
            for(int i=si; i<=n-1-si; i++){
                // cout<<si<<",a"<<i<<endl;
                ans.push_back(matrix[si][i]);
                elesConsidered++;
            }

            for(int i=si+1; i<=m-1-si; i++){
                // cout<<i<<",b"<<n-1-si<<endl;
                ans.push_back(matrix[i][n-1-si]);
                elesConsidered++;
            }

            for(int i=n-2-si; i>=si && m-1-si != si; i--){
                // cout<<m-1-si<<",c"<<i<<endl;
                ans.push_back(matrix[m-1-si][i]);
                elesConsidered++;
            }

            for(int i=m-2-si; i>si && si!=n-1-si; i--){
                // cout<<i<<",d"<<si<<endl;
                ans.push_back(matrix[i][si]);
                elesConsidered++;
            }
            si++;
            // sj++;
        }
        return ans;
    }
};