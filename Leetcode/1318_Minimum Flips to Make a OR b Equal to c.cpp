// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(c != 0 || a != 0 || b != 0){
            int cdigit = c%2, adigit = a % 2, bdigit = b%2;

            cout<<a<<","<<b<<","<<c;
            if(cdigit == 1){
                if(adigit == 0 && bdigit == 0){
                    cnt++;
                }
            }
            else{
                if(adigit == 1){
                    cnt++;
                }

                if(bdigit == 1){
                    cnt++;
                }
            }
            b = b/2;
            a = a/2;
            c = c/2;
            cout<<","<<cnt<<endl;
        }

        return cnt;
    }
};