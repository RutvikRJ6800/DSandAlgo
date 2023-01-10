//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    Solution(){
 
        // cout<<endl;
    }
    
    int shortestPath(int Num1,int Num2)
    {   
        // find sieve array
        int n=10000;
        vector<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        
        vector<int> dp(10000, -1);
        vector<bool> visited(10000, 0);
        
        queue<int> q;
        q.push(Num1);
        dp[Num1] = 0;
        visited[Num1] = 1; // mark visited (so next time this number dont be puted into queue)
        
        while(!q.empty()){
            // cout<<"a"<<endl;
            int curr = q.front();
            q.pop();
            
            
            visited[curr] = 1;
            string num = to_string(curr);
            
            for(int i=0; i<4; i++){ // check all posible number whose digit diff is just 1
                for(char j = '0'; j<='9'; j++){
                    if(num[i] == j || (i==0 && j=='0'))continue;
                    
                    string newNum = num.substr(0,i) + j + num.substr(i+1, 4-(i+1));
                    // cout<<newNum<<endl;
                    int newNumInt = stoi(newNum);
                    
                    if(is_prime[newNumInt] && dp[newNumInt] == -1 && visited[newNumInt]==0){ // if newNumInt is prime and not been visited add it into queue
                        visited[curr] = 1;
                        dp[newNumInt] = dp[curr] + 1;
                        q.push(newNumInt);
                        // cout<<"prime: "<<newNumInt<<endl;
                    }
                }
            }
        }
        
        
        
        return dp[Num2];
        
        
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends