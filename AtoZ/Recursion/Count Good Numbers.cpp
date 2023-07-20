// https://leetcode.com/problems/count-good-numbers/description/
#define MOD 1000000007
class Solution {
public:
    // bool isPrime(int num){

    // }
    long long power(long long n, long long b){
        if(b==0) return 1;
        else if(b%2 == 0){
            return (power(n*n % MOD, b/2))% MOD;
        }
        else
        return (n * power(n*n % MOD, (b-1)/2)) % MOD;
    }
   
    int countGoodNumbers(long long n) {
        long long numOfOddSpaces = n / 2;
        long long numOfEvenSpaces = n / 2 + n%2;

        return ((power(5LL, numOfEvenSpaces) % MOD) *( power(4LL, numOfOddSpaces) % MOD)) % MOD;
    }
};