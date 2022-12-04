class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long leftsum = 0,n = nums.size();
        long long rightsum = 0, lavg = 0, ravg = 0;
        vector<int> ans(n,0);
        
        for(int i=0; i<n; i++){
            rightsum += nums[i];
        }
        
        int minv = INT_MAX;
        int mini = 0;
        
        for(int i=0; i<n-1; i++){
            // modifie left sum
            leftsum = leftsum + nums[i];
            lavg = leftsum / (i+1);
            
            // modify right sum
            rightsum = rightsum - nums[i];
            ravg = rightsum / (n - (i + 1));
            
            // cout<< leftsum <<"::"<<rightsum;
        
            ans[i] = abs(lavg - ravg);
            
            if(ans[i] < minv){
                minv = ans[i];
                mini = i;
            }
            // cout<<">" <<ans[i]<<endl;
        }
        
        leftsum += nums[n-1];
        ans[n-1] = leftsum / n;
        
        if(ans[n-1] < minv){
            minv = ans[n-1];
            mini = n-1;
        }
        
        return mini;
    }
};