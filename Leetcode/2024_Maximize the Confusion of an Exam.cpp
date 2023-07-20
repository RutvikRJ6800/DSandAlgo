// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = INT_MIN, left = 0, n=answerKey.size();
        unordered_map<char, int> count;

        for(int i=0; i<k; i++){
            count[answerKey[i]]++;
        }

        for(int right=k; right<n; right++){
            count[answerKey[right]]++;

            // check invalidity
            while(min(count['T'], count['F']) > k){
                count[answerKey[left]]--;
                left++;
            }
            ans = max(ans, right - left+1);
        }
        return ans != INT_MIN ? ans:k;
    }
};