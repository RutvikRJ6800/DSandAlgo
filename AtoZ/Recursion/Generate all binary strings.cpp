// A C/C++ Program to generate OTP (One Time Password)

#include<bits/stdc++.h>
using namespace std;

// A Function to generate a unique OTP everytime
void rec(int n, bool flag, string &s)
{
	if(n==0){
	    if(flag){
	        // we cant take 1 otherwise consicutive one will be otherwise
	        s.push_back('0');
	        cout<<s<<endl;
	        s.pop_back();
	    }
	    else{
	        // we can take both 0 as well as one
	        s.push_back('0');
	        cout<<s<<endl;
	        s.pop_back();
	        
	        s.push_back('1');
	        cout<<s<<endl;
	        s.pop_back();
	    }
	}
	else{
	    if(flag){
	        s.push_back('0');
	        rec(n-1, 0, s);
	        
	        s.pop_back();
	    }
	    else{
	        s.push_back('0');
	        rec(n-1, 0, s);
	        s.pop_back();
	        
	        s.push_back('1');
	        rec(n-1, 1, s);
	        s.pop_back();
	    }
	}
}

// Driver Program to test above functions
int main()
{
	string temp = "";
	rec(4-1, 0, temp);
	
	return(0);
}
