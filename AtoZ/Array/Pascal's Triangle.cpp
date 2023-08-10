// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows == 1) return ans;
        int inseredRows = 1;

        while(inseredRows < numRows){
            inseredRows++;
            vector<int> curr_row;
            curr_row.push_back(1);
            int ele = 1;
            while(ele<=inseredRows-2){
                cout<<inseredRows<<","<<ele;
                curr_row.push_back(ans[inseredRows-2][ele-1] + ans[inseredRows-2][ele]);
                ele++;
            }
            curr_row.push_back(1);
            ans.push_back(curr_row);
        }
        return ans;
    }
};