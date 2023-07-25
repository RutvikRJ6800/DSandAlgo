// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* createBBST(int start, int end, vector<int> & nums){
        if(start>end) return nullptr;
        if(start == end) return new TreeNode(nums[start]);

        int mid = start + (end-start)/2;

        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = createBBST(start, mid-1, nums);
        curr->right = createBBST(mid+1, end, nums);

        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size()-1;

        return createBBST(0, n, nums);
    }
};