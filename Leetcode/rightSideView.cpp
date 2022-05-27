/**
 * https://leetcode.com/problems/binary-tree-right-side-view/submissions/
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
        vector<int> res;
        if(!root)
        return res;
        
//         queue stores node and level of the node
// basically for each level we need to store first node's value that we will visit 
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<TreeNode*,int> p=q.front();
            q.pop();
            TreeNode* curr = p.first;
            int level = p.second;
            
//             if the visiting node is the first seen with respected to level then add it in result
            if(res.empty() || res.size()<=level){
                res.push_back(curr->val);
            }
            
//             first add right subtree/node if exist
            if(curr->right){
                q.push(make_pair(curr->right,level+1));
            }
            
//             then add left subtree/node if exist
            if(curr->left){
                q.push(make_pair(curr->left,level+1));
            }
        }
        return res;
    
    }
};