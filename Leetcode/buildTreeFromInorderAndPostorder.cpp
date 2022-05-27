/**
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    
//     time O(N) and space O(N) bcoz recursion use auxilary stack
    
    TreeNode* build(vector<int>& inorder,int is,int ie, vector<int>& postorder,int ps,int pe,unordered_map<int,int> &hs){
        if(is>ie || ps>pe){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[pe]);
        
        int inRoot = hs[postorder[pe]];
        int numsLeft = inRoot-is;
        
        root->left = build(inorder,is,inRoot-1,postorder,ps,ps+numsLeft-1,hs);
        
        root->right = build(inorder, inRoot+1, ie, postorder, ps+numsLeft,pe-1,hs);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.size()!=postorder.size()){
            return NULL;
        }
         unordered_map <int,int> hs;
        for(int i=0; i<inorder.size(); i++){
            hs[inorder[i]] = i;
        }
        
        return build(inorder,0,inorder.size()-1, postorder, 0, postorder.size()-1,hs);
        
        
    }
};