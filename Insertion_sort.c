#include<stdio.h>
void bubble_sort(int a[],int c){
    for(int i=1;i<c;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && key<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main(){
    int a[]={32,23,75,93,35,65};
    int c=sizeof(a)/sizeof(a[0]);
    bubble_sort(a,c);
    for(int i=0;i<c;i++){
        printf("%d ", a[i]);   
    }
    printf("\n");
    return 0;
}
