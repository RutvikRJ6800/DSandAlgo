// https://leetcode.com/problems/maximum-running-time-of-n-computers/description/

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        /*
        Approch 1: prefix sum + sorting
        sort(batteries.begin(), batteries.end());

        int idx = batteries.size()-n;

        long long extra = 0;
        for(int i=0; i<idx; i++){
            extra += batteries[i];
        }

        for(int i=idx; i<batteries.size()-1; i++){
            int diff = batteries[i+1] - batteries[i];

            // cout<<i<<", diff:"<<diff<<endl;

            if(extra >= (long long)diff*(i-idx+1)){
                extra -= (long long)diff*(i-idx+1);
            }
            else{
                return batteries[i] + (long long)extra/(i-idx+1);
            }
        }

        return batteries[batteries.size()-1] + extra/n;

        */

        long long left = 1, right = 0, ans = 1;
        for(auto b: batteries){
            right += b;
        }

        right /= n;

        while(left <= right){
            long long mid = left + (right - left)/2;

            long long powerPossible = 0;
            for(auto power: batteries){
                if(power > mid){
                    powerPossible += mid;
                }
                else{
                    powerPossible += power;
                }
            }

            if(powerPossible >= n*mid){
                ans = mid;
                left =  mid+1; 
            }
            else{
                right = mid -1;
            }
        }

        return ans;


    }
};