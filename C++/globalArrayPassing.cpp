#include<bits/stdc++.h>
using namespace std;

// easiest way is to declare global array
const int N=1e5 + 10;
int arr[N];

void incrementArrayIndexN(){
    arr[N]++;
}
int main(){

    arr[N]=6;
    cout<<arr[N]<<endl;
    incrementArrayIndexN();
    cout<<arr[N]<<endl;
    
    return 0;
}