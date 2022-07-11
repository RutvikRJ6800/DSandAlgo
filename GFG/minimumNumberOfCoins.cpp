// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int f(int v[],int M , int c){
	    
	    
	   // Greedy algorithm will not work if sum of two smaller coins
	   // is bigger than biger coins
	   
	   //eg. coins {9 6 5 1} & W=11, here greedy gives 9+1+1 and optimal is 6+5
	    int ans=0;
	    int j=M-1;
	    while(c>0 && j>=0){
	        if(v[j]<=c){
	            ans++;
	            c=c-v[j];
	        }
	        else j--;
	    }
	    return ans;

    // // cout<<"i: "<<i<<", c: "<<c<<endl;
    // if(i>=M){
    //     return -1;
    // }

    // if(v[i]==c){return 1;}
    // else{
    //     int tk=0,nt=0;
    //     if(v[i]<= c){
    //         tk=f(v,M,i,c-v[i]);
    //         nt=f(v,M,i+1,c);
    //         if(tk==-1 && nt==-1)return -1;
    //         if(tk==-1)return nt;
    //         if(nt==-1)return 1+tk;
    //         return min(1 + tk,nt);
    //     }
    //     else{
    //         return f(v,M,i+1,c);
    //     }

    // }

}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    sort(coins,coins+M);
	    return f(coins,M,V);
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends