// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double, Item> &a, pair<double, Item> &b){
        return a.first >= b.first;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, Item>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({arr[i].value/(arr[i].weight + 0.0), arr[i]});
        }
        
        sort(vec.begin(), vec.end(), cmp);
        
        int i=0, capacity = W;
        double ans = 0.0;
        
        while(i<n && capacity > 0){
            // cout<<i<<" : "<<vec[i].first<<", "<<vec[i].second.value<<" & "<<vec[i].second.weight<<endl;
            if(vec[i].second.weight <= capacity){
                ans += vec[i].second.value;
                capacity -= vec[i].second.weight;
            }
            else if(vec[i].second.weight > capacity) break;
            i++;
        }
        
        if(capacity > 0){
            ans += (capacity * vec[i].first);
        }
        
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends