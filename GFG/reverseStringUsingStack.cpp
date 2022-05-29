// { Driver Code Starts
// https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}

// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{
    //code here


    // time -O(size of string) and space = O(size of string)
    stack<int> st;
    for(int i=0; i<len; i++){
        st.push(S[i]);
    }
    int i=0;
    while(!st.empty()){
        S[i]=st.top();
        st.pop();
        i++;
    }
    return S;
}