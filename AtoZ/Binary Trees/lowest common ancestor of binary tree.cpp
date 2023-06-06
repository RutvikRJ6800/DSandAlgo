// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// see best code in striver video

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
    TreeNode* res = nullptr;
    pair<int, int> rec(TreeNode* rt, TreeNode* p, TreeNode* q){
        if(!rt) return {0,0};

        pair<int, int> ans = {0,0}, left, right;

        left = rec(rt->left, p, q);
        right = rec(rt->right, p, q);

        ans.first = left.first + right.first;
        ans.second = left.second + right.second;

        if(rt == p)
            ans.first = ans.first + 1;

        if(rt == q)
            ans.second = ans.second + 1;

        if(ans.first == 1 && ans.second == 1){
            res = rt;
            return {0,0};
        }
        else
            return ans;

        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        rec(root, p, q);
        return res;
    }
};