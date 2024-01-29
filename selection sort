#include <stdio.h>
void selectionsort(int a[],int b){
    for(int i=0;i<b;i++){
        int min=i;
        for(int j=i+1;j<b;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

int main()
{
    int b;
    scanf("%d", &b);
    int a[b],e[b/2],o[b/2];
    for(int i=0;i<b;i++){
        scanf("%d", &a[i]);
        if(i%2==0){
            e[(i/2)]=a[i];
        }else{
            o[(i-1)/2]=a[i];
        }
    }
    selectionsort(e,b/2);
    selectionsort(o,b/2); 
    for(int j=0;j<b/2;j++){
        printf("%d ", e[j]);
        printf("%d ", o[(b/2)-j-1]);
    }
    return 0;
}
