// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> q;
        int n = nums.size(), i = 0, j = 0;
        vector<int> ans;

        while(j<n){
            // maintain mono que
            while(!q.empty() && q.back().second <= nums[j]){
                // cout<<j<<":"<<q.back().second<<endl;
                q.pop_back();
            }
            q.push_back({j, nums[j]});

            if(j - i + 1 < k){
                j++;
            }
            else if(j - i + 1 == k){
                ans.push_back(q.front().second);

                // pq.erase(std::find(pq.c.begin(), pq.c.end(), nums[i]));
                if(q.front().first == i){
                    q.pop_front();
                }

                i++;
                j++;
            }
        }
        return ans;
    }
};