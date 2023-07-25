// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(TreeNode* root, string &ans){
        if(!root){
            ans += " " + to_string(-1001);
            return;
        }
        else{
            ans += " " + to_string(root->val);

            preorder(root->left, ans);
            preorder(root->right, ans);
        }
    }
    string serialize(TreeNode* root) {
        string ans = "";

        preorder(root, ans);

        cout<<ans<<endl;

        return ans;
    }

    // Decodes your encoded data to tree.

    pair<TreeNode*, int> createTree(int idx, vector<int> &vec){
        if(idx >= vec.size()){
            return {nullptr,1} ;
        }
        int node = vec[idx];

        if(node != -1001){
            TreeNode* tr = new TreeNode(node);
            pair<TreeNode*, int> p1, p2;
            p1 = createTree(idx + 1, vec);
            tr->left = p1.first;
            p2 = createTree(idx + p1.second + 1, vec);
            tr->right = p2.first;

            return {tr, p1.second + p2.second + 1};
        }

        else
        return {nullptr, 1};
    }
    TreeNode* deserialize(string data) {
        int n = data.size();
        vector<int> vec;

        string curr = "";
        for(int i=0; i<n; i++){
            if(data[i] == ' '){
                // got delimeter
                if(curr.size() > 0){
                    vec.push_back(stoi(curr));
                }
                curr = "";
            }
            else{
                curr.push_back(data[i]);
            }
        }

        if(curr.size() > 0){
            vec.push_back(stoi(curr));
        }

        // for(auto num: vec){
        //     cout<<num<<","; 
        // }

        return createTree(0, vec).first;


        // return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));