// https://leetcode.com/problems/task-scheduler/description/
// https://leetcode.com/problems/task-scheduler/solutions/104500/java-o-n-time-o-1-space-1-pass-no-sorting-solution-with-detailed-explanation/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> lastOccured;
        unordered_map<char, int> freq;

        for(char c: tasks){
            freq[c]++;
            lastOccured[c] = -1;
        }

        priority_queue<int> maxH;
        queue<pair<int, int>> waitQueue;
        
        for(auto it: freq){
            maxH.push(it.second);
        }

        int currTime = 0;
        while(maxH.size()>0 || waitQueue.size()>0){
            currTime++;
            if(maxH.size() > 0){
                int top = maxH.top(); maxH.pop();
                if(--top > 0){
                    // add back top in waiting queue
                    waitQueue.push({top, currTime + n});
                }
            }

            if(waitQueue.size()>0 && waitQueue.front().second == currTime){
                maxH.push(waitQueue.front().first);
                waitQueue.pop();
            }
        }
        return currTime;
    }
};