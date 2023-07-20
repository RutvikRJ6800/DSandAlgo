// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
//{ Driver Code Starts
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
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.first > b.first;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int, int>> vec(n);
        for(int i=0; i<n; i++){
            vec[i] = {arr[i].profit, arr[i].dead};
        }
        
        sort(vec.begin(), vec.end(), cmp);
        
        // for(auto it : vec){
        //     int profit = it.first, deadline = it.second;
        //     cout<<profit<<" "<<deadline<<endl;
        // }
        
        // cout<<endl;
        
        int jobDone = 0, profit = 0;
        vector<int> cal(n+1, -1);
        
        for(int i=0; i<n; i++){
            
            for(int j=vec[i].second -1; j>=0; j--){
                if(cal[j] == -1){
                    jobDone++;
                    cal[j] = i;
                    profit += vec[i].first;
                    // cout<<jobDone<<", "<<vec[i].first<<":"<<vec[i].second<<endl;
                    break;
                }
            }
        }
        
        return {jobDone, profit};
    } 
};

//{ Driver Code Starts.
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