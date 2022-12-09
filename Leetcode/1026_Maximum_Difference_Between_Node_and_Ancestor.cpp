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
    void rec(TreeNode* root, int minVal, int maxVal, vector<int> &ans){
        // maxVal & minVal denote the max & minimum value seen till now in current path.
        // ans[0] will store the maximum posible difference btw ancestore and node till now.

        if(!root)return; // exit if null 

        ans[0] = max(max(ans[0], abs(minVal - (root->val))), abs(maxVal - (root->val)));

        minVal = min(minVal, root->val); // update min and max value
        maxVal = max(maxVal, root->val);

        rec(root->left, minVal, maxVal, ans); // go left and right recursively
        rec(root->right, minVal, maxVal, ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int> ans(1,INT_MIN);

        rec(root, root->val, root->val, ans);
        return ans[0];
    }
};