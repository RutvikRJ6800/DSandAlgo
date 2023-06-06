// https://leetcode.com/problems/binary-tree-right-side-view/description/
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
    vector<int> rightSideView(TreeNode* root) {
        TreeNode* rt = root;
        vector<int> ans;

        queue<TreeNode*> q;
        if(!rt) return ans;
        q.push(rt);

        while(!q.empty()){
            int sz = q.size();
            int last = 0;
            while(sz--){
                TreeNode* t = q.front();
                q.pop();
                last = t->val;

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(last);
        }
        return ans;
    }
};