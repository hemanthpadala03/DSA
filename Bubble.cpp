#include<stdio.h>
void bubble_sort(int a[],int c){
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            if(a[i]<a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
} 
int main(){
    int a[]={12,23,75,93,35,65};
    int c=sizeof(a)/sizeof(a[0]);
    bubble_sort(a,c);
    for(int i=0;i<c;i++){
        printf("%d ", a[i]);   
    }
    printf("\n");
    return 0;
}
