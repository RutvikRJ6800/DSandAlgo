// https://leetcode.com/problems/3sum/
// https://www.youtube.com/watch?v=onLoX6Nhvmg&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=42&ab_channel=takeUforward
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)return res;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size();i++){
            
            int j=i+1;
            int k=nums.size()-1;
            int need = -nums[i];
            
            while(j<k){
                if(need == nums[j]+nums[k]){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    res.push_back(v);
                    while(k>=2 && nums[k]==nums[k-1])k--;
                    k--;
                    while(j<=nums.size()-3 && nums[j]==nums[j+1])j++;
                    j++;
                }
                else if(need<nums[j]+nums[k]){
                    while(k>=2 && nums[k]==nums[k-1])k--;
                    k--;
                }
                else{
                     while(j<=nums.size()-3 && nums[j]==nums[j+1])j++;
                    j++;
                }
            }
            while(i<nums.size()-2 && nums[i]==nums[i+1])i++;

        }
        return res;
        
//         Not working code
//         for(int i=0; i<nums.size();++i){
//             for(int j=i+1;j<nums.size(); ++j){
//                 for(int k=j+1; k<nums.size(); ++k){
//                     if(nums[i]+nums[j]+nums[k]==0){
//                         vector<int> tpl;
//                         tpl.push_back(i);
//                         tpl.push_back(j);
//                         tpl.push_back(k);
//                         // sort(tpl.begin(),tpl.end());
                        
//                         // if(res.find(tpl)==res.end())
//                         res.push_back(tpl);
//                     }
//                 }
//             }
//         }
        
//         return res;
    }
};