#include <stdio.h>
#include <stdlib.h>
#include "../datastruct/myStrcut.h"



// 2015 第十大题，生成二叉树的扩充标准形式的存储结构
void TEN_extendTree(BTree * tree,BTree * pre){
    if(tree == NULL){
        return;
    } else {
        tree->parent = pre;
        TEN_extendTree(tree->lchild,tree);
        TEN_extendTree(tree->rchild,tree);
    }
}

void TEN(){
    int data[100];
    FILE * in =  fopen("./in.data","r");
    int n;
    int i=0;
    fscanf(in,"%d\n",&n);
    for(i=0;i<n;i++){
        fscanf(in,"%d",&data[i]);
    }
    BTree * tree = NULL;
    tree = createTree(tree,data);
    printf("标准存储结构\n");
    PreOrderBiTree(tree);
    TEN_extendTree(tree,NULL);
    printf("扩充标准形式\n");
    PreOrderBiTree(tree);
    printf("\n");
}

int main()
{
    TEN();
    return 1;
}
