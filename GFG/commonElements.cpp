// https://practice.geeksforgeeks.org/problems/common-elements1132/1#
/*Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution

{
    public:    
    bool comp(int a, int b){
    return (a < b);
    }
    
   vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
    {
        //code here.
        int i,j,k;
        i=0; j=0; k=0;
        vector <int> result;
        
        while(i<n1 && j<n2 && k<n3){
            if(A[i]==B[j] && B[j] == C[k]){
                if(!result.empty() && result.back()==A[i]){
                    i++;
                    j++;
                    k++;
                    continue;
                }
                result.push_back(A[i]);
                i++;
                j++;
                k++;
                continue;
            }
            int m = std::max({A[i],B[j],C[k]});
            if(A[i]<m)
            i++;
            if(B[j]<m)
            j++;
            if(C[k]<m)
            k++;
        }
        return result;
    }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends