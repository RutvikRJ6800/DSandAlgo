// https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
class Solution{
	public:
	int NthRoot(int n, int m)
	{
int l=1;
	    int h=m;
	    while(l<=h)
	    {
	        int mid=(l+h)/2;
	        if(pow(mid,n)==m)
	        return mid;
	        else if(pow(mid,n)>m)
	        h=mid-1;
	        else
	        l=mid+1;
	    }
	    return -1;
	}  
};