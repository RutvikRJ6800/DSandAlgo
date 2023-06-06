// https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool rec(TreeNode* A, int B, vector<int> &ans){
    if(!A) return false;
    
    bool left = rec(A->left, B, ans);
    bool right = rec(A->right, B, ans);
    

    if(left || right){
        // B found some where in child
        // so consider current root in path
        ans.push_back(A->val);
        return true;
    }
    
    // check if curr node contains the target value of not?
    if(A->val == B){
        ans.push_back(A->val);
        return true;
    }
    
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(!A) return ans;
    
    bool res = rec(A, B, ans);
    // if(res)
    //     ans.push_back(A->val);
        
    reverse(ans.begin(), ans.end());
    return ans;
}
