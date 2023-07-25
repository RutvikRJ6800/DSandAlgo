// https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorderTraversal(Node* root, vector<int> &inorder){
        if(!root) return;
        else{
            inorderTraversal(root->left, inorder);
            inorder.push_back(root->data);
            inorderTraversal(root->right, inorder);
        }
    }
    int fillTree(Node* root, int idx, vector<int> &inorder){
        if(idx >= inorder.size()) return 0;
        if(!root) return 0;
        
        // fill left tree
        int leftEle = fillTree(root->left, idx, inorder);
        root->data = inorder[idx + leftEle];
        int rightEle = fillTree(root->right, idx + 1 + leftEle, inorder);
        
        return leftEle + rightEle + 1;
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> inorder;
        inorderTraversal(root, inorder);
        
        sort(inorder.begin(), inorder.end());
        
        // for(int num: inorder){
        //     cout<<num<<",";
        // }
        
        fillTree(root, 0, inorder);
        
        return root;
    }
};