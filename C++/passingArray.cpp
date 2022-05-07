#include<bits/stdc++.h>
using namespace std;


// by default array passed by reference
// except the first dimenstion of array we must pass other dimention while passing array to function
void incrementIndex0(int a[][20]){
    a[0][0]++;
}
int main(){
    int a[10][20];
    a[0][0]=6;
    cout<<a[0][0]<<endl;
    incrementIndex0(a);
    cout<<a[0][0]<<endl;

    
}