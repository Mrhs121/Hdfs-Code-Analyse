#include <stdio.h>


void swap(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertSort(int arr[],int length){
    int i,j;
    int temp = arr[0];
    for(i=1;i<length;i++){
        // 如果小于前驱那么进行插入
        if(arr[i]<arr[i-1]){
            temp = arr[i];
            for(j=i-1;temp<arr[j]&&j>=0;j--){
               //swap(&arr[j],&arr[j-1]);
               arr[j+1] = arr[j];
            };
            arr[j+1] = temp;
            /*另一种实现
             *for(j=i;a[j]<a[j-1]&&j<0;j--){
                    swap(&a[j],a[j-1]);
             }
             *
            */
        }  
    }
}

void print(int b[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%5d",b[i]);
    }
    printf("\n");
}
int main()
{
    printf("Hello world\n");
    int a[2] = {1,2};
    swap(&a[0],&a[1]);
    printf("%d\n",a[0]);
    int b[10] = {12,2,4,51,213,14,5,5,1,1324};
    print(b,10);
    InsertSort(b,10);
    print(b,10);
    return 0;
}

