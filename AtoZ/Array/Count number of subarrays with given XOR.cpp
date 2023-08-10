// https://www.interviewbit.com/problems/subarray-with-given-xor/
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> mp;
    int preXor = 0, ans=0;
    mp[0] = 1;
    for(int num: A){
        preXor ^= num;
        int needed = preXor ^ B;
        ans += mp[needed];
        mp[preXor]++;
    }
    return ans;
}
