// https://leetcode.com/problems/trapping-rain-water/description/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> largestToLeft(n, 0);
        int  maxi = 0;
        largestToLeft[0] = -1;

        for(int i =0; i<n; i++){
            if(height[maxi] > height[i]){
                largestToLeft[i] = maxi;
            }
            else{
                largestToLeft[i] = -1;
            }

            if(height[maxi] < height[i]){
                maxi = i;
            }
        }

        vector<int> largestToRight(n, 0);
        largestToRight[n-1] = n;
        maxi = n-1;

        for(int i =n-2; i>=0; i--){
            if(height[maxi] > height[i]){
                largestToRight[i] = maxi;
            }
            else{
                largestToRight[i] = n;
            }

            if(height[maxi] < height[i]){
                maxi = i;
            }
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            // cout<<largestToLeft[i]<<":"<<largestToRight[i]<<endl;
            if(largestToRight[i] != n && largestToLeft[i] != -1){
                ans += min(height[largestToRight[i]], height[largestToLeft[i]]) - height[i];
            }
        }

        return ans;
    }
};