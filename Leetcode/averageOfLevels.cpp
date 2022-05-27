/**
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> finalResult;
        if(!root){
            return finalResult;
        }
        
        queue<TreeNode*> q;
        q.push(root);
            
        while(!q.empty()){
            int qlen = q.size();
            double sum = 0.0;
            for(int i=0; i<qlen; i++){
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            finalResult.push_back(sum/qlen);
        }
        
        return finalResult;
    }
};