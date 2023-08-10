// https://www.codingninjas.com/studio/problems/sorted-array_6613259?leftPanelTab=1

#include <bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int prevInserted = -1, i = 0, j= 0, lenA = a.size(), lenB = b.size();
    vector<int> ans;
    while(i<lenA && j<lenB){
        if(a[i] == b[j] && a[i] != prevInserted){
            ans.push_back(a[i]);
            prevInserted = a[i];
            i++;
            j++;
        }
        else if(a[i] < b[j]){
            if(prevInserted != a[i]){
                ans.push_back(a[i]);
                prevInserted = a[i];
            }
            i++;
        }
        else{
            if(prevInserted != b[j]){
                ans.push_back(b[j]);
                prevInserted = b[j];
            }
            j++;
        }
    }

    while(i<lenA){
        if(a[i] != prevInserted){
            prevInserted = a[i];
            ans.push_back(a[i]);
        }
        i++;
    }

    while(j<lenB){
        if(b[j] != prevInserted){
            prevInserted = b[j];
            ans.push_back(b[j]);
        }
        j++;
    }
    return ans;
}