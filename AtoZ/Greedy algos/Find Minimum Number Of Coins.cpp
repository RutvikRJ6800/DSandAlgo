// https://www.codingninjas.com/studio/problems/find-minimum-number-of-coins_975277?leftPanelTab=0
#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int coin[9] = {1000, 500, 100, 50, 20, 10, 5, 2, 1}, i=0;
    int ans = 0;

    while(i<9 && amount > 0){
        if(coin[i] > amount) i++;
        else{
            ans++;
            amount -= coin[i];
        }
    }

    // for(int k=ans.size()-1; k>=0; k--){
    //     cout<<ans[k]<<" ";
    // }
    return ans;
}
