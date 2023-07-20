// https://leetcode.com/problems/asteroid-collision/description/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int w: asteroids){
            if(st.empty()){
                st.push(w);
            }
            // check is colision posiblle of not?
            else if(st.top() > 0 && w < 0){
                if(st.top() + w == 0){
                    // both will be destroed
                    st.pop();
                    continue;
                }
                else if(st.top() > abs(w)) continue;
                while(!st.empty() && st.top() > 0 && w < 0 && st.top() < abs(w)){
                    st.pop();
                }
                // st.push(w);
                if(!st.empty() && st.top() + w == 0){
                    st.pop();
                    continue;
                }
                else if(!st.empty() && st.top() > 0 && st.top() > w){
                    continue;
                }
                else{
                    st.push(w);
                }
            }
            else{
                st.push(w);
            }
            
            // if(st.empty()){
            //     st.push(w);
            // }
            // else if(!st.empty() && st.top() < 0){
            //     st.push(w);
            // }
            // else if(!st.empty() && st.top() > 0 && )
        }

        vector<int> ans;
        while(!st.empty()){
            cout<<st.top()<<",";
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};