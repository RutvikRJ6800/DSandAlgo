// https://leetcode.com/problems/maximum-product-of-three-numbers/submissions/
#include<bits/stdc++.h>
class Solution {
public:
    int maximumProduct(vector<int>& nums) {


        // brute force aproch to solve --O(n^3) time;

    //     size_t size = nums.size();
    //     if(size<2){
    //         return -1;
    //     }
    //     int maxProduct = nums[0]*nums[1]*nums[2];
        
    //     for(size_t i=0; i<size; i++){
            
    //         for(size_t j=i+1; j<size; j++){
                
    //             for(size_t k=j+1; k<size; k++){
                    
    //                 if(maxProduct<nums[i]*nums[j]*nums[k]){
                        
    //                     maxProduct = nums[i]*nums[j]*nums[k];
    //                 }
                    
    //             }
    //         }
    //     }
    //  return maxProduct;   

    // smart way- O(n) time and constant space
    size_t size = nums.size();
        if(size<2){
            return -1;
        }
        int  maxA, maxB, maxC;
        int minA, minB;
        
        if(nums[0]>nums[1]){
            if(nums[0]>nums[2]){
                maxA = nums[0];
                if(nums[1]>nums[2]){
                    maxB = nums[1];
                    maxC = nums[2];
                }
                
                else{
                    maxB = nums[2];
                    maxC = nums[1];
                }
            }
            else{
                maxA = nums[2];
                maxB = nums[0];
                maxC = nums[1];
               
            }
        }
        else{
            if(nums[2]>nums[1]){
                maxA=nums[2];
                maxB=nums[1];
                maxC=nums[0];
            }
            else{
                maxA=nums[1];
                if(nums[2]>nums[0]){
                    maxB=nums[2];
                    maxC=nums[0];
                }
                
                else{
                    maxB=nums[0];
                    maxC=nums[2];       
                }
                
            }
        
        }
        
        minA=nums[0];
        minB=nums[1];
        
        if(minA>minB){
            int temp = minB;
            minB = minA;
            minA = temp;
        }
        
        if(minA>=nums[2]){
            minB=minA;
            minA=nums[2];
        }
        
        else if(minB>nums[2]){
            minB=nums[2];
        }
        
        
        for(size_t i=3; i<size; i++){
            
            if(nums[i]>=maxA){
                maxC=maxB;
                maxB=maxA;
                maxA=nums[i];
            }
            
            else if(nums[i]>=maxB){
                maxC=maxB;
                maxB=nums[i];
            }
            
            else if(nums[i]>maxC){
                maxC=nums[i];
            }
            
            
            if(nums[i]<=minA){
                minB= minA;
                minA=nums[i];
                
            }
            else if(nums[i]<minB){
                minB=nums[i];
            }
        }
        
        int one=minA*minB*maxA;
        int sec = maxA*maxB*maxC;
        
        if(one>sec)
            return one;
        else
            return sec;
        

    }
};