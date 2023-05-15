// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0
class Solution {
public:
    bool isLeaf(Node* rt){
        if(!rt->left && !rt->right)return true;
        else return false;
    }
    void addLeftBoundary(Node * root, vector < int > & res) {
      Node * cur = root -> left;
      while (cur) {
        if (!isLeaf(cur)) res.push_back(cur -> data);
        if (cur -> left) cur = cur -> left;
        else cur = cur -> right;
      }
    }
    void addRightBoundary(Node * root, vector < int > & res) {
      Node * cur = root -> right;
      vector < int > tmp;
      while (cur) {
        if (!isLeaf(cur)) tmp.push_back(cur -> data);
        if (cur -> right) cur = cur -> right;
        else cur = cur -> left;
      }
      for (int i = tmp.size() - 1; i >= 0; --i) {
        res.push_back(tmp[i]);
      }
    }

    void addleaf(Node* root, vector<int> &ans){
        Node * rt = root;
        if(!rt->left && !rt->right){
            ans.push_back(rt->data);
        }
        
        if(rt->left)addleaf(rt->left, ans);
        if(rt->right)addleaf(rt->right, ans);
        
    }
    
    void addright(Node* root, vector<int> &ans){
        Node * rt = root -> right;
        vector<int> temp;
        
        while(rt){
            if(rt->left && rt->right)
            temp.push_back(rt->data);
            
            if(rt->right) rt = rt->right;
            else rt = rt->left;
        }
        
        for(int i = temp.size(); i>=1; i--){
            ans.push_back(temp[i]);
        }
    }
    
    void addleft(Node* root, vector<int> &ans){
        Node* rt = root;
        while(rt){
            if(rt->left && rt->right)
            ans.push_back(rt->data);
            
            if(rt->left) rt = rt->left;
            else 
                rt = rt->right;
        }
        
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        
        // find left border
        if(!root) return ans;
        
        if(!isLeaf(root))
        ans.push_back(root->data);
        addLeftBoundary(root, ans);
        // find leaf
        addleaf(root, ans);
        addRightBoundary(root, ans);
        // addright(root, ans);
        
        return ans;

    }
};