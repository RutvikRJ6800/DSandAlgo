// https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

void solve(int zeros, int ones, int &N, string curr, vector<string> &ans){
        if(zeros > ones) return;
        else if(zeros + ones == N){
            ans.push_back(curr);
            return;
        }
        else{
            solve(zeros, ones + 1, N, curr + '1', ans);
            solve(zeros+1, ones, N, curr + '0', ans);
        }
        
    }
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string> ans;
	    string curr = "";
	    solve(0,0,N,curr, ans);
	    return ans;
	}