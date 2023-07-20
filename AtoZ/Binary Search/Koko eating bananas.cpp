// https://leetcode.com/problems/koko-eating-bananas/solutions/769702/python-clear-explanation-powerful-ultimate-binary-search-template-solved-many-problems/
// https://leetcode.com/problems/koko-eating-bananas/description/


#define ll long long
class Solution {
public:
    ll checkDays(vector<int> &piles, ll k){
        ll time = 0;
        for(int d: piles){
            time += ceil((double)d/k);
            // cout<<time<<",";
        }
        // cout<<endl;
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int sz = piles.size();
        sort(piles.begin(), piles.end());

        ll i = 1, j = piles[sz-1];

        while(i<=j){
            // cout<<i<<","<<j<<endl;
            ll m = i + (j-i)/2;
            ll res = checkDays(piles, m);
            // cout<<m<<","<<res<<endl;
            if(res > h){
                i = m + 1;
            }
            else{
                j = m - 1; 
            }
        }
        return i;


    }
};

/*
[3,6,7,11]
8
[30,11,23,4,20]
5
[30,11,23,4,20]
6
*/