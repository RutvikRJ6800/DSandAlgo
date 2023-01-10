class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0]<=b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), cmp); // sort intervals based on asc order of first index

        int e = points[0][1]; // e denote end time of last considered balloon
        int n = points.size();
        int cnt = 1; // cnt denote number of arrows needed
        for(int i=1; i<n; i++){
            if(e>=points[i][0]){ // if next ballon is overlapped
                e = min(e, points[i][1]); // then e must be min of size ---> (twist)
            }
            else{
                cnt++; // else we need one more arrow
                e = max(e, points[i][1]); // update e with max size.
            }
        }

        return cnt;
    }
};