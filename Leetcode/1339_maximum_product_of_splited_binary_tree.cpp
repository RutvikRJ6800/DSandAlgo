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
    long long int ans = INT_MIN;
    int maxProductHelper(TreeNode* root,long long int total){
        if(!root) return 0; // if root == NULL return sum = 0;

        int currSum = root->val + maxProductHelper(root->left, total) + maxProductHelper(root->right, total); // find currsum == sum for subtree 
                                                                                                             // rooted at current Node.

        ans = max(ans, (currSum * (total - currSum))); // update ans
        // total - currSum = sum of rest of tree other than subtree rooted at curr node.
    

        return currSum; // return currSum 
    }

    long long int findSum(TreeNode* root){
        if(!root) return 0;

        return root->val + findSum(root->left) + findSum(root->right);
    }
    int maxProduct(TreeNode* root) {
        // find sum of whole tree
        long long int total = findSum(root); // first find total sum of each node.
        maxProductHelper(root, total);
        
        return ans%1000000007; // final ans is mod ans % 10e9+7 
    }
};