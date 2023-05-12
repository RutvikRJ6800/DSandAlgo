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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int dir = 1; // 1 denote next traversal should be from right to left;
                    // 0 denote next traversal should be from left to right.
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push(root);

        while(!q.empty()){
            

            vector<TreeNode*> nodeToBeVisited;
            while(!q.empty()){
                nodeToBeVisited.push_back(q.front());
                q.pop();
            }

            vector<int> val;
            for(int i=0; i<nodeToBeVisited.size(); i++){
                val.push_back(nodeToBeVisited[i]->val);
                if(nodeToBeVisited[i]->left) q.push(nodeToBeVisited[i]->left);
                if(nodeToBeVisited[i]->right) q.push(nodeToBeVisited[i]->right);
            }

            if(!dir){
                reverse(val.begin(), val.end());
            }

            dir = !dir;

            ans.push_back(val);
        }
        return ans;
    }
};