#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,target,*p;
    printf("Enter No. of elements\n");
    scanf("%d",&n);
    p = (int *)calloc(n,sizeof(int));
    for (int i = 0; i < n ; i++){
        scanf("%d",p[i]);
        printf("%d",p[i]);
    }
    printf("Enter target value\n");
    scanf("%d",&target);
    for(i = 0 ; i < n;i++){
        if(target == p[i]){
            printf("\nTarget fount at index %d",i);
            return 0;
        }
    }
    printf("\nTarget not exist..");
    return 0;

    return 0;
    
}