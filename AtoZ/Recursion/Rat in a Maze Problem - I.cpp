// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    char direction[4] = {'D', 'R', 'U', 'L'};
    
    void solve(vector<vector<int>> &m, int n, int row, int col, vector<string> &ans, string &curr, vector<vector<bool>> &visited){
        if(row < 0 || col < 0 || row>=n || col>=n) return;
        else if(row==n-1 && col==n-1) {
            ans.push_back(curr);
            // return 1;
            return;
        }
        else if(m[row][col]==0 || visited[row][col]==1){
            // return 0;
            return;
        }
        else{
            // not blocked and not visited cell
            visited[row][col] = 1;
    
            
            for(int k=0; k<4; k++){
                int newrow = row + dx[k];
                int newcol = col + dy[k];
                curr.push_back(direction[k]);
                
                solve(m, n, newrow, newcol, ans, curr, visited);
                
                curr.pop_back();
            }
            // return paths;
            
            visited[row][col] = 0;
            return;
        }
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[n-1][n-1] == 0) return {"-1"};
        
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        vector<string> ans;
        string curr = "";
        
        
        solve(m, n, 0, 0, ans, curr, visited);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends