/*************************************************************************
	> File Name: 18_839.c
	> Author:黄大神 
	> Mail: 
	> Created Time: Sat 22 Sep 2018 08:17:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct LNode{
    int data;
    struct LNode * next;
}LNode,*linklist;

// create linklist with headnode
LNode * create(int data[],int n)
{


    LNode * head = (linklist)malloc(sizeof(LNode)); 
    head->data = -1;
    LNode * m = head;
    int i = 0;
    for(i=0;i<n;i++){
        LNode *  node = (linklist)malloc(sizeof(LNode));
        node->data = data[i];
        node->next = NULL;
        m->next = node;
        m = node;
    }
    return head;

}
// 2018 839 判断表b是否包含在a中 时间O(n)
int  isAIncludeB(LNode *a,LNode*b)
{
    LNode * _a = a->next;
    LNode * _b = b->next;
    // 如果匹配链 首元素的值比目标链的首元素都小
    // 那么肯定不包含
    if(_b->data < _a->data){
        return FALSE;
    }
    while(_a!=NULL){
        if(_a->data == _b->data){
            // 同时移动
            _a = _a->next;
            _b = _b->next;
        } else {
            // 不匹配的情况下 子表复原到表头
            _b = b->next;
            _a = _a->next;
        }
        // 如果走完了，那么说明吧全部匹配好了
        if(_b==NULL){
            return TRUE;
        }
    }
    if(_a==NULL && _b!=NULL){
        return FALSE;
    } else {
        return TRUE;
    }
    //return FALSE;
}

// 奇偶划分
void divide(int arr[],int left,int right){

    int base = arr[left];
    int l = left;
    int r = right;
    int temp;
    while(l<r){
        while(arr[r]%2==0 && l<r){
            r--;
        }
        while(arr[l]%2!=0 && l<r){
            l++;
        }
        // 当左边遇到偶数的时候，右边遇到奇数的时候，交换
        printf("swap %d <-- >%d\n",r,l);
        if(arr[l]%2==0&&arr[r]%2!=0){
            temp = arr[r];
            arr[r] = arr[l];
            arr[l] = temp;
        }   
    }   
}


void  testDivid(){
    int arr[7] = {2,2,1,2,2,2,1};
    divide(arr,0,6);
    int i=0;
    for(i=0;i<7;i++){
        printf("%4d",arr[i]);
    }
    printf("\n");
}

void testIsInclude(){
    int a[] = {1,2,3,4,5,6,7,8};
    int b[] = {1,2,3};
    LNode * A = create(a,8);
    LNode * B = create(b,3);
    if(isAIncludeB(A,B)){
        printf("A include B\n");
    } else {
        printf("not included B\n");
    }
}
int main()
{
    testIsInclude(); 
    return 0;
}

