#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int N;
        cin>>N;
        int a[N+1][N+1];

        for(int i=1; i<=N; i++){
            for(int j=1; j<=i; j++){
                if(j==1){
                    // cout<<1<<" ";
                    a[i][j]=1;
                }
                else if(i==j){
                    a[i][j] = 1;
                }
                else{
                    a[i][j] = a[i-1][j-1] + a[i-1][j];
                }
            }
        }

        for(int i=1; i<=N; i++){
            for(int j=1; j<=i; j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}