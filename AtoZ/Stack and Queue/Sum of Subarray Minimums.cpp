// https://leetcode.com/problems/sum-of-subarray-minimums/description/

#define mod 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> smallerToLeft, smallerToRight;
        int ans = 0, n = arr.size();
        vector<int> left(n, 0), right(n, 0);

        for(int i=n-1; i>=0; i--){
            while(!smallerToRight.empty() && arr[smallerToRight.top()] >= arr[i]){
                smallerToRight.pop();
            }

            if(smallerToRight.empty()){
                right[i] = n;
            }
            else{
                right[i] = smallerToRight.top();
            }
            smallerToRight.push(i);
        }   

        for(int i=0; i<n; i++){
            while(!smallerToLeft.empty() && arr[smallerToLeft.top()] > arr[i]){
                smallerToLeft.pop();
            }

            if(smallerToLeft.empty()){
                left[i] = -1;
            }
            else{
                left[i] = smallerToLeft.top();
            }
            smallerToLeft.push(i);
        }
        
        for(int i=0; i<n; i++){
            // cout<<right[i]<<":"<<left[i]<<endl;
            ans = (ans % mod)  + (((((right[i]-i - 0LL) % mod) * ((i-left[i]-0LL) % mod)) % mod) * arr[i]) % mod;
        }
        return ans;
    }
};