// https://leetcode.com/problems/check-if-it-is-a-straight-line/description/
// though this code is bad. see good code in leetcode editorial
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size = coordinates.size();


        if(coordinates[0][0] == coordinates[1][0]){
            for(int i=2; i<size; ++i){
                if(coordinates[i][0] != coordinates[i-1][0]) return false;
            }
            return true;
        }
        else{
            double slope = (coordinates[1][1] - coordinates[0][1]) / (double)(coordinates[1][0] - coordinates[0][0]);

            for(int i=2; i<size; ++i){

                if((coordinates[i][0] - coordinates[i-1][0]) == 0 || ((coordinates[i][1] - coordinates[i-1][1]) / (double)(coordinates[i][0] - coordinates[i-1][0])) != slope) return false;
            }
            return true;
            
        }
    }
};