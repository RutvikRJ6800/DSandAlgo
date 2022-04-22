#include <cmath>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector <int> res;
        
        int length = nums.size();
        int threshold = nums.size()/3;
        int me1, me2, c1, c2;
        me1=-99999; me2=-99999; c1=0; c2=0;


//  using map---> time complexity O(n) and space complexity O(n)
        // unordered_map<int,int> map;
        // for(size_t i=0; i<nums.size(); i++){
            
        //     map[nums[i]]++;
            
        // }
        
        // for(size_t i=0; i<nums.size(); i++){
            
        //     if(map[nums[i]]>threshold){
        //         if(find(res.begin(), res.end(),nums[i])==res.end())
        //         res.push_back(nums[i]);
        //     }
            
        // }
        

// most efficient algorithm  time complexity---->O(n) and constant space 
        for(auto i:nums){
            
            if(me1==i) c1++;
            else if(me2==i) c2++;
            else if(c1==0) me1=i, c1++;
            else if(c2==0) me2=i, c2++;
            else c1--, c2--;
            
        }
        c1=0;
        c2=0;
        for(size_t i=0; i<length; i++){
            
            if(nums[i]==me1){
                c1++;
            }
            else if(nums[i]==me2){
                c2++;
            }
            
        }
        
        if(c1>threshold) res.push_back(me1);
        if(c2>threshold) res.push_back(me2);
        
        return res;
    }
};