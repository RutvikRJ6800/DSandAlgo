class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        for(int i=0; i<n; i++){
            rocks[i] = capacity[i] - rocks[i]; // modified rock array to need array// rep each bag need to complete full
        }

        sort(rocks.begin(), rocks.end()); // sort need array/rocks

        int cnt = 0; // denote number of bags that we can make it full
        for(int i=0; i<n && additionalRocks >= 0; i++){
            if(additionalRocks >= rocks[i]){ // if we can make this bag full then just consider it into result
                cnt++;
                additionalRocks -= rocks[i];
            }
            else{
                break;
            }
        }

        return cnt;
    }
};