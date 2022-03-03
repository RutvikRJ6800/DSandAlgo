// https://www.geeksforgeeks.org/avl-tree-set-2-deletion/?ref=lbp
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int info;
    int height;
    struct Node* left;
    struct Node* right;
    
    Node(int val){ 
        info = val;
        left=NULL;
        right=NULL;
        height=1;
    }
};

void inOrder(Node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}
void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int getHeight(Node* a){
    if(a==NULL) return 0;
    
    return a->height;
}


int max(int a, int b){
    return (a>b)?a:b;
}

Node * rotateLeft(Node* a){
    Node* s=a->right;
    Node* t = s->left;

    s->left=a;
    a->right= t;

    a->height = 1+max(getHeight(a->left),getHeight(a->right));
    s->height= 1+max(getHeight(s->left),getHeight(s->right));
    return s;
}

Node * rotateRight(Node* a){
    Node* s=a->left;
    Node* t = s->right;

    s->right=a;
    a->left= t;

    a->height = 1+max(getHeight(a->left),getHeight(a->right));
    s->height= 1+max(getHeight(s->left),getHeight(s->right));
    return s;
}

int getBalance(Node * a){
    if(a==NULL){
        return 0;
    }
    else
    return getHeight(a->left)-getHeight(a->right);
}

Node* minValueNode(Node * a){

    Node* current = a;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

Node * insert(Node * ptr,int key){
    if(ptr==NULL){
        return new Node(key);
    }
    else if(key<=ptr->info){
        ptr->left=insert(ptr->left,key);
    }
    else if(key>ptr->info){
        ptr->right=insert(ptr->right,key);
    }
    else{
        return ptr;
    }

    // change hight of ptr
    ptr->height=1+max(getHeight(ptr->left),getHeight(ptr->right));

    int balance = getBalance(ptr);

    if (balance > 1 && key < ptr->left->info)
		return rotateRight(ptr);

	// Right Right Case
	if (balance < -1 && key > ptr->right->info)
		return rotateLeft(ptr);

	// Left Right Case
	if (balance > 1 && key > ptr->left->info)
	{
		ptr->left = rotateLeft(ptr->left);
		return rotateRight(ptr);
	}

	// Right Left Case
	if (balance < -1 && key < ptr->right->info)
	{
		ptr->right = rotateRight(ptr->right);
		return rotateLeft(ptr);
	}

    return ptr;


}

Node * deleteNode(Node * ptr,int key){
    if(ptr==NULL){
        return ptr;
    }
    else if(key<ptr->info){
        ptr->left=deleteNode(ptr->left,key);
    }
    else if(key>ptr->info){
        ptr->right=deleteNode(ptr->right,key);
    }
    else{
        if(ptr->left==NULL || ptr->right==NULL ){
            Node* temp = ptr->left?ptr->left:ptr->right;
            if(temp==NULL){
                temp=ptr;
                ptr=NULL;
                free(temp);
            }
            else{

                *ptr=*temp;
                free(temp);

            }
        }
        else{
            // node to be deleted has 2 children;
            Node * iS = minValueNode(ptr->right);
            ptr->info=iS->info;
            ptr->right=deleteNode(iS->right,key);

        }
        
    }
    if (ptr == NULL)
    return ptr;

    // change hight of ptr
    ptr->height=1+max(getHeight(ptr->left),getHeight(ptr->right));

    int balance = getBalance(ptr);

    if (balance > 1 && key < ptr->left->info)
		return rotateRight(ptr);

	// Right Right Case
	if (balance < -1 && key > ptr->right->info)
		return rotateLeft(ptr);

	// Left Right Case
	if (balance > 1 && key > ptr->left->info)
	{
		ptr->left = rotateLeft(ptr->left);
		return rotateRight(ptr);
	}

	// Right Left Case
	if (balance < -1 && key < ptr->right->info)
	{
		ptr->right = rotateRight(ptr->right);
		return rotateLeft(ptr);
	}

    return ptr;


}



int main(){

    Node *root = NULL;
     
    // /* Constructing tree given in
    // the above figure */
    // // root = insert(root, 40);
    // // root = insert(root, 10);
    // // root = insert(root, 30);
    // // root = insert(root, 20);
    // // root = insert(root, 50);
    // // root = insert(root, 25);
    // root = insert(root, 10);
	// root = insert(root, 20);
	// root = insert(root, 30);
	// root = insert(root, 40);
	// root = insert(root, 50);
	// root = insert(root, 25);


    // cout << "Preorder traversal of the "
    //         "constructed AVL tree is \n";
    // preOrder(root);
    // cout<<endl;
    // cout << "INorder traversal of the "
    //         "constructed AVL tree is \n";
    // inOrder(root);
      /* Constructing tree given in
    the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
 
    /* The constructed AVL Tree would be
            9
        / \
        1 10
        / \ \
    0 5 11
    / / \
    -1 2 6
    */
 
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);
 
    root = deleteNode(root, 10);
 
    /* The AVL Tree after deletion of 10
            1
        / \
        0 9
        / / \
    -1 5     11
        / \
        2 6
    */
 
    cout << "\nPreorder traversal after"
         << " deletion of 10 \n";
    preOrder(root);
    cout<<endl;
    cout << "INorder traversal of the "
            "constructed AVL tree is \n";
    inOrder(root);
    return 0;

}
