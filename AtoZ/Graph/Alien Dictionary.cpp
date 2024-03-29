// https://practice.geeksforgeeks.org/problems/alien-dictionary/1


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> indegree(K, 0);
        vector<int> adj[K];
        
        for(int i=1; i<N; ++i){
            string s1 = dict[i-1];
            string s2 = dict[i];
            int p = 0;
            while(p<s1.size() && p<s2.size()){
                if(s1[p] != s2[p]){
                    adj[s1[p] - 'a'].push_back(s2[p] - 'a');
                    indegree[s2[p] - 'a']++;
                    break;
                }
                p++;
            }
        }
        
        // for(auto it:indegree){
        //     cout<<it<<",";
        // }
        // cout<<endl;
        
        queue<int> q;
        string ans;
        for(int i=0; i<K; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node+'a');
            
            for(auto it: adj[node]){
                indegree[it]--;
                
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        // cout<<ans;
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends