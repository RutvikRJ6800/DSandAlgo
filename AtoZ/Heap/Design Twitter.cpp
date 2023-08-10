// https://leetcode.com/problems/design-twitter/description/
class Twitter {
public:
    unordered_map<int, vector<int>> following;
    unordered_map<int,  vector<pair<int, int>>> userToPosts;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userToPosts[userId].push_back({++time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;     

        // add all post of user into pq
        for(auto it: userToPosts[userId]){
            // cout<<"post:"<<it.second<<endl;
            pq.push(it);
            if(pq.size()>10){
                pq.pop();
            }
        }

        // add post of all the followings of userID
        for(int fo: following[userId]){
            for(auto it: userToPosts[fo]){
                pq.push(it);
                if(pq.size()>10){
                    pq.pop();
                }
            }
        }

        // retrive most recent post frm the min Heap
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId || std::find(following[followerId].begin(), following[followerId].end(), followeeId) != following[followerId].end()) return;

        following[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId || std::find(following[followerId].begin(), following[followerId].end(), followeeId) == following[followerId].end()) return;

        following[followerId].erase(std::find(following[followerId].begin(), following[followerId].end(), followeeId));
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */