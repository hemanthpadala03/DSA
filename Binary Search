#include<stdio.h>
int Binary_search(int a[],int d, int c, int b){
    int f=d+(c-d)/2;
    if (a[f]==b){
        return f;
    }else if(a[f]<b){
        return Binary_search(a,f+1,c,b);
    }else{
        return Binary_search(a,0,f-1,b);
    }
    return -1;
} 
int main(){
    int a[]={12,23,35,65,75,93};
    int c=sizeof(a)/sizeof(a[0]);
    printf("enter the element:");
    int b;
    scanf("%d",& b);
    int d=0;
    int x=Binary_search(a, d, c, b);
    printf("%d", x);
    return 0;
}
