// https://leetcode.com/problems/validate-binary-search-tree/description/

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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;

        TreeNode* t = root;
        while(t){
            st.push(t);
            t = t->left;
        }

        long long int prevSmaller = LONG_MIN;
        while(!st.empty()){
            t = st.top();
            st.pop();

            if(t->val <= prevSmaller){
                return false;
            }

            prevSmaller = t->val;

            t = t->right;
            while(t){
                st.push(t);
                t = t->left;
            }
        }

        return true;
    }
};