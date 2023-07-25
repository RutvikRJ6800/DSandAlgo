// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* t = root;
        while(t){
            st.push(t);
            t=t->left;
        }


        int cnt = 0;

        while(!st.empty()){
            t = st.top();
            st.pop();
            cnt++;

            if(cnt == k) return t->val;

            t = t->right;
            while(t){
                st.push(t);
                t = t->left;
            }
        }

        return -1;
    }
};