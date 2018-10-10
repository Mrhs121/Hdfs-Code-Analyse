#include <stdio.h>


void print(int b[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%5d->",b[i]);
    }
    printf("\n");
}

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


void HalfInsertSort(int arr[],int n){
    if(n<=1){
        return;
    }
    int count=1;
    int temp;
    int i,j,mid,left,right;
    for(i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            temp = arr[i];
            left = 0;
            right = i-1;
            while(left<=right){
                mid = (left + right)/2;
                if(temp<arr[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
            //arr[mid] = temp;
            for(j=i-1;j>=mid;j--){
                arr[j+1] = arr[j];
            }
            arr[mid] = temp;
            printf("第%d次: ",count++);
            print(arr,10);            
        }
    }
}
// 双向 冒泡
void dobule_pop(int arr[],int n){
    
}

void QuickSort(int arr[],int left,int right){
    

}

// Time O(n^2) 
// Space O(1)
void selectSort(int arr[],int length){
    if(length <= 1){
        return;
    }
    int i,j,index;
    int _min;
    for(i=0;i<length-1;i++){
        _min = arr[i];
        index = i;
        for(j=i;j<length;j++){
            if(arr[j]<_min){
                _min = arr[j];
                index = j;
            }
                
        }
        //min = 9999;
        swap(&arr[i],&arr[index]);
    }
}

int find_k_min(int arr[],int low,int high,int k){
    int pivot = arr[low];
    int l=low,r=high;
    while(low<high){
        while(arr[high]>=pivot && low<high){
            --high;
        }
        while(arr[low]<=pivot&&low<high){
            ++low;
        }
        int temp = arr[high];
        arr[high] = arr[low];
        arr[low] = temp;

    }
    arr[l] = arr[low];
    arr[low] = pivot;
    if(low==k){
        return arr[k-1];
    }
    else if(low>k){
        return find_k_min(arr,l,low-1,k);
    } else {
        return find_k_min(arr,low+1,r,k);
    }
}

int main()
{
    int b[10] = {412,1234,124,6,1234,1,412,4231,4 ,3,};
//    int k_min = find_k_min(b,0,9,3);
    //printf("k_min = %d\n",k_min);
    print(b,10);
    selectSort(b,10);
    print(b,10);
    //print(b,10);
    //HalfInsertSort(b,10);
    //print(b,10);

    
    return 0;
}

