// https://leetcode.com/problems/balanced-binary-tree/
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
class Solution {
public:
    
    int height(TreeNode* root){
        if(root==NULL){
            return 1;
        }
        int l = height(root->left);
        int r= height(root->right);
        if(l==-1 ||r==-1 || abs(l-r)>1){
            return -1;
        }
        return ((l>r)?l:r)+1;
        
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(height(root)==-1){
            return false;
        }
        else
            return true;
        
        
    }
};