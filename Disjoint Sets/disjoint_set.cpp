#include<bits/stdc++.h>
using namespace std;

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

int main(){
    DisjointSet d(5);

    cout<<d.findUnionParent(0)<<endl;
    cout<<d.findUnionParent(1)<<endl;
    cout<<d.findUnionParent(4)<<endl;

    d.unionByRank(0,1);
    d.unionByRank(4,1);

    cout<<d.findUnionParent(0)<<endl;
    cout<<d.findUnionParent(1)<<endl;
    cout<<d.findUnionParent(4)<<endl;
    return 0;
}