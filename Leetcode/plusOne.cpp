// https://leetcode.com/problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx= digits.size()-1;
        
        while(idx!=-1){
            ++digits[idx];
            if(digits[idx]==10){
                digits[idx]=0;
                idx--;
                continue;
            }
            else{
                break;
            }
            
        }
        if(idx==-1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};