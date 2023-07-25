// https://practice.geeksforgeeks.org/problems/largest-bst/1

struct bst {
    bool isBST;
    int min, max, size;

    bst(bool b, int mini, int maxi, int sz) {
        isBST = b;
        min = mini;
        max = maxi;
        size = sz;
    }
};


class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    bst solve(Node* root){
        if(!root) return bst(1, INT_MAX, INT_MIN, 0);
        
        bst left = solve(root->left);
        bst right = solve(root->right);
        
        if(left.isBST && right.isBST && left.max < root->data && right.min > root->data){
            // ans = max(ans, left.size + right.size + 1);
            
            return bst(1, min(left.min, root->data), max(right.max, root->data), left.size + right.size + 1);
        }
        else{
            return bst(0, -1, -1, max(left.size, right.size));
        }
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	
    	return solve(root).size;
    }
};