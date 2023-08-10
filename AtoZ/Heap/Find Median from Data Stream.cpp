// https://leetcode.com/problems/find-median-from-data-stream/description/
// good readable code at https://leetcode.com/problems/find-median-from-data-stream/solutions/74062/short-simple-java-c-python-o-log-n-o-1/
/*
class MedianFinder {
    priority_queue<long> small, large;
public:

    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() > large.size()
               ? small.top()
               : (small.top() - large.top()) / 2.0;
    }
};
*/


class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minh;
    priority_queue<int> maxh;
    MedianFinder() {
        
    }

    
    void addNum(int num) {
        if(maxh.empty()) maxh.push(num);
        else if(maxh.top() < num) minh.push(num);
        else maxh.push(num);

        // do balancing
        if(maxh.size() < minh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
        else if(maxh.size() > 1 + minh.size()){
            minh.push(maxh.top());
            maxh.pop();
        }
    }
    
    double findMedian() {
        if(minh.size() == maxh.size()) return (minh.top() + maxh.top())/2.0;
        else return maxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */