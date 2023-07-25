// https://leetcode.com/problems/binary-tree-inorder-traversal/


vector<int> inorderTraversal(TreeNode* root) {

        // Moris inorder -> O(N) time and O(1) space
        TreeNode* curr = root;
        vector<int> inorder;
        while(curr){
            if(!curr->left){
                // if no left tree present -> put this node in arry and goto to right;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* temp = curr->left;
                while(temp->right && temp -> right != curr){
                    temp = temp->right;
                }

                if(!temp->right){
                    // left tree doesn't have thread
                    // so make it and go to left tree
                    temp->right = curr;
                    curr = curr->left;
                }
                else{
                    // left tree have have thread
                    // means we already traversed left tree so
                    // remove thread and go to right tree

                    temp->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;

        /*
        INORDER NORMAL -> O(n) space and time

        stack<pair<TreeNode*, bool>> st;
        vector<int> ans;
        st.push({root, 1});

        while(!st.empty()){
            TreeNode* node = st.top().first;
            bool canVisitLeft = st.top().second;
            
            st.pop();
            if(!node) continue;

            if(canVisitLeft){
                st.push({node, 0});
                st.push({node->left, 1});
            }
            else{
                ans.push_back(node->val);
                st.push({node->right, 1});
            }
        }
        return ans;
        */
    }
};