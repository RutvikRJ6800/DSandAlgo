// https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, ans = 0;

        while(left < right){
            ans = max(ans, (right-left)*min(height[left], height[right]));

            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;

    }
};