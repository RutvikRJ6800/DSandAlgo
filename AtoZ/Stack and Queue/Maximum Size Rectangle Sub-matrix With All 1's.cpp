// https://www.codingninjas.com/studio/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	// Write your code here.
	vector<int> heights(m, 0);
	int ans = INT_MIN;
	for(int r=0; r<n; r++){

		for(int j=0; j<m; j++){
			if(mat[r][j] == 0){
				heights[j] = 0;
			}
			else{
				heights[j] += mat[r][j]; 
			}
			// cout<<heights[j]<<", ";
		}
		// cout<<endl;

		stack<pair<int, int>> st;
        vector<int> ans1(m, 0);

        for(int i=0; i<m; i++){
            int ele = heights[i];
            while(!st.empty() && st.top().second >= ele){
                st.pop();
            }

            if(st.empty()){
                ans1[i] = -1;
            }
            else{
                ans1[i] = st.top().first;
            }
            st.push({i, ele});
        }

        stack<pair<int, int>> st2;
        vector<int> ans2(m, 0);

        for(int i=m-1; i>=0; i--){
            int ele = heights[i];
            
            while(!st2.empty() && st2.top().second >= ele){
                st2.pop();
            }

            if(st2.empty()){
                // ans2[i] = max(ele*(i+1), ele);
                ans2[i] = m;
            }
            else{
                ans2[i] = st2.top().first;
            }
            st2.push({i, ele});
        }

        // int ans = INT_MIN;

        for(int i=0; i<m; i++){
            if(ans < (ans2[i] - ans1[i]-1)*heights[i]){
				ans = (ans2[i] - ans1[i]-1)*heights[i];
				// cout<<"changed"<<ans<<endl;
			}
        }
		

	}

	return ans;
}