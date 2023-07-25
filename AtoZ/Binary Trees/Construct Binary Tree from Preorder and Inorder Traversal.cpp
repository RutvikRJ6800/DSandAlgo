// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

class Solution {
public:
    TreeNode* addNode(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, unordered_map<int, int> & inorderIndex){
        if(ps>pe || is>ie || ps<0 || is <0 || pe>= preorder.size() || ie >= inorder.size()){
            return nullptr;
        }
        int root = preorder[ps];
        cout<<root<<": pre:"<<ps<<","<<pe<<", inor:"<<is<<","<<ie<<endl;
        int leftNodes = inorderIndex[root] - is;
        int rightNodes = ie - inorderIndex[root];

        TreeNode* curr = new TreeNode(root);
        curr->left = addNode(preorder, ps+1, ps+leftNodes, inorder, is, is + leftNodes - 1, inorderIndex);
        curr->right = addNode(preorder, ps+leftNodes+1, pe, inorder, is + leftNodes+1, ie, inorderIndex);

        return curr;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        int size = inorder.size();
        for(int i=0; i<size; i++){
            inorderIndex[inorder[i]] = i;
        }

        return addNode(preorder, 0, size-1, inorder, 0, size-1, inorderIndex);
    }
};