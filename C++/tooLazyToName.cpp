#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
    if(a==b){
        return a;
    }
    else{
        if(a>b){
            return gcd(a-b,b);
        }
        else{
            return gcd(a,b-a);
        }
    }
}

int lcm(int a, int b){
    int cgcd = gcd(a,b);
    return (a*b)/(cgcd);
}



int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int num=1;
    int i=1; 

    for(; c>0; i++){
        if(i %a ==0 ||i %b ==0){
            c--;
        }
    }
    num = i-1;

    // while(i<=c){
    //     if(num%a || num%b){
    //         i++;
    //     }
    //     num++;
    // }

    if(num % a==0 && num%b==0){
        int clcm = lcm(a,b);
        while(num >=0){
            cout<<num<<" ";
            num -= clcm;
        }
    }

    else if(num%a ==0){
        while(num >=0){
            cout<<num<<" ";
            num -= a;
        }
    }
    else if(num%b ==0){
        while(num >=0){
            cout<<num<<" ";
            num -= b;
        }
    }
    return 0;
}