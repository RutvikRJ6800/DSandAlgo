//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
// best explained solution at : https://leetcode.com/antdavid/

// this code is submitted on gfg
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
         vector<vector<string>> ans;
        // if endword is not in wordList return empry lisst
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end()) return ans;
        vector<string> currWords;
        queue<vector<string>> q;
        currWords.push_back(beginWord);
        q.push(currWords);

        while(!q.empty()){            
            
            for(auto it: currWords){
                wordSet.erase(it);
            }
            currWords.clear();

            int size = q.size();

            while(size--){
                vector<string> vec = q.front();
                q.pop();

                string lastStr = vec[vec.size() - 1];

                if(lastStr == endWord){
                    if(ans.empty()){
                        ans.push_back(vec);
                        continue;
                    }
                    else if(ans[0].size() == vec.size()){
                        ans.push_back(vec);
                        continue;
                    }
                }

                for(int i=0; i<lastStr.size(); ++i){
                    string s = lastStr;
                    char originalChar = s[i];
                    for(char c = 'a'; c <= 'z'; ++c){
                        s[i] = c;

                        if(wordSet.find(s) != wordSet.end()){
                            // cout<<s<<endl;
                            currWords.push_back(s);
                            vec.push_back(s);
                            q.push(vec);
                            vec.pop_back();
                        }
                    }
                } 
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends