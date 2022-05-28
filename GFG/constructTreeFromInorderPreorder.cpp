// { Driver Code Starts
//https://practice.geeksforgeeks.org/problems/construct-tree-1/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* insert(int in[], int is, int ie, int pre[], int ps, int pe, unordered_map<int, int> &hm){
        if(is>ie || ps>pe){
            return NULL;
        }
        
        Node * root = new Node(pre[ps]);
        int inRoot = hm[pre[ps]];
        int numsLeft = inRoot-is;
        
        root->left = insert(in,is,inRoot-1,pre,ps+1,ps+numsLeft,hm);
        root->right = insert(in,inRoot+1,ie,pre,ps+numsLeft+1,pe,hm);
        
        return root;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        if(n==0){
            return NULL;
        }
        
        unordered_map<int, int> hm;
        for(int i=0; i<n; i++){
            hm[in[i]] = i;
        }
        
        return insert(in,0,n-1,pre,0,n-1,hm);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends