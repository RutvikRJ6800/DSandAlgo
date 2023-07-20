// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> prices(n, 1e9);
        prices[src] = 0;

        int stops = -1;
        while(stops < k && !q.empty()){
            int size = q.size();
            stops++;
            while(size--){
                auto it = q.front();
                int node  = it.first;
                int currPrice = it.second;
                q.pop();

                for(auto adjNode: adj[node]){
                    if(prices[adjNode.first] > currPrice + adjNode.second){
                        prices[adjNode.first] = currPrice + adjNode.second;

                        q.push({adjNode.first, prices[adjNode.first]});
                    }
                }
            }
        }

        return prices[dst] != 1e9 ? prices[dst] : -1;
    }
};