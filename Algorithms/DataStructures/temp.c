#include<stdio.h>
void fun(int a[2][2])
{
    printf("%d",a[1][1]);
}

void main(){
    int b[2][2] = { {1,2},{3,4}};
     printf("%u",b[1][0]);
 
}
  