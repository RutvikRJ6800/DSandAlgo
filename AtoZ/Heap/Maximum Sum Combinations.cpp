// https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    priority_queue<int, vector<int>, greater<int>> minh;
    int n = A.size();
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            int currSum = A[i] + B[j];
            if(minh.size()<=C) minh.push(currSum);
            else{
                // minh size greater or equal to C
                if(minh.top() < currSum){
                    // remove top and add currSum
                    minh.pop();
                    minh.push(currSum);
                }
                else break;
            }
        }
    }
    
    vector<int> ans;
    while(!minh.empty()){
        ans.push_back(minh.top());
        minh.pop();
    }
    reverse(ans.begin(), ans.end());
    ans.pop_back();
    return ans;
}
