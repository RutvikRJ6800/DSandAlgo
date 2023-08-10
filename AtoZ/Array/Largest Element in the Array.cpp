// https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?leftPanelTab=0

#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int largestElement = INT_MIN;
    for(auto num: arr){
        largestElement = max(largestElement, num);
    }
    return largestElement;
}
