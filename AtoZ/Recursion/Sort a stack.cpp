// https://practice.geeksforgeeks.org/problems/sort-a-stack/1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
stack <int> temp1, temp2;
void rec(stack<int> &st){
    if(!st.empty()){
        int ele = st.top();
        st.pop();
        
        
        while(!temp1.empty() && temp1.top() < ele){
           temp2.push(temp1.top());
           temp1.pop();
       }
       
       temp1.push(ele);
       
       while(!temp2.empty()){
           temp1.push(temp2.top());
           temp2.pop();
       }
       
       rec(st);
       
       st.push(temp1.top());
       temp1.pop();
        
    }
    
}
void SortedStack :: sort()
{
   //Your code here
//   stack<int> temp1, temp2;
   
//   while(!s.empty()){
//       int ele = s.top();
//       s.pop();
       
       
//       while(!temp1.empty() && temp1.top() < ele){
//           temp2.push(temp1.top());
//           temp1.pop();
//       }
       
//       temp1.push(ele);
       
//       while(!temp2.empty()){
//           temp1.push(temp2.top());
//           temp2.pop();
//       }
//   }
   
//   while(!temp1.empty()){
//       s.push(temp1.top());
//       temp1.pop();
//   }
   rec(s);
   
   
}