class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minTillHere = 1, maxTillHere = 1;
        int maxG = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxG = max(maxG, nums[i]);
        }
        
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int temp = maxTillHere * num;
            
            maxTillHere = max(num * maxTillHere, max(num * minTillHere, num));
            minTillHere = min(min(temp, num*minTillHere), num);
            maxG = max(maxG, maxTillHere);
        }
        
    return maxG;
    }
    
};