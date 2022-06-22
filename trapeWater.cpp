// https://leetcode.com/problems/trapping-rain-water/submissions/
//  https://www.youtube.com/watch?v=m18Hntz4go8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=43&ab_channel=takeUforward
class Solution {
public:
    int trap(vector<int>& height) {
//         optimal approch is not coded- do it after learning two pointer
        
        
//         mid-good approach- time&space-O(N) 
        vector<int> premax(height.size(),0),suffmax(height.size(),0);
        int pre=0;
        for(int i=0; i<height.size();i++){
            premax[i]=pre;
            if(pre<height[i])pre=height[i];
        }
        int suff=0;
        for(int i=height.size()-1; i>=0;i--){
            suffmax[i]=suff;
            if(suff<height[i])suff=height[i];
        }
        int sum=0;
        for(int i=0; i<height.size();i++){
            sum += (min(premax[i],suffmax[i])-height[i])>0?min(premax[i],suffmax[i])-height[i]:0;
        }
        return sum;
    }
};