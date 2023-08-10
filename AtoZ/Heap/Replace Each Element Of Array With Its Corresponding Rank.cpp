// https://www.codingninjas.com/studio/problems/replace-each-element-of-array-with-its-corresponding-rank_975384?leftPanelTab=0

#include<bits/stdc++.h>
typedef pair<int, int> pi;

vector<int> replaceWithRank(vector<int> &arr, int n) {
    // Write your code here.
    priority_queue<pi, vector<pi>, greater<pi>> minH;
    for(int i=0; i<n; i++){
        minH.push({arr[i], i});
    }

    vector<int> ans(n);
    int currRank = 0, currEle = INT_MIN;

    while(minH.size()>0){
        pi p = minH.top();
        minH.pop();
        if(p.first == currEle) ans[p.second] = currRank;
        else{
            currRank++;
            currEle = p.first;
            ans[p.second] = currRank;
        }
    }
    return ans;
}