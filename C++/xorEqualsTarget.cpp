// https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/
// https://www.interviewbit.com/problems/subarray-with-given-xor/
int Solution::solve(vector<int> &A, int B) {


    // O(N) time and space solution- used cumulative/prefix xor concept
    int ans=0,cummulative=0;
    unordered_map<int,int> m;
    
    for(int i=0; i<A.size(); i++){
        cummulative = cummulative^A[i];
        
        if(cummulative==B)ans++;
        int y = B^cummulative;
        if(m.find(y)!=m.end()){
            ans += m[y];
        }
        m[cummulative]++;
    }
    return ans;

    // O(N2) time O(1) space- use nested loop for finding all posible subarrays and their XOR
}

