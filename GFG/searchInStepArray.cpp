// https://practice.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456/1/#
// https://www.youtube.com/watch?v=s_IYrsRhxtw&ab_channel=ShashwatTiwari
// { Driver Code Starts
// C++ program to search an element in an array
// where difference between all elements is 1
#include<bits/stdc++.h>
using namespace std;

// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k);


// Driver program to test above function
int main()
{
	int t,n,k,x;
	// cin>>t;
	// while(t--)
    // {

        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>x;
        cout<<"Answer is"<<search(arr, n, x, k)<<endl;

    // }
return 0;
}

// } Driver Code Ends


// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    // Complete the function
    // optimised approch-O(n) time and constant space
    int i,steps;
    while(i<n){
        if(arr[i]==x){
            return i;
        }
        i = i+max(1,abs(x-arr[i])/k);
    }
    return -1;


//  brute force approch-O(n) time & constant space
//     for(int i=0;i<n;i++)
//    {
//        if(arr[i]==x)
//        {
//            return i;
//            break;
//        }
//    }
//    return -1;
}    	