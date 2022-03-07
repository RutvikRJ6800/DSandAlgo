// https://practice.geeksforgeeks.org/problems/construct-tree-1/1#
// { Driver Code Starts
//

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
    Node* root=NULL;
    
    Node* insert(Node* root,int *in, int ele, int n){
        
        if(root==NULL){
            return new Node(ele);
        }
        
        int indexRoot, indexEle,i,rootElement;
        
        rootElement=root->data;
        
        for(i=0; i<n; i++){
            if(in[i]==rootElement){
                indexRoot=i;
            }
            if(in[i]==ele){
                indexEle=i;
            }
        }
        
        if(indexRoot<indexEle){
            root->right=insert(root->right, in, ele, n);
        }
        else if(indexRoot>indexEle){
            root->left=insert(root->left, in, ele, n);
        }
        
        
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        
        for(size_t i=0; i<n; i++){
            int ele = pre[i];
            root =insert(root, in, ele,n);
   
        }
        
        return root;
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