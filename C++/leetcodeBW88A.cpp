#include<bits/stdc++.h>
using namespace std;
bool equalFrequency(string word) {
        vector<int> freq(26,0);
        size_t n = word.size();
        
        // for(size_t i=0; i<n; i++){
        //     freq[word[i]-'a']++;
        // }
        
        int count =0;
        
        
        map<char,int> fm;
        
         for(size_t i=0; i<n; i++){
            fm[word[i]]++;
        }
        
        
        map<int,int> newMap;
        
        auto i = fm.begin();
        i++;
        for(; i!=fm.end(); i++){
            newMap[i->second]++;
        }

         for (auto r = newMap.begin(); r != newMap.end(); r++)
        cout << r->first << "      " << r->second
             << endl;
        
        if(newMap.size()<=1 || newMap.size()>=3){
            // cout<<"a";
            return false;
        }
        
        else {
            auto j = newMap.begin();
            auto k = newMap.begin();
            k++;
            if(abs(j->first - k->first)==1 && (j->second == 1 || k->second == 1))return true;
            else
            return false;
        }

    }

int main(){
    string s = "ababcccddd";
    cout<<equalFrequency(s);
    return 0;
}
        