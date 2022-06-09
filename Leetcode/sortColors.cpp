// https://leetcode.com/problems/sort-colors/
// https://www.youtube.com/watch?v=oaVa-9wmpns&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=3
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // datch national flag algorithm-O(N)(1 pass)

        int low,mid,high;
        low=0;
        mid=0;
        high=nums.size()-1;

        while(mid<high+1){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                high++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }



//         counting sort approch - O(N)*2(2 pass) time; O(3) space;
       //  vector<int> count(3,0);
       //  for(int i=0; i<nums.size(); i++){
       //      count[nums[i]]++;
       //  }
       //  int j=0,i=0;
        
       // while(i<nums.size()){
       //      if(count[j]==0){
       //          j++;
       //          continue;
       //      }
       //      nums[i]=j;
       //      count[j]--;
       //     i++;
       //  }

        // O(N2) time O(1) space
        // for(int i=0; i<nums.size();i++){
        //     for(int j=i; j<nums.size(); j++){
        //         if(nums[i]>nums[j]){
        //             swap(nums[i],nums[j]);
        //         }
        //     }
        // }
        
        
        
    }
};