// https://leetcode.com/problems/max-points-on-a-line/description/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            unordered_map<double,int> hm;
            int i_max = 0;
            for(int j=i+1; j<n; j++){
                double slop;
                if(points[j][0] - points[i][0] == 0) slop = 100000001;
                else{
                    slop = (double)((double)(points[j][1] - points[i][1])/(double)(points[j][0] - points[i][0]));
                }
                hm[slop]++;
                cout<<i<<","<<j<<","<<hm[slop]<<","<<slop<<endl;
                i_max = max(i_max, hm[slop]);
            }
            ans = max(ans, i_max);
        }
        return ans+1;
    }
};