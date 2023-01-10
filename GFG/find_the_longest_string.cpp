// https://practice.geeksforgeeks.org/problems/8d157f11af5416087251513cfc38ffc4d23be308/1
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    class Node{
        public:
        
        Node* alpha[26];
        bool isEnd;
        
        Node(){
            for(int i=0; i<26; i++){
                alpha[i] = NULL;
            }
            
            isEnd = false;
        }
    };
    class Trie{
        public:
        Node* root;
        
        Trie(){
            root = new Node();
        }
        
        void insert(string s){
            Node* rt = root;
            
            for(int i=0; i<s.size(); i++){
                char c = s[i];
                
                if(!rt->alpha[c-'a']){
                    rt->alpha[c-'a'] = new Node();
                }
                rt = rt->alpha[c-'a'];
            }
            rt->isEnd = true;
        }
        
        void printTrieHelper(Node* rt, string currentString){
        
            if(rt->isEnd == true){
                cout<<currentString<<endl;
            }
    
            for(size_t i=0; i<26; i++){
                if(rt->alpha[i]){
                    char c = 'a'+i;
                    string temp = currentString +c;
                    printTrieHelper(rt->alpha[i], temp );
                }
        
            }
        }
    
        void printTrie(){
            string temp = "";
            printTrieHelper(root, temp);
        }
        
        void solve(Node* rt, string &ans, string curr){
            //cout<<"this"<<endl;
            if(!rt) return; // if null return coz we can't do anything now
            if(!rt->isEnd) return; // if word is not terminating here then return
                                    // coz we will not get prefix of next words.
            
            // traverse all the posible words from this node
            for(int i=0; i<26; i++){
                if(rt->alpha[i] != NULL){
                    string temp = curr + (char)('a'+i); // temp is the string that we got now.
                    //cout<<"$$"<<temp<<endl;
                    solve(rt->alpha[i], ans, temp);
                }
            }
            
            if(ans.size() < curr.size()) ans = curr; // if size of ans string is less then curr
                                                    // just change the ans
                                                    // <= will not work, b'coz we need lexi small string
            return;
            
        }
    };
    
    string longestString(vector<string> &words)
    {
        // code here
        Trie *tr = new Trie();
        int n = words.size();
        
        for(int i=0; i<n; i++){
            tr->insert(words[i]);
        }
        
        Node* rt = tr->root;
        
        string ans = "";
        
        for(int i=0; i<26; i++){
            if(rt->alpha[i]){
                string st = "";
                st.push_back((char)(i+'a'));
                // cout<<"here:"<<st;
                tr->solve(rt->alpha[i], ans, st);
            }
        }

        // cout<<"below is Tie"<<endl;            
        // tr->printTrie();
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends