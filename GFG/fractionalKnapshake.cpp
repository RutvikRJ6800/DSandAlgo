// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1/#
// { Driver Code Starts
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
    
    // static bool compareS(Item i1, Item i2){
    //     return ((i1.value)/(0.0+i1.weight))>((i2.value)/(0.0+i2.weight));
    // }
    static bool compareS(Item a1, Item a2){
        //int divided or added by double gives double only.
        return a1.value/(1.0* a1.weight) > a2.value/(1.0* a2.weight);   
        //decreasing order
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double profit=0;
        
        sort(arr,arr+n,compareS);
        int currCapacity=W;
        int i=0;
        // for(int k=0; k<n;k++){
        //     cout<<arr[k].value+" ";
        // }
        // while(currCapacity>0 && i<n){
        //     if(arr[i].weight<=currCapacity){
        //         currCapacity-=arr[i].weight;
        //         profit+=arr[i].value;
        //         cout<<currCapacity<<" ";
                
        //     }
        //     i++;
        // }
        for(i=0; i<n; i++){
            if(arr[i].weight<=currCapacity){
                currCapacity-=arr[i].weight;
                profit+=arr[i].value;
                
            }
            else if(currCapacity>0){
            profit+= currCapacity*arr[i].value/(0.0 + arr[i].weight);
            currCapacity=0;
            }
        
            
        }
        return profit;  
       
    }
        
};


// { Driver Code Starts.
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
}  // } Driver Code Ends