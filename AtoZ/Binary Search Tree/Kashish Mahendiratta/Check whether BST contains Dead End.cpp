// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

bool solve(Node* root, int min, int max){
    if(!root) return false;
    
    // cout<<root->data<<", "<<min<<", "<<max<<endl;
    
    if(min == max) return true;
    
    if(solve(root->left, min, root->data - 1)) return true;
    if(solve(root->right, root->data + 1, max)) return true;
    
    else return false;
    
    
}
bool isDeadEnd(Node *root)
{
    //Your code here
    return solve(root, 1, 200);
}