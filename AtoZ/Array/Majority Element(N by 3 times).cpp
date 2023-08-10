// https://leetcode.com/problems/majority-element-ii/ 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=INT_MAX, freq1 = 0, n=nums.size();
        int ele2=INT_MAX, freq2 = 0;

        for(int i=0; i<n; i++){
            if(freq1==0 && ele2 != nums[i]) {ele1 = nums[i]; freq1=1;}
            else if(freq2==0 && ele1 != nums[i]) {ele2 = nums[i]; freq2=1;}

            else if(ele1 == nums[i]) freq1++;
            else if(ele2 == nums[i]) freq2++;
            else{
                freq1--;
                freq2--;
            } 
        }
        
        cout<<ele1<<":"<<freq1<<endl<<ele2<<":"<<freq2<<endl;
        freq1 = 0, freq2 = 0;
        if(ele1 == ele2){
            for(int i=0; i<n; i++){
                if(nums[i]==ele1) freq1++;
            }
            if(freq1 > (n/3)) return {ele1};
        }
        else{
            vector<int> ans;
            for(int i=0; i<n; i++){
                if(nums[i]==ele1) freq1++;
                if(nums[i]==ele2) freq2++;
            }
            if(freq1 > (n/3)) ans.push_back(ele1);
            if(freq2 > (n/3)) ans.push_back(ele2); 
            return ans;
        }
        return {};

    }
};