/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool isLeaf(TreeNode* root){ // this function check if node is leaf node or not
    if(!root->left && !root->right){
        return true;
    }
    else
        return false;
}

void helper(vector<int> &ans, TreeNode* root){
    if(!root) return;
    
    if(root->left && root->right){ // this is non leaf node so add 1 into ans
        ans[0]++;
        helper(ans, root->left);
        helper(ans, root->right);
        return;
    }
    else if(root->left && isLeaf(root->left)){ // this is non leaf node with only left child && this node is in second last
        ans[0]++;
        helper(ans, root->left);
        return;
    }
    else if(isLeaf(root)){ // this is leaf node
        ans[0]++;
        helper(ans, root->left);
        return;
    }
//     else{
        
//     }
    
}


class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        vector<int> ans(1,0);
        
        helper(ans, root);
        
        return ans[0];
        
    }
};