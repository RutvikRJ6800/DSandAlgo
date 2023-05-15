// 987. Vertical Order Traversal of a Binary Tree

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
    void inorder(TreeNode* rt, int r, int c,  map<int, map<int, vector<int>>> &hm){
        if(!rt) return;

        hm[c][r].push_back(rt->val);

        inorder(rt->left, r + 1, c - 1, hm);
        inorder(rt->right, r + 1, c + 1, hm);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> hm;

        // travese inorder and store node in their column 
        inorder(root, 0, 0, hm);

        // crate datastructer to return result
        vector<vector<int>> ans;
        for (auto i : hm){
            // map<int, vector<int>> rhm;
            vector<int> tempRes;
            for(auto j: i.second){
                vector<int> vec;
                for(int k=0; k<j.second.size(); k++){
                    vec.push_back(j.second[k]);
                }
                sort(vec.begin(), vec.end());
                tempRes.insert(tempRes.end(), vec.begin(), vec.end());
            }
            ans.push_back(tempRes);
        }
        return ans;
    }
};