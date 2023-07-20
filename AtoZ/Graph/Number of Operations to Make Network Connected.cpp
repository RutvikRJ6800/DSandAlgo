// https://leetcode.com/problems/number-of-operations-to-make-network-connected/


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
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<pair<int, pair<int, int>>> edges;
        int edgesCount = connections.size();
        if(edgesCount < n-1) return -1;

        DisjointSet ds(n);
        int edgesTaken = 0;

        for(auto it: connections){
            int a = it[0], b = it[1];

            if(ds.findUnionParent(a) != ds.findUnionParent(b)){
                //merge
                ds.unionByRank(a, b);
                edgesTaken++;
            }
        }

        return n -1 - edgesTaken;
    }
};