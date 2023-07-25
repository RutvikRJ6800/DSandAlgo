// https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1


Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(!root) return nullptr;
    
    if(root->data == X){
        // node found
        Node* lst = root->left, *rst = root->right;
        
        if(!lst & !rst) return nullptr;
        else if(!lst && rst){
            return rst;
        }
        else if(lst && !rst){
            return lst;
        }
        else{
            Node* temp = rst;
            while(temp->left){
                temp = temp->left;
            }
            
            temp->left = lst;
            
            return rst;
        }
        
    }
    else if(root->data < X) root->right = deleteNode(root->right, X);
    else
        root->left = deleteNode(root->left, X);
    
}
