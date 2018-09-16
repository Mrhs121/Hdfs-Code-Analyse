#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define YES 1 // 是堆
#define NO -1
#define maxsize 100 // 规定二叉树的节点总数不超过100
/*
 * *  二叉树 前中后序遍历，非递归遍历（利用堆）（注：图的非递归遍历用的是队列）
 * *  时间：2017-09-17
 * *  作者：黄晟
 * */

typedef struct BTree {
	int data;
	struct BTree* lchild;
	struct BTree* rchild;
}BTree;

typedef struct TStack{
    BTree * data[50];
    int top;
}TStack;

bool isEmpty(TStack s){
    if(s.top==-1){
        //cout<<"kong\n";
        return true;   
    } else {
        //cout<<"not empty"<<endl;
        return false;
    }
}

void push(TStack * s,BTree * node){
   s->data[++(s->top)] = node;
}

BTree * pop(TStack * s)
{

    return s->data[s->top--];
}

BTree * getTop(TStack s)
{
    return s.data[s.top];
}

BTree* createTree(BTree* T) {

	cout << "输入数据(-1表示空节点):";
	int data;
	scanf("%d",&data);
	if (data == -1)
		return NULL;
	else
	{
		T = (BTree*)malloc(sizeof(BTree));
		T->data = data;
		cout <<"input "<< data <<" 的左子树:" << endl;
		T->lchild = createTree(T->lchild);
		cout << "input " << data <<" 的右子树:" << endl;
		T->rchild = createTree(T->rchild);
	}
	return T;
}

// 839真题 答案 一颗二叉树采用标准存储
// 判断这棵树是否为堆的条件
int isSatisfyHeap(BTree * tree) {
	BTree * stack[maxsize];
	int top = -1;
	stack[++top] = tree;
	BTree * p;
	while (top!=-1)
	{
		p = stack[top--]; 
	
        // 左右孩子均不能大于根结点
		if (p->lchild !=NULL)
		{
			
			if (p->data < p->lchild->data)
			{
				return -1;
			}
			
			stack[++top] = p->lchild;
		}

		if (p->rchild != NULL)
		{
			
			if (p->data < p->rchild->data)
			{
				return -1;
			}
			
			stack[++top] = p->lchild;
		}
	}
	return 1;
}

void PreOrderBiTree(BTree *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%d ", T->data);
		PreOrderBiTree(T->lchild);
		PreOrderBiTree(T->rchild);
	}
}

// 二叉树的层序遍历 使用队列若该节点的左右孩子不为空，则入队
void LeverOrder(BTree * root)
{
	int front= -1;
	int rear = -1;
	BTree * Q[1000];
	Q[++rear] = root;
	BTree * q = (BTree*)malloc(sizeof(BTree));
	while(front!=rear)
	{
		q = Q[++front];
		cout<<q->data<<endl;
		// 左右孩子入队
		if(q->lchild!=NULL)
			Q[++rear] = q->lchild;
		if(q->rchild!=NULL)
			Q[++rear] = q->rchild;
	} 

}
// 非递归前序遍历 OK
void PreOrder(BTree * T)
{
	cout<<"非递归前序遍历"<<endl;
	int top = -1;
	BTree * s[1000];	
	while(T!=NULL || top!=-1)
	{
	    while(T!=NULL)
	    {
		cout<<T->data<<endl;
		s[++top] = T;
		T = T->lchild;
	    }
	    if(top!=-1)
	    {
		T = s[top--];
		T = T->rchild;
	    }	
	}
}

void postOrder(BTree * tree)
{
    
    int i = 0;
    TStack s;
   
    s.top = -1;
    BTree * p = tree;
    BTree * r = NULL;
    while(p!=NULL || !isEmpty(s))
    {
        if(++i > 8){
            break;
        }
        //cout<<"if "<<s.top<<"----------"<<s.data[s.top]->data<<endl;
        if(p!=NULL){
            push(&s,p);
            p = p->lchild;
//            if(p==NULL){
  //              cout<<"left finish"<<endl;
    //        }
        }
        else
        {
      //      cout<<"tetst111111"<<endl;
            p = getTop(s);
            if(p->rchild&&p->rchild!=r)
            {
                p = p->rchild; //上一个结点向右边走
                push(&s,p);
                p = p->lchild;
            }
            else
            {
                p = pop(&s);
                printf("%5d",p->data);
                r = p;
                p = NULL;
            }
        }
    }
    printf("\n");
}


int main()
{
	BTree *T=NULL;
	T = createTree(T);
	cout << "test" << endl;
    PreOrderBiTree(T);
	cout<<"\n------------------------------\n";
    postOrder(T);
    //PreOrder(T);
	/*
    LeverOrder(T);
	int res = isSatisfyHeap(T);
	cout << "res : " << res<<endl;
	if(res == YES)
	{
		cout << "此树是堆" << endl;
	}
	else
	{
		cout << "此树不是堆" << endl;
	}
	system("pause");
    */
    return 0;
}
