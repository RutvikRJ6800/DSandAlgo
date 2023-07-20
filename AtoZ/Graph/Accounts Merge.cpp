// https://leetcode.com/problems/accounts-merge/description/

class DisjointSet{
    vector<int> rank, parent;
    public:

    DisjointSet(int V){
        rank.resize(V+1, 0);
        parent.resize(V+1);

        for(int i=0; i<V+1; i++){
            parent[i] = i;
        }
    }

    int findUnionParent(int u){
       if(parent[u] == u)
            return u;
       else
            return parent[u] = findUnionParent(parent[u]);
    }

    void unionByRank(int u, int v){
        int ultimateParentU = findUnionParent(u);
        int ultimateParentV = findUnionParent(v);

        if(ultimateParentU == ultimateParentV) return;

        // do union of u and v
        if(rank[u] < rank[v]){
            parent[ultimateParentU] = ultimateParentV;
        }
        else if(rank[u] > rank[v]){
            parent[ultimateParentV] = ultimateParentU;
        }
        else if(rank[u] == rank[v]){
            parent[ultimateParentV] = ultimateParentU;
            rank[u]++;
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DisjointSet ds(n);
        unordered_map<string, int> mp;

        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string str = accounts[i][j];
                if(mp.find(str) == mp.end()){
                    mp[str] = i;
                }
                else if(mp[str] != i){
                    ds.findUnionParent(mp[str]);
                    ds.unionByRank(mp[str], i);
                }
            }
        }
        vector<vector<string>> ans;
        vector<vector<string>> emails(n);

        for(auto mppair: mp){
            int ultiParent = ds.findUnionParent(mppair.second);
            emails[ultiParent].push_back(mppair.first);
        }

        for(int i=0; i<n; i++){
            if(emails[i].size() > 0){
                vector<string> temp;
                temp.push_back(accounts[i][0]);

                sort(emails[i].begin(), emails[i].end());

                for(auto em: emails[i]){
                    temp.push_back(em);
                }

                ans.push_back(temp);
            }
        }
        return ans;
    }
};