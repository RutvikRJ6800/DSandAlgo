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
    

    int search(int in[],int curr, int st, int end){
        for(int i=st; i<= end; i++){
            if(in[i]==curr){
                return i;
            }
        }
        return -1;
    }
    
    Node* insert(int in[], int pre[], int st, int end){

        static int idx =0;
        if(st>end){
            return NULL;
        }
        int curr = pre[idx];
        idx++;
        Node* node = new Node(curr);

        int pos = search(in,curr, st, end);
        node->left = insert(in, pre, st, pos-1);
        node->right= insert(in, pre, pos+1, end);

        return node;
        
        
        
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        
        Node* root =insert(in,pre ,0, n-1);
        
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