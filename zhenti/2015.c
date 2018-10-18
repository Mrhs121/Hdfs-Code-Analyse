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

// 2015 第十大题，生成二叉树的扩充标准形式的存储结构
//  完美解决方案
ExtendBTree * TEN_extendTree2(BTree * tree,ExtendBTree * pre){
    if(tree == NULL){
        return NULL;
    }
    ExtendBTree * Extree = (ExtendBTree*)malloc(sizeof(ExtendBTree));
    Extree->data = tree->data;
    Extree->rchild = NULL;
    Extree->lchild = NULL;
    Extree->parent = pre;
    if(tree->lchild!=NULL){
        Extree->lchild = TEN_extendTree2(tree->lchild,Extree);
    }
    if(tree->rchild!=NULL){
        Extree->rchild = TEN_extendTree2(tree->rchild,Extree);
    }
    return Extree;
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
    for(i=0;i<n;i++){
        printf("%d ",data[i]);
    }
    printf("\n");
    BTree * tree = NULL;
    tree = createTree(tree,data);
    printf("标准存储结构\n");
    PreOrderBiTree(tree);
    //TEN_extendTree(tree,NULL);
    ExtendBTree * ExTree = (ExtendBTree*)malloc(sizeof(ExtendBTree));
    ExTree = TEN_extendTree2(tree,NULL);
    printf("扩充标准形式\n");
    PreOrderExBiTree(ExTree);
    printf("\n");
}

int main()
{
    TEN();
    return 1;
}
