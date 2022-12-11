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
    int ans = INT_MIN;
    int rec(TreeNode* root){
        if(!root) return 0;

        int leftPath = rec(root->left);
        int rightPath = rec(root->right);
        int vPath = leftPath + rightPath + root->val;
        leftPath += root->val;
        rightPath += root->val;

        ans = max(ans, max(vPath,max(root->val,max(leftPath, rightPath))));

        cout<<"NODE: "<<root->val<<"::"<<"leftPath: "<<leftPath<<". & rightPath: "<<rightPath<<". &vPath: "<<vPath<<". &ans: ";
        cout<<ans<<endl;

        return max(root->val, max(leftPath, rightPath));
    }
    
    int maxPathSum(TreeNode* root) {
        
        rec(root);

        return ans;
    }
};