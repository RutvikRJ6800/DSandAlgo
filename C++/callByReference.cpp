#include<bits/stdc++.h>
using namespace std;

void increment(int &n, int m){
    n++;
    m++;
}

int main(){
    int a=3;
    int b=4;
    cout<<a<<" "<<b<<endl;
    increment(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}