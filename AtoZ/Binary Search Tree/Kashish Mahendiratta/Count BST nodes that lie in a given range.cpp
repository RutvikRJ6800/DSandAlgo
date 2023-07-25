// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

class Solution{
public:

    int count(Node* root, int l, int h){
        if(!root) return 0;
        int inRange = 0;
        if(root->data >= l && root->data <= h) inRange++;
        
        if(root->data >= l)
        inRange += count(root->left, l, h);
        
        if(root->data <= h)
        inRange += count(root->right, l, h);
        
        return inRange;
    }
    
    int getCount(Node *root, int l, int h)
    {
      // your code goes here 
      return count(root, l , h);
    }
};