// https://leetcode.com/problems/k-th-symbol-in-grammar/description/

class Solution {
public:
    int solve(int n, int k){
        // cout<<n<<"k: "<<k<<", Bola:"<<(int)(ceil(k/2.0)<<endl;
        if(n==1) return 0;
        else if(k == 1) return 0;

        int prev = solve(n-1, (int)(ceil(k*1.0/2)));
        
        if(prev == 0 && k%2 == 0) return 1;
        else if(prev == 0 && k%2 == 1) return 0;
        else if(prev == 1 && k%2 == 0) return 0;
        else if(prev == 1 && k%2 == 1) return 1;
        

        return -1;
    }
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        
        return solve(n, k);
    }
};