// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        vector<int> cumulativeSumFront(n, 0);
        vector<int> cumulativeSumBehind(n, 0);
        
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += cardPoints[i];
            cumulativeSumFront[i] = sum;
        }

        sum = 0;
        for(int i=n-1; i>=0; i--){
            sum += cardPoints[i];
            cumulativeSumBehind[i] = sum;
        }

        int i=k-1, maxi = 0;
        while(i>=-1){
            int j = n - (k-1 - i);

            int currWindowSum = ((i>=0) ? cumulativeSumFront[i] : 0) + ((j<=n-1) ? cumulativeSumBehind[j] : 0);        
            cout<<i<<","<<currWindowSum<<endl;
            maxi = max(maxi, currWindowSum);

            i--;

        }

        return maxi;

    }
};