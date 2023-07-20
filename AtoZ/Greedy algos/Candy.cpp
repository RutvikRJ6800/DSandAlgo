// https://leetcode.com/problems/candy/description/
class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.first < b.first;
    }
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        if(n == 1) return {1};

        vector<pair<int, int>> vec(n);

        for(int i=0; i<n; i++){
            vec[i] = {ratings[i], i};
        }

        sort(vec.begin(), vec.end(), cmp);
        vector<int> ans(n, -1);

        for(int i=0; i<n; i++){
            int idx = vec[i].second;

            if(idx == 0){
                if(ratings[idx+1] < ratings[idx]){
                    ans[idx] = ans[1]+1;
                }
                else{
                    ans[idx] = 1;
                }
            }
            else if(idx == n-1){
                if(ratings[idx-1] < ratings[idx]){
                    ans[idx] = ans[idx-1]+1;
                }
                else{
                    ans[idx] = 1;
                }
            }
            else{
                if((ratings[idx-1] < ratings[idx]) && (ratings[idx+1] < ratings[idx])){
                    ans[idx] = 1 + max(ans[idx+1], ans[idx-1]);
                }
                else if((ratings[idx-1] < ratings[idx])){
                    ans[idx] = 1 + ans[idx-1];
                }
                else if((ratings[idx+1] < ratings[idx])){
                    ans[idx] = 1 + ans[idx + 1];
                }
                else{
                    ans[idx] = 1;
                }
            }

        }

        int sum = 0;
        for(int i=0; i<n; i++){
            // cout<<ans[i]<<", ";
            sum += ans[i];
        }
        return sum;
    }
};