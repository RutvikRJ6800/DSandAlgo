// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorderTraversal(Node* root, vector<int> &inorder){
        if(!root) return;
        else{
            inorderTraversal(root->left, inorder);
            inorder.push_back(root->data);
            inorderTraversal(root->right, inorder);
        }
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       // Takes O(logN + logM) space
       // insort O(hight1 + hight2) space
       
       stack<Node*> st1, st2;
       vector<int> ans;
       
       Node* t1 = root1;
       while(t1){
           st1.push(t1);
           t1 = t1->left;
       }
       
       t1 = root2;
       while(t1){
           st2.push(t1);
           t1 = t1->left;
       }
       
       
       
       while(!st1.empty() && !st2.empty()){
            if(st1.top()->data <= st2.top()->data){
                t1 = st1.top();
                ans.push_back(t1->data);
                st1.pop();
                
                t1 = t1->right;
                while(t1){
                    st1.push(t1);
                    t1 = t1 ->left;
                }
            }
            else{
                t1 = st2.top();
                ans.push_back(t1->data);
                st2.pop();
                
                t1 = t1->right;
                while(t1){
                    st2.push(t1);
                    t1 = t1 ->left;
                }
            }
       }
       
       while(!st1.empty()){
           t1 = st1.top();
            ans.push_back(t1->data);
            st1.pop();
            
            t1 = t1->right;
            while(t1){
                st1.push(t1);
                t1 = t1 ->left;
            }
       }
       
       while(!st2.empty()){
            t1 = st2.top();
            ans.push_back(t1->data);
            st2.pop();
            
            t1 = t1->right;
            while(t1){
                st2.push(t1);
                t1 = t1 ->left;
            }
       }
       
       return ans;
       
       /*
       Takes O(N + M) space and Time
       vector<int> inorder1, inorder2, ans;
        inorderTraversal(root1, inorder1);
        inorderTraversal(root2, inorder2);
        
        int n1 = inorder1.size(), n2 = inorder2.size();
        int i=0, j = 0;
        
        while(i<n1 && j< n2){
            if(inorder1[i] < inorder2[j]){
                ans.push_back(inorder1[i]);
                i++;
            }
            else{
                ans.push_back(inorder2[j++]);
            }
        }
        
        while(i<n1){
            ans.push_back(inorder1[i++]);
        }
        
        while(j<n1){
            ans.push_back(inorder2[j++]);
        }
        
        return ans;
        
        */
    }
};