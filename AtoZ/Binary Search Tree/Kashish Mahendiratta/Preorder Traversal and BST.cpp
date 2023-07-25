// https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1


class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        // code here
        stack<int> st;
        
        int parent = INT_MIN;
        
        for(int i=0; i<N; i++){
            while(!st.empty() && st.top() < arr[i]){
                parent = st.top();
                st.pop();
            }
            
            if(parent > arr[i]) return false;
            st.push(arr[i]);
        }
        
        return true;
    }
};