// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    
    static bool cmp(Job ob1 , Job ob2){
	            return ob1.profit > ob2.profit;
	        }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, cmp);
          
        int maxDeadline=0;
        
        // find max deadline
        for(int i=0; i<n; i++){
            if(arr[i].dead>maxDeadline){
                maxDeadline=arr[i].dead;
            }
        }
        
        // // ans is time chart
        vector<int> ans(maxDeadline,-1);
        
        // set as far as pos
        for(int i=0; i<n; i++){
            int deadline = arr[i].dead;
            // bool success=false;
            for(int j=deadline-1; j>=0;j--){
                if(ans[j]==-1){
                    ans[j]=arr[i].profit;
                    // success=true;
                    break;
                }
            }
            
        }
        
        // find maxProfit and number of jobs from time chart.
        int maxProfit=0, count=0;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]!=-1){
                maxProfit+=ans[i];
                count++;
            }
        }
        
        // formate a vector containing return result;
        
        return {count,maxProfit};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends