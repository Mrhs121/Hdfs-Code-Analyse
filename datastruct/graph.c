#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
typedef int VertexType;
typedef int I_ten[10];
#define V_Type %d
/*
 *  
 *  数据结构 图的存储结构以及相关的操作
 *
 *
 */
//---------邻接矩阵

typedef struct{
    char Vex[MAXNUM];
    int Edge[MAXNUM][MAXNUM];
    int vexnum,edgenum;
}MGraph;

// ---------------------------

FILE * fin;
// ----邻接表------ 
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
// ----------------------------------------
ALGraph * create_graph(){
    //int vexnum;
    ALGraph * algraph = (ALGraph*)malloc(sizeof(ALGraph));
    int i=0;
    printf("input vexnum and arcnum:");
    fscanf(fin,"%d%d",&algraph->vexnum,&algraph->arcnum);
    printf("---->%d %d\n",algraph->vexnum,algraph->arcnum);
    // printf("---->input all vex's data\n");
    //初始化定点表
    for(i=0;i<algraph->vexnum;i++){
        //printf("input vex%d\'s data:",i);
        fscanf(fin,"%d",&algraph->vertices[i].data);
        algraph->vertices[i].first = (ArcNode*)malloc(sizeof(ArcNode));
        algraph->vertices[i].first = NULL;
    }
    // 初始化边表
    printf("----> input arc\n");
    for(i=0;i<algraph->vexnum;i++){
        int arcnum = 0;
        int j=0;
        ArcNode * p = (ArcNode*)malloc(sizeof(ArcNode));
        p = algraph->vertices[i].first; 
        fscanf(fin,"%d",&arcnum);         
        for(j=0;j<arcnum;j++){
           ArcNode * newnode = (ArcNode*)malloc(sizeof(ArcNode));
           newnode->next = NULL;
            //printf("int arcnode data:\n");
            // 此处输入的顶点的编号，数组下表为0 ，编号为1，注意区别
            int num=0;    
            fscanf(fin,"%d",&num);
            printf("v%d connect-->v%d\t",i+1,num);
            newnode->adjvex = num-1;
            if(p==NULL){
                algraph->vertices[i].first = newnode;
                p = algraph->vertices[i].first;
            } else {
                p->next = newnode;
                p = newnode;
            } 
        }
        printf("\n");
    }
    return  algraph;
}

MGraph * create(){
    FILE * fin = fopen("mgraph.txt","r");
    MGraph * mgraph = (MGraph*)malloc(sizeof(mgraph));
    fscanf(fin,"%d %d",&mgraph->vexnum,&mgraph->edgenum);
    int i=0,j=0;
    int l,r;
    for(i=0;i<mgraph->vexnum;i++){
        fscanf(fin,"%c",&mgraph->Vex[i]);
    }
    for(i=0;i<mgraph->vexnum;i++){
        for(j=0;j<mgraph->vexnum;j++){
            mgraph->Edge[i][j] = 0;
        }
    }
    for(i=0;i<mgraph->edgenum;i++){
        fscanf(fin,"%d %d",&l,&r);
        // 编号从0开始
        mgraph->Edge[l][r] = 1;
        mgraph->Edge[r][l] = 1;
    }
    return mgraph;
}



void print(ALGraph * g){
    int i =0;
    for(i=0;i<g->vexnum;i++){
        printf("%4d",g->vertices[i].data);
    }
}

void testAlgraph(){
    fin = fopen("g_input.txt","r");
    ALGraph * algraph = (ALGraph*)malloc(sizeof(ALGraph)); 
    algraph = create_graph();
    printf("test\n");
    printf("0 first is :%d\n",algraph->vertices[algraph->vertices[0].first->adjvex].data);
    printf("%d",algraph->vertices[algraph->vertices[0].first->next->adjvex].data); 
    printf("\n------\n"); 
   
}
void testMgraph(){
    MGraph * m = create();
    int i=0,j=0;
    for(i=0;i<m->vexnum;i++){
        for(j=0;j<m->vexnum;j++){
            printf("%3d",m->Edge[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    testMgraph();
    return 0;
}

