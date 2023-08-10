// https://leetcode.com/problems/shortest-string-that-contains-three-strings/description/

class Solution {
public:
    string merge(string A, string &B){
        if(A.find(B) != string::npos) return A;
        int lenA = A.size(), lenB = B.size();
        string curr = "";
        int i=min(lenA, lenB), j=0;
        for(int i=min(lenA, lenB); i>=0; i--){
            if(A.substr(lenA-i, i).find(B.substr(0, i)) != string::npos){
                return A + B.substr(i, lenB-i);
            }
        }
        return A + B;
    }
    void updateAns(string &temp, string &ans){
        if(temp.size() < ans.size()){
            ans = temp;
        }
        else if(temp.size() == ans.size()){
            for(int i=0; i<temp.size(); i++){
                if(temp[i] < ans[i]){
                    ans = temp;
                    return;
                }
                else if(temp[i] > ans[i]) return;
            }
        }
        return;
    }
    void checkCombination(string &A, string &B, string &C, string &ans){
        string tempAns = merge(merge(A,B),C);
        cout<<tempAns<<endl;
        updateAns(tempAns, ans);
        tempAns = merge(merge(A,C),B);
        // cout<<tempAns<<endl;
        updateAns(tempAns, ans);

        tempAns = merge(merge(B,C),A);
        // cout<<tempAns<<endl;
        updateAns(tempAns, ans);

        tempAns = merge(merge(B,A),C);
        // cout<<tempAns<<endl;
        updateAns(tempAns, ans);

        tempAns = merge(merge(C,A),B);
        // cout<<tempAns<<endl;
        updateAns(tempAns, ans);

        tempAns = merge(merge(C,B),A);
        // cout<<tempAns<<endl;
        updateAns(tempAns, ans);

    }


    string minimumString(string a, string b, string c) {
        string ans = a + b + c;
        checkCombination(a, b, c, ans);

        return ans;
    }
};