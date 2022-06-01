// { Driver Code Starts
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
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   
//   recursive solution
   if(s.size()==1){
    //   base condition
       return;
   }
   else{
      int ele = s.top(); // take one element out.
       s.pop();
       sort();//sort remaining
       stack<int> temp; // use temporary stack for soring remaining element. 
       while(!s.empty() && s.top()>ele){
           temp.push(s.top());
           s.pop();
       }
       s.push(ele);
       while(!temp.empty()){
           s.push(temp.top());
           temp.pop();
       }
   }
   
}