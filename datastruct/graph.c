#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
typedef int VertexType;
typedef int I_ten[10];
/*
 *  
 *  数据结构 图的存储结构以及相关的操作
 *
 *
 */

FILE * fin;

typedef struct ArcNode{
    int adjvex; //vertices index
    struct ArcNode * next;
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode * first;
}VNode,AdjList[MAXNUM];

typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;

ALGraph * create_graph(){
    int vexnum;
    ALGraph * algraph = (ALGraph*)malloc(sizeof(ALGraph));
    int i=0;
    printf("input vexnum and arcnum:");
    fscanf(fin,"%d%d",&algraph->vexnum,&algraph->arcnum);
    printf("---->%d %d\n",algraph->vexnum,algraph->arcnum);
    // printf("---->input all vex's data\n");
    for(i=0;i<algraph->vexnum;i++){
        //printf("input vex%d\'s data:",i);
        fscanf(fin,"%d",&algraph->vertices[i].data);
        algraph->vertices[i].first = NULL;
    }
    
    printf("----> input arc\n");
    for(i=0;i<algraph->vexnum;i++){
        int arcnum = 0;
        int j=0;
        ArcNode * p = (ArcNode*)malloc(sizeof(ArcNode));
        algraph->vertices[i].first = (ArcNode*)malloc(sizeof(ArcNode));
        p = algraph->vertices[i].first;
        //printf("input v%d's arcnum:",i+1); 
        fscanf(fin,"%d",&arcnum);
//        ArcNode * newnode = 
   //             (ArcNode*)malloc(sizeof(ArcNode));
            
        for(j=0;j<arcnum;j++){
           ArcNode * newnode = 
            (ArcNode*)malloc(sizeof(ArcNode));
           newnode->next = NULL;
            //printf("int arcnode data:\n");
            // 此处输入的顶点的编号，数组下表为0 ，编号为1，注意区别
            int num=0;
            fscanf(fin,"%d",&num);
            newnode->adjvex = num-1;
            if(p==NULL){
                algraph->vertices[i].first = newnode;
                p = algraph->vertices[i].first;
            } else {
                p->next = newnode;
                p = newnode;
            }
            //   p = newnode;
         //   newnode = (ArcNode*)malloc(sizeof(ArcNode));
         //   newnode->next = NULL;
         //   p->next = newnode;
          
        }
    }
//binvoid print(ALGraph *g);
    //print(algraph);
    return  algraph;
}





void print(ALGraph * g){
    int i =0;
    for(i=0;i<g->vexnum;i++){
        printf("%4d",g->vertices[i].data);
    }
}

int main()
{
    fin = fopen("g_input.txt","r");
    ALGraph * algraph = (ALGraph*)malloc(sizeof(ALGraph)); 
    algraph = create_graph();
    printf("test\n");
    printf("0 first is :%d\n",algraph->vertices[0].data);
   printf("%d",algraph->vertices[algraph->vertices[0].first->next->adjvex].data); 
    printf("\n------\n"); 
    return 0;
}

