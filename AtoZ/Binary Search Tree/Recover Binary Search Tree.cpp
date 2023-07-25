// https://leetcode.com/problems/recover-binary-search-tree/description/

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
    TreeNode* prev = nullptr, *first = nullptr, *mid = nullptr, *last = nullptr;

    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);

        if(prev && prev->val > root->val){
            if(!first){
                first = prev;
                mid = root;
            }
            else{
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);

        if(first && last){
            int val = last->val;
            last->val = first->val;
            first-> val = val;
        }
        else if(first && mid){
            int val = mid->val;
            mid->val = first->val;
            first-> val = val;
        }
    }
};


/*
stack<TreeNode*> st;

        TreeNode* t = root;
        while(t){
            st.push(t);
            t = t->left;
        }

        long long int prevSmaller = LONG_MIN;
        int cnt = 0;
        while(!st.empty()){
            t = st.top();
            st.pop();

            if(t->val <= prevSmaller){
                cnt++;
            }

            prevSmaller = t->val;

            t = t->right;
            while(t){
                st.push(t);
                t = t->left;
            }
        }

        return cnt == 1;
*/