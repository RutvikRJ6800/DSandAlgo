// https://leetcode.com/problems/kth-missing-positive-number/description/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        
        while(left<=right){
            int mid = left +(right-left)/2;

            int missingTillMid = arr[mid] - (mid + 1);

            if(missingTillMid < k){
                // goto right
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        if(right < 0) return k;
        else return arr[right] + (k - (arr[right] - 1 - right));


        /*
        **** O(N) time solution: ****

        int start = 1, i = 0, n = 0;
        n = arr.size();
        // k--;
        while(k && i < n){
            if(arr[i] > start){
                // cout<<start<<":"<<i<<":"<<k<<endl;
                k--;
                start++;
            }
            else if(arr[i] == start){
                i++;
                start++;

            }
        }

        while(k--){
            start++;
        }

        return start-1;
        */
    }
};