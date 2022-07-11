// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    static bool cmp(pair<int,int> &pr1, pair<int,int> &pr2){
        if(pr1.second < pr2.second){
            return true;
        }
        if (pr1.second == pr2.second){
            if (pr1.first<pr2.first){
                return true;
            }
        }
        
        return false;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        // Your code here
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back(make_pair(start[i],end[i]));
        }

        sort(vec.begin(),vec.end(),cmp);
        int cnt=0;
        if(vec.size()==0)return cnt;

        cnt=1;
        int lastEnd=vec[0].second;

        for(int i=1; i<n; i++){
            if(lastEnd<vec[i].first){
                cnt++;
                lastEnd=vec[i].second;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends