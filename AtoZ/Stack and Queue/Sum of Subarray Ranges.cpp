// https://leetcode.com/problems/sum-of-subarray-ranges/description/


class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftsmall(n, 0), rightsmall(n, 0), leftlarge(n, 0), rightlarge(n, 0);

        stack<int> st1, st2;
        for(int i=0; i<n; i++){
            int ele = nums[i];
            while(!st1.empty() && nums[st1.top()] >= ele){
                st1.pop();
            }
            if(st1.empty()) leftsmall[i] = -1;
            else leftsmall[i] = st1.top();

            st1.push(i);



            while(!st2.empty() && nums[st2.top()] <= ele){
                st2.pop();
            }
            if(st2.empty()) leftlarge[i] = -1;
            else leftlarge[i] = st2.top();
            st2.push(i);

        }

        while(!st1.empty()){
            st1.pop();
        }
        while(!st2.empty()){
            st2.pop();
        }

        
        for(int i=n-1; i>=0; i--){
            int ele = nums[i];
            while(!st1.empty() && nums[st1.top()] > ele){
                st1.pop();
            }
            if(st1.empty()) rightsmall[i] = n;
            else rightsmall[i] = st1.top();

            st1.push(i);

            while(!st2.empty() && nums[st2.top()] < ele){
                st2.pop();
            }
            if(st2.empty()) rightlarge[i] = n;
            else rightlarge[i] = st2.top();
            st2.push(i);

        }

        long long ans = 0;
        for(int i=0; i<n; i++){
            int ele = nums[i];
            // cout<<leftsmall[i]<<","<<rightsmall[i]<<" : "<<leftlarge[i]<<","<<rightlarge[i]<<endl;
            // find how much time we need to delete this ele / ele is small
            int deletetime = 0;
            if(leftsmall[i] == -1) deletetime = ((i+1)*(rightsmall[i]-i)) - 1;
            else deletetime = (i-leftsmall[i])*(rightsmall[i] - i) - 1;
            
            int addtime = 0;
            if(leftlarge[i] == -1) addtime = ((i+1)*(rightlarge[i] - i)) -1;
            else addtime = ((i-leftlarge[i])*(rightlarge[i] - i)) - 1;
            
            // cout<<" -- "<<deletetime<<" ++ "<<addtime<<" = "<<((addtime - deletetime)*nums[i])<<endl;
            ans += (((long long)addtime - deletetime)*nums[i]);
        }
        return ans;
    }
};