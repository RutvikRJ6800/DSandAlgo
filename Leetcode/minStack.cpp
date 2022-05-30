// https://leetcode.com/problems/min-stack/submissions/
//  https://www.youtube.com/watch?v=V09NfaGf2ao&ab_channel=takeUforward
#include<bits/stdc++.h>
using namespace std;


// this code time -O(N) & space -O(2*N) because stack stores pair of (element, min so far);
// class MinStack {
// public:
//     stack<pair<long long,long long>> st;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(st.empty()){
//             st.push(make_pair(val,val));
//         }
//         else{
//             long long min=st.top().second;
//             if(val<min){
//                 st.push(make_pair(val,val));
//             }
//             else{
//                 st.push(make_pair(val,min));
//             }
//         }               
//     }
                        
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         if(st.empty()){
//             return -1;
//         }
//         else
//             return st.top().first;
//     }
    
//     int getMin() {
//         if(st.empty()){
//             return -1;
//         }
//         else
//             return st.top().second;
//     }
// };






// below code-time O(N) and space O(N) - litle bit efficient in space


class MinStack {
public:
    stack<long long> st;
    long long mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            mini = val;
            st.push(val);
            return;
        }
        if(mini>val){
            long long modifiedValue = 2*1LL*val - mini;
            st.push(modifiedValue);
            mini = val;
        }
        else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.empty())return;
        long long tp = st.top();
        if(tp<mini){
//             top is the curr min value in the stack and we need to delete it
            long long ret = mini;
            mini = 2*mini*1LL - tp; // set new min as previous min
            st.pop();
        }
        else{
//             top is not the minimum so without worries just pop it
            st.pop();
        }
        
    }
    
    int top() {
        if(st.empty()) return -1;
        long long tp = st.top();
        
        if(tp<mini){
            return mini; // because tp is the current min in stack
        }
        else
            return tp;
    }
    
    int getMin() {
        if(st.empty())
            return -1;
        else
            return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */