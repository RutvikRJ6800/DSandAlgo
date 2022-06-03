// https://leetcode.com/problems/pascals-triangle/
// https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        
        for(int i=0; i<numRows;++i){
            vector<int> v;
            
            for(int j=0; j<=i; ++j){
                if(j==0 || j==i){
                    v.push_back(1);
                }
                else{
                    int sum = res.back()[j]+res.back()[j-1];
                    v.push_back(sum);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};