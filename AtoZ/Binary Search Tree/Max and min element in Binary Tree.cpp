// https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1

class Solution
{
public:
    int findMax(Node *root)
    {
        //code here
        if(!root->right) return root->data;
        
        while(root->right){
            root = root->right;
        }
        
        return root->data;
    }
    int findMin(Node *root)
    {
        //code here
        
        if(!root->left) return root->data;
        
        while(root->left){
            root = root->left;
        }
        
        return root->data;
    }
};