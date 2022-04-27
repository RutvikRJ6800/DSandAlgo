// { Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

void reverse_dig(int &a,int &b)
{
    //Add your code here.
    cout<<a<<b;
    
}
void swap(int &a,int &b)
{
    //Add your code here.
}


// { Driver Code Starts.

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
	    cin>>a>>b;
	
	    reverse_dig(a,b);
	    swap(a,b);
	    cout<<a<<" "<<b<<endl;
    }
	return 0;
}  // } Driver Code Ends