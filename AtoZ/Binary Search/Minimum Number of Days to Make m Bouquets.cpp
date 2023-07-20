// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

class Solution {
public:
    int checkIfPossible(vector<int>& bloomDay, int m, int k, int mid){
        int flow = 0, bouq = 0;
        for (int j = 0; j < bloomDay.size(); ++j) {
            if (bloomDay[j] > mid) {
                flow = 0;
            } else if (++flow >= k) {
                bouq++;
                flow = 0;
            }
        }
        return bouq;
        // int cnt = 0, n = bloomDay.size();
        // int i=0;
        // while(i<n){
        //     int tempK = k;
        //     bool flag = true;
        //     while(tempK && i<n){
        //         tempK--;
        //         if(bloomDay[i] > mid){
        //             flag = false;
        //             // cout<<"hited false:"<<i<<endl;
        //             i++;
        //             break;
        //         }
        //         else{
        //             i++;
        //         }
        //     }
        //     if(flag && tempK == 0)cnt++;
        // }
        // // cout<<"cnt: "<<cnt<<endl;
        // return cnt;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if((long long int)m*k > n) return -1;

        int mini = INT_MAX, maxi = INT_MIN, daysneeded = -1;

        for(int i=0; i<n; ++i){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }


        while(mini<=maxi){
            int mid = mini + (maxi-mini)/2;

            // cout<<mini<<", "<<maxi<<", "<<mid<<endl;
            if(checkIfPossible(bloomDay, m, k, mid) >= m){
                daysneeded = mid;
                maxi = mid - 1;
            }
            else{
                mini = mid + 1;
            }
        }

        return daysneeded;

    }
};