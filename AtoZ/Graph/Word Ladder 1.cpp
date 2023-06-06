/*
Intuition
We will first traverse the boundry and apply DFS if we see O's.
By doing this we will visit all O's which are not surrounded by 'X' in some direction/s.

Approach
Step 1:
we will perform DFS traversal on 'O's which are in boundary, so all the 'O' which are connected to boundary 'O's will be visited

Step 2:
we will traverse the board and mark all 'O's to 'X' which are not visited. (They are not visited means they are not anyway conntected to any boundary O's. means they are all surrounded by 'X's in all 4 direction.)

Complexity
Time complexity:
2∗O(m)2*O(m)2∗O(m) (for left and right border traversal) + 2∗O(n)2*O(n)2∗O(n) (bottom and top border traversal) + 2∗O(m∗n)2*O(m * n)2∗O(m∗n) (for dfs and board traversal) ≡ O(m∗n)O(m*n)O(m∗n)

Space complexity:
O(m∗n)O(m * n)O(m∗n) (for DFS) + O(m∗n)O(m * n)O(m∗n) (for visited matrix) ≡ O(m∗n)O(m * n)O(m∗n)

*/
// https://leetcode.com/problems/word-ladder/description/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int m = wordList.size(), d = wordList[0].size();
        vector<bool> visited(m, 0);
        set<string> wordSet(wordList.begin(), wordList.end());

        string currWord = beginWord;
        queue<pair<string, int>> q;
        q.push({currWord, 1});
        int res = 0;

        while(!q.empty()){
            auto [currStr, level] = q.front();
            q.pop();

            for(int i=0; i<d; i++){
                for(int j=0; j<26; j++){
                    string s = currStr;
                    s[i] = ('a' + (s[i] + j)%26);
                    // cout<<s<<endl;
                    // check if new word is in the set or not
                    if(wordSet.find(s) !=  wordSet.end()){
                        q.push({s, level+1});
                        wordSet.erase(s);
                        if(s == endWord) res = level + 1;
                    }
                }
            }
        }
        return res;
    }
};