class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> myMap;
        size_t size = strs.size();
        vector<string> strsT(strs);
        
        for(size_t i=0; i<size; i++){
            
            sort(strsT[i].begin(), strsT[i].end());
//             if string is not in map
            if(myMap.find(strsT[i])==myMap.end()){
                myMap[strsT[i]] = {strs[i]};
            }
//             if string is already in map
            else{
                myMap[strsT[i]].push_back(strs[i]);
            }
        }
        
        vector<vector<string>> res;
//         for(size_t j=0; j<myMap.size(); j++){
//             vector<string> vS;
//             for(size_t i=0; i<myMap.second.size(); i++){
//                 vS.push_back(myMap.second[i]);
//             }
            
//             // for (auto i : m)
//             //     cout << i.first << "   " << i.second
//             //  << endl;
            
            
//             res.push_back(vS);
//         }
        
        
        
        
//         for (auto i : myMap){
//             vector<string> vS;
//             for(size_t i=0; i<(myMap.second).size(); i++){
//                 vS.push_back(myMap.second[i]);
//             }
//             res.push_back(vS);
                
        unordered_map<string, vector<string>>::iterator it = myMap.begin();
        while(it != myMap.end()){
            vector<string> vS;
            // vector<string>::iterator bit = it->second;
            for(size_t p=0; p<(it->second).size(); p++){
                vS.push_back((it->second)[p]);
            }
            // while(bit!= it->second->end()){
            //     vS.push_back(*bit);
            // }
            res.push_back(vS);
            it++;
            
        }
    // Iterating over the map using Iterator till map end.
        return res;
    }
};