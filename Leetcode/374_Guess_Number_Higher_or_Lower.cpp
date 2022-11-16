/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */


/*
Approch: Use binary search to reach at the exact guessed number
*/
class Solution {
public:
    int guessNumber(int n) {
        
        int low = 1, high = n, mid, g;
        
        while(low<=high){
            mid = low + (high-low) / 2;
            // cout<<"mid: "<<mid<<endl;
            g = guess(mid);
            if(g == 0) return mid; // found guessed number
            else if(g == -1){ // guessed number is lesser 
                high = mid-1;
            }
            else{ // guessed number is greater
                low = mid+1;
            }
        }
        
        return low;
    }
};