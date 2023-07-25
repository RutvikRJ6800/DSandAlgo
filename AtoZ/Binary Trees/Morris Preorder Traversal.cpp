// https://practice.geeksforgeeks.org/problems/preorder-traversal/1


vector <int> preorder(Node* root)
{
  // Your code here
  Node* curr = root;
  vector<int> preorder;

	while(curr){
		if(!curr->left){
			preorder.push_back(curr->data);
			curr = curr->right;
		}
		else{
			// left node exist

			Node* temp = curr->left;

			while(temp->right && temp->right != curr){
				temp = temp->right;
			}

			if(!temp->right){
			    preorder.push_back(curr->data);
				temp->right = curr;
				curr = curr->left;
			}
			else{
				// break thread and go to right
				temp->right = NULL;
				curr = curr->right;
			}
		}
	}

	return preorder;
}