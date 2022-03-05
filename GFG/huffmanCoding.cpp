// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
struct treeNode{
	        int val;
	        char symbol;
	        treeNode* left;
	        treeNode* right;
	        treeNode(int v, char c, treeNode* l = NULL, treeNode *r = NULL){
	            val = v;
	            symbol = c;
	            left = l;
	            right = r;
	        }
    
};
struct comp{
	        bool operator()(treeNode * node1 , treeNode* node2){
	            return node1->val > node2->val;
	        }
	    };
void preOrder(treeNode* root, vector<string> &ans, string curr=""){
    if(root==NULL) return;
    if(root->symbol!='$' && root->left==NULL &&root->right==NULL){
        ans.push_back(curr);
        return;
    }
    preOrder(root->left,ans,curr+'0');
    preOrder(root->right,ans,curr+'1');
    return ;
    
}

	        
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<treeNode*, vector<treeNode*>, comp> pq;
		    for(int i=0; i<N; i++){
		        pq.push(new treeNode(f[i],S[i]));
		    }
		    
		    while(pq.size()>1){
		        treeNode* t1 = pq.top();
		        pq.pop();
		        treeNode* t2 = pq.top();
		        pq.pop();
		        treeNode* newNode = new treeNode(t1->val+t2->val,'$',t1,t2);
		        pq.push(newNode);
		    }
		    vector<string> ans;
		    preOrder(pq.top(),ans,"");
		    return ans;
		    
		    
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends