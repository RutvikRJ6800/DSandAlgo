#include<bits/stdc++.h>
using namespace std;

int main(){

    int a=5;
    int *p_a = &a;
    int **p_p_a = &p_a;

    cout<<"value of a "<<a<<endl;
    cout<<"value of &a "<<&a<<endl;
    cout<<"value of p_a "<<p_a<<endl;
    cout<<"value of p_a+1 "<<p_a+1<<endl;
    cout<<"value of &p_a "<<&p_a<<endl;
    cout<<"value of p_p_a "<<p_p_a<<endl;

    return 0;
}