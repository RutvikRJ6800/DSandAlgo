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
    vector<vector<int>> levelOrder(TreeNode* root) {
   
        // faster then 100% cpp submission
        // my code time-O(N) and space O(N) it store levels and add elements according to its respective level vector
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<TreeNode*,int> p = q.front();
            q.pop();
            
            int size = result.size()-1;
            if(!result.empty() && size>=p.second){
                result[p.second].push_back(p.first->val);
            }
            else{
                vector<int> v1 = {p.first->val};
                result.push_back(v1);
            }
        
            
            if(p.first->left){
                q.push(make_pair(p.first->left,p.second+1));
            }
            
            if(p.first->right){
                q.push(make_pair(p.first->right,p.second+1));
            }
            
        }
        return result;
    }
    
//     easy to understand cpp solution
//             vector<vector<int>> result;
//         if(!root){
//             return result;
//         }
        
//         queue<TreeNode*> q;
//         q.push(root);
            
//         while(!q.empty()){
//             int qlen = q.size();
            
//             vector<int> vec;
//             for(int i=0; i<qlen; i++){
//                 TreeNode* curr = q.front();
//                 q.pop();
                
//                 vec.push_back(curr->val);
                
//                 if(curr->left) q.push(curr->left);
//                 if(curr->right) q.push(curr->right);
//             }
//             result.push_back(vec);
//         }
//         return result;
    
    
    
};