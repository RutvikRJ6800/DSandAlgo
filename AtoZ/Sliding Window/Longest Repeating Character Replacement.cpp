// https://leetcode.com/problems/longest-repeating-character-replacement/description/


class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), i = 0, j=0, cnt = 0, ans = 1, totalchar = 0, maxcharfreq = 0;
        vector<int> freq(26, 0);

        while(j<n){
            freq[s[j] - 'A']++;
            if(freq[s[j] - 'A'] > maxcharfreq) maxcharfreq = freq[s[j] - 'A'];
            totalchar++;

            // vector<int> temp(freq.begin(), freq.end());
            // sort(temp.begin(), temp.end());
            cnt = totalchar - maxcharfreq;

            if(cnt < k){
                ans = max(ans, j - i + 1);
                j++;
            }
            else if(cnt == k){
                ans = max(ans, j - i + 1);
                j++;
            }
            else if(cnt > k){
                
                while(cnt > k){
                    freq[s[i] - 'A']--;
                    totalchar--;

                    // vector<int> temp(freq.begin(), freq.end());
                    // sort(temp.begin(), temp.end());
                    cnt = totalchar - maxcharfreq;

                    i++;
                }

                if(cnt == k){
                    ans = max(ans, j - i + 1);
                }
                j++;

            }
        }
        return ans;
    }
};