class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        //         O(N) time ans space solution
        vector<int> v;
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); ++i){
            if(m.find(target-nums[i])!=m.end()){
                
                v.push_back(m[target-nums[i]]);
                v.push_back(i);
                break;
            }
            else{
                m[nums[i]]=i;
            }
        }
        
        return v;
        
        // time - O(N2), space -O(1)
    //     vector<int> ans;
    //     for(int i=0; i<nums.size(); ++i){
    //         int curr = nums[i];
    //         int find = target-curr;
    //         for(int j=i+1; j<nums.size(); ++j){
    //             if(nums[j]==find){
    //                 ans.push_back(i);
    //                 ans.push_back(j);
    //                 break;
    //             }
    //         }
    //     }
    //     return ans;
    // }
        
    }
};