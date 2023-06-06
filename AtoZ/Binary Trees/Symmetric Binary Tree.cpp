// https://leetcode.com/problems/symmetric-tree/description/
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
    bool isequal(TreeNode* rt1, TreeNode* rt2){
        if(rt1 == NULL || rt2 == NULL){
            return rt1 == rt2;
        }
        return (rt1->val == rt2->val) && isequal(rt1->left, rt2->right) && isequal(rt1->right, rt2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isequal(root->left, root->right);
    }
};