// https://www.codingninjas.com/studio/problems/superior-elements_6783446

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int> ans;
    int maxRight = a[a.size()-1];
    ans.push_back(maxRight);
    for(int i=a.size()-2; i>=0; i--){
        if(maxRight < a[i]){
            ans.push_back(a[i]);
            maxRight = a[i];
        }
    }
    return ans;
}