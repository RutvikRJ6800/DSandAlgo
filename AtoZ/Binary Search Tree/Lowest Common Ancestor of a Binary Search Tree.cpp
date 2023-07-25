// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return nullptr;

        if(root == p || root == q){
            return root;
        }
        else if(root->val < min(p->val, q->val)){
            return solve(root->right, p , q);
        }
        else if(root->val > max(p->val, q->val)){
            return solve(root->left, p, q);
        }
        TreeNode* left = solve(root->left, p, q);
        TreeNode* right = solve(root->right, p, q);

        if(left && right) return root;
        else if(left) return left;
        else if(right) return right;
        else return nullptr;


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};