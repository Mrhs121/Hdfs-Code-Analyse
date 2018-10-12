#include <stdio.h>


void print(int b[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%5d",b[i]);
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

//  折半插入
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
// 拍排
void QuickSort(int arr[],int left,int right){
    

}

// 选择排序
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

// 查找一个无序的序列中第k个最小的
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


// 调整堆
void AdjustDown(int arr[],int k,int length){
    arr[0] = arr[k];
    int i;
    for(i=2*k;i<=length;i*=2){
        if(i<length&&arr[i]<arr[i+1])
            i++;
        if(arr[0] >= arr[i])
            break;
        else {
            arr[k] = arr[i];
            k = i;
        }
    }
    arr[k] = arr[0];
}

// 大顶堆
void buildHeap(int arr[],int length){
    int i;
    for(i=length/2;i>0;i--){
        AdjustDown(arr,i,length);
    }
}

//堆排
// O(nlog2 n)
void testHeap(){
    int arr[] = {-1,53,17,78,9,45,65,87,32};
    print(arr,9);
    int i=0;
    int len = 9;
    buildHeap(arr,len);
    for(i=len;i>1;i--){
        printf("%5d",arr[1]);
        swap(&arr[1],&arr[i]);
        AdjustDown(arr,1,i-1);
    }
    printf("\n");
}




int main()
{

    testHeap();
    //printf("\n-----------------\n");
    //int b[10] = {412,1234,124,6,1234,1,412,4231,4 ,3,};
//    int k_min = find_k_min(b,0,9,3);
    //printf("k_min = %d\n",k_min);
    //print(b,10);
    //selectSort(b,10);
    //print(b,10);
    //print(b,10);
    //HalfInsertSort(b,10);
    //print(b,10);

    
    return 0;
}

