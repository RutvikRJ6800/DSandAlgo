// https://leetcode.com/problems/max-consecutive-ones/solutions/96693/java-4-lines-concise-solution-with-explanation/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0, maxCnt=0;
        for(int num: nums){
            if(num == 1){
                cnt++;
            }
            else{
                cnt = 0;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};