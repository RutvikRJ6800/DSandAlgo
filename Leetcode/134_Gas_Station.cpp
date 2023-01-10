class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n, 0);
        int totalGas = 0, totalCost=0;
        for(int i=0; i<n; i++){
            diff[i] = gas[i] - cost[i];
            totalGas += gas[i];
            totalCost += cost[i]; 
        }

        if(totalGas<totalCost) return -1;

        int start = 0, i = 0;
        int sum = 0;
        while(i<n){
            sum += diff[i];
            if(sum<0){
                sum = 0;
                start = i+1;
            }
            i++;
        }   

        if(i==n && sum>=0) return start;
        else return -1;  
    }
};