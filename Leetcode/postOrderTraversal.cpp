/**
 * https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/
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
    // vector<int> vec;
    vector<int> postorderTraversal(TreeNode* root) {
//         postOrder(root);
//         return vec;
        
//         iterative code 100% faster. time-O(N) space _O(N)
        stack<TreeNode*> st;
        vector<int> vec;
        if(!root){
            return vec;
        }
        
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            
            vec.push_back(curr->val);
            
            if(curr->left)st.push(curr->left);
            if(curr->right) st.push(curr->right);
            
            
        }
        reverse(vec.begin(),vec.end());
        return vec;
        
    }
    void postOrder(TreeNode* root){
        
        
//         recursive solution time -O(N) and space O(N)bcoz recursion stack
        // if(!root){
        //     return;
        // }
        // postOrder(root->left);
        // postOrder(root->right);
        // vec.push_back(root->val);
    }
};