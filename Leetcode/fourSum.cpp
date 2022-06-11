class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
//         O(N3) time and O(1)space
        int i,j,left,right, size;
        i=0;
        j=1;
        size = nums.size();
        
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<size; i++){
            
            for(int j=i+1; j<size; j++){
                
                int target2 = target-nums[i]-nums[j];
                left=j+1;
                right=size-1;
                while(left<right){
                    if((nums[left]+nums[right])<target2){
                        left++;
                    }
                    else if((nums[left]+nums[right])>target2){
                        right--;
                        
                    }
                    else{
                        vector<int> vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[left]);
                        vec.push_back(nums[right]);
                        res.push_back(vec);
                        while(left<right && nums[left]==vec[2])left++;
                        while(left<right && nums[right]==vec[3])right--;
                    }
                    
                }
                while(j+1<size && nums[j+1]==nums[j])j++;
            }
            while(i+1<size && nums[i+1]==nums[i])i++;
        }
        return res;
        
        
        
    }
};