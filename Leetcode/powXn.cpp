// https://leetcode.com/problems/powx-n/submissions/
// https://www.youtube.com/watch?v=l0YC3876qxg&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=14
class Solution {
public:

// O(lgN) time solution
    double myPow(double x, int n) {
        if(n==1){
            return x;
        }
        if(n==0){
            return (double)1;
        }
        
        if(x==(double)1){
            return double(1);
        }
        long long nn =n;
        bool resipro=false;
        
        if(nn<0){
            resipro=true; 
            nn=nn*(-1);
        }
        
        double  ans = 1;
        int tpow = n;
        double base = x;
        
        while(nn!=0){
            if(nn%2==0){
                base =base*base;
                nn = nn/2;
            }
            else{
                ans = ans * base;
                nn--;
            }
        }
                 
        if(resipro){
            ans = 1/ans;
        }
        
        return ans;
    }
};