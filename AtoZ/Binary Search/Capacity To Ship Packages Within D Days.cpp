// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/


class Solution {
public:
    bool canWeFinish(vector<int>& weights, int capacity, int days){
        int currweight = 0, currday = 1;

        for(int weight: weights){
            currweight += weight;
            
            if(capacity < currweight){
                currday++;
                currweight = weight;
            }
        }

        return currday <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxvalue = INT_MIN, total = 0;
        for(int weight: weights){
            maxvalue = max(maxvalue, weight);
            total += weight;
        }

        int l = maxvalue, r = total;

        while(l<r){
            int mid = l + (r-l)/2;
            if(canWeFinish(weights, mid, days)){
                // we can finish check for lesser capcity
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }


        return r;

    }
};