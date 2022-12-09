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
    void getleaves(TreeNode * root, vector<int> &vec){
        if(!root) return;
        
        if (!root->left && !root->right){
            vec.push_back(root->val);
        }
        
        if (root->left) getleaves(root->left, vec);
        if (root -> right) getleaves(root->right, vec);
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> vec1;
        getleaves(root1, vec1);
        
         std::vector<int> vec2;
        getleaves(root2, vec2);
        
        if (vec1.size() != vec2.size()) return false;
        
        for(int i=0; i<vec1.size(); i++){
            if(vec1[i] != vec2[i]) return false;
        }
        
        return true;
    }
};