// https://leetcode.com/problems/hand-of-straights/description/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // base case
        if(hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        
        for(auto card: hand){
            freq[card]++;
        }


        // create min heap of hand cards
        priority_queue<int, vector<int>, greater<int>> minH;
        for(auto it: freq){ 
            minH.push(it.first);
        }
        
        int groupCount = 0, totalGroup = hand.size()/groupSize;
        while(groupCount < totalGroup){
            // form a new group of size groupSize
            int first = minH.top(), i=0; // take first card which is with min value
            while(i<groupSize){
                int curr = first + i;
                if(freq[curr] == 0) return false; // if curr card is not present than we can not make consecutive pair
                freq[curr]--;
                if(freq[curr] == 0) minH.pop(); // if freq of curr card is reached 0 then remove it from the minHeap
                i++;
            }
            groupCount++;
        }
        return true;
    }
};