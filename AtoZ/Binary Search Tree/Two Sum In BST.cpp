// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
/*
*
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
    bool solve(TreeNode* root, int k, unordered_map<int, bool> &hm){
        if(!root) return false;
        int currVal = root->val, needed = k - root->val;
        if(hm.find(needed) != hm.end()) return true;
        hm[currVal] = 1;

        return (solve(root->left, k, hm) || solve(root->right, k, hm));
        
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, bool> hm;
        return solve(root, k, hm);
    }
};