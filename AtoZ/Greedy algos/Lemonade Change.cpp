// https://leetcode.com/problems/lemonade-change/description/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int fiveCoins = 0, tenCoins = 0;
        for(int b: bills){
            if(b == 5) fiveCoins++;
            else if(b == 10 && fiveCoins >= 1) {
                fiveCoins--;
                tenCoins++;
            }
            else if(b == 20 || (fiveCoins >= 3)){
                // cout<<"here"<<fiveCoins<<" "<<tenCoins<<endl;
                if(tenCoins >=1 && fiveCoins >= 1){
                    tenCoins--;
                    fiveCoins--;
                }
                else if(fiveCoins >= 3){
                    fiveCoins -= 3;
                }
                else return false;
            }
            else return false;
        }

        return true;
    }
};