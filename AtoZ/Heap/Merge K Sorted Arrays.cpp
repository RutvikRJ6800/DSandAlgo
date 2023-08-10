// https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<int, vector<int>, greater<int>> minH;

        for(auto vec: kArrays){

            for(int num: vec){
                minH.push(num);
            }
        }

        vector<int> ans;
        while(minH.size() > 0){
            ans.push_back(minH.top());
            minH.pop();
        }

        return ans;
}
