// https://leetcode.com/problems/keys-and-rooms/description/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        // vector<int> keys = rooms[0];
        // vector<bool> foundKeys(n, 0);
        set<int> keyset; // stores key that we found till now
        queue<int> q; // use to explore rooms // bfs of graph
        keyset.insert(0); // add 0th room key
        q.push(0); // start exploring 0th room

        while(!q.empty()){ // start exploring room for all found keys 
            int room = q.front();
            q.pop();
            cout<<"room : "<<room<<"    ";

            for( auto key: rooms[room]){ // for all keys in room

                if(keyset.find(key) == keyset.end()){ // if that that rooms key yet not added in keyset(bunch).
                    keyset.insert(key);
                    q.push(key); // add that new room so we can visit it.
                    cout<<key;
                }
            }

            cout<<endl;
        }
        
        if(keyset.size() == n) return true; // if keyset(bunch) size is same as n means we found all rooms key
        else 
            return false; // we were not able to take all room's key.
    }
};