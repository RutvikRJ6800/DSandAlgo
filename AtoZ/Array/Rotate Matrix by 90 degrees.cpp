// https://leetcode.com/problems/rotate-image/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        // take small 3 X 3 matrix and find ans manually
        // now observe patten in ans and original array
        // you will see prev column become row and new row = n-1- something

        reverse(matrix.begin(), matrix.end()); // reverse rows

        // now take transpoze
        for(int i=m; i>=1; i--){
            int row = m-i;
            for(int j=m-i; j<m; j++){
                swap(matrix[row][j], matrix[j][row]);
            }
        }

        // eventually we can see the req is reverse row and transpose it
    }
};