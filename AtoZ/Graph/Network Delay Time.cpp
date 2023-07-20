// https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);

	for(int i=0; i<times.size(); i++){
		adj[times[i][0]].push_back({times[i][1], times[i][2]});
	}

	vector<int> dist(n+1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

	dist[k] = 0;
	pq.push({0, k});

	while(!pq.empty()){
		auto it = pq.top();
		pq.pop();

		int node = it.second;
		int currDist = it.first;

		for(auto neig: adj[node]){
			if(dist[neig.first] > (currDist + neig.second)){
				dist[neig.first] = (currDist + neig.second);
				pq.push({dist[neig.first], neig.first});
				// cout<<"here: "<<neig.first<<endl;
			}
		}
	}

    int mini = 0;
    for(int i=1; i<=n; i++){
				int d  = dist[i];
				// cout<<d<<", ";
        if(d==INT_MAX) return -1;
				// if(i==k)continue;
        mini = max(mini, d);
    }
	return mini;
    }
};