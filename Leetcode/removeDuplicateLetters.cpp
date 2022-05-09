#include<bits/stdc++.h>
using namespace std;
string removeDuplicateLetters(string s) {

    
    int freq[26] = {0};
    bool isPresent[26] = {false};
    string result="";

    for(int i=0; i<s.size(); i++){
        freq[s[i]-'a']++;
    }

    char curr;

    for(int i=0; i<s.size(); ++i){
        --freq[s[i]-'a'];
// if current character already present then goto next
        if(isPresent[s[i]-'a']==true){
            continue;
        }
        //  if last character of result string is greater than current and that is occuring letter also than delete it.
        while(result.size()!=0 && result[result.size()-1] > s[i] && freq[result[result.size()-1]-'a']>0){
            isPresent[result[result.size()-1]-'a']=false;
            result.pop_back();
        }

        // now last character of result string is lesser than currunt so add it string result.
        result.push_back(s[i]);
        isPresent[s[i]-'a']=true;
    
    }



    return result;
            
}


int main(){
    string s;
    cin>>s;
    cout<<removeDuplicateLetters(s);
}