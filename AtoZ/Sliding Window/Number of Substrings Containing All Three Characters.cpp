// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), i = 0, j=0, cnt = 0, ans = 0;
        int freq[26] = {0};

        // for(int i=0; i<n; i++){
        //     cout<<(s[i] - 'a')<<", ";
        // }
        // cout<<endl;

        while(j<n){
            // cout<<
            if(freq[s[j] - 'a'] == 0){
               cnt++;
            } 
            freq[s[j] - 'a']++;

            if(cnt < 3){
                j++;
            }
            else if(cnt == 3){
                // ans += (n-j);

                while(cnt == 3 && i<j){
                    ans += (n-j);
                    if(freq[s[i] - 'a']  == 1){
                        cnt--;
                    } 

                    freq[s[i]-'a']--;
                    i++;    
                    
                    // j++;
                }
                // else{
                    j++;
                // }
                // if(freq[s[i] - 'a']  == 1){
                //     cnt--;
                // } 

                // freq[s[i]-'a']--;
                // i++;
            }
        }


        // j = n-1;
        // // if(freq[s[i] - 'a']  == 1){
        // //     cnt--;
        // // } 

        // // freq[s[i]-'a']--;
        // // i++;
        // // j++;

        // while(i<n){
        //     // cout<<i<<endl;
        //     if(cnt == 3){
        //         ans++;
        //         if(freq[s[i] - 'a']  == 1){
        //             cnt--;
        //         } 

        //         freq[s[i]-'a']--;
        //         i++;
        //     }
        //     else break;
        // }
        
        return ans;
    }
};