// 
// https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int sz = q.size();
            long long first = q.front().second, second = q.back().second;
            while(sz--){
                auto [node, num] = q.front();
                q.pop();

                num--;

                if(num<0) num = 0;

                if(node->left){
                    q.push({node->left, (2*num)+1});
                }
                if(node->right){
                    q.push({node->right, (2*num)+2});
                }
            }

            // update ans
            if (ans < (second-first + 1)){
                ans = (second-first + 1);
            }
        }

        return ans;
    }
};