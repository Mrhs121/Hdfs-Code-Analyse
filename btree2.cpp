// git.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
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

typedef struct BTree_char {
	char data;
	struct BTree_char * lchild;
	struct BTree_char * rchild;
}BTree_char;


typedef struct TStack {
	BTree * data[50];
	int top;
}TStack;

typedef struct Qu {
	BTree * data[50];
	// int LeverCount[50];
	int front, rear;
}Qu;



//先序自动创建二叉树
//int _data[] = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1};
int _data[] = { 1,2,3,-1,-1,-1,5,-1,-1 };
char _data_char[] = { '*','+','a','#','#','b','#','#','*','c','#','#','-','#','d','#','#' };
char _data_char2[] = { '+','+','a','#','#','b','#','#','+','c','#','#','+','d','#','#','e','#','#' };

static int _count = 0;
int _Lever = 0;


// 计算最大宽度
// 以及计算层数
int BTWidth(BTree * t) {
	int LeverCount[100];
	int max = -1;
	Qu _queue;
	_queue.front = -1;
	_queue.rear = -1;
	int last = 0;
	int Lever = 0;
	int count = 0;
	_queue.data[++_queue.rear] = t;
	BTree * p;
	while (_queue.front < _queue.rear) {
		p = _queue.data[++_queue.front];
		count += 1;
		if (p->lchild != NULL)
			_queue.data[++_queue.rear] = p->lchild;
		if (p->rchild != NULL)
			_queue.data[++_queue.rear] = p->rchild;
		// key
		if (_queue.front == last) {
			Lever++;
			cout << "count:" << count << endl;
			LeverCount[Lever] = count;
			// echoLeverWidth[Lever] = count;
			last = _queue.rear;
			count = 0;
		}
	}
	max = LeverCount[1];
	//cout<<"_max:"<<max<<endl;
	for (int i = 1;i <= Lever;i++) {
		if (max<LeverCount[i])
			max = LeverCount[i];
	}
	cout << "the tree's Lever is:" << Lever << endl;
	return max;
}



bool isEmpty(TStack s) {
	if (s.top == -1) {
		//cout<<"kong\n";
		return true;
	}
	else {
		//cout<<"not empty"<<endl;
		return false;
	}
}

void push(TStack * s, BTree * node) {
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


BTree_char* createTree_char(BTree_char* T) {

	cout << "输入数据(-1表示空节点):";
	char data;
	//scanf("%d",&data);
	cout << _data_char2[_count] << endl;;
	data = _data_char2[_count];
	_count++;
	if (data == '#')
		return NULL;
	else
	{
		T = (BTree_char*)malloc(sizeof(BTree_char));
		T->data = data;
		cout << "input " << data << " 的左子树:" << endl;
		T->lchild = createTree_char(T->lchild);
		cout << "input " << data << " 的右子树:" << endl;
		T->rchild = createTree_char(T->rchild);
	}
	return T;
}






BTree* createTree(BTree* T) {

	cout << "输入数据(-1表示空节点):";
	int data;
	//scanf("%d",&data);
	cout << _data[_count] << endl;;
	data = _data[_count];
	_count++;
	if (data == -1)
		return NULL;
	else
	{
		T = (BTree*)malloc(sizeof(BTree));
		T->data = data;
		cout << "input " << data << " 的左子树:" << endl;
		T->lchild = createTree(T->lchild);
		cout << "input " << data << " 的右子树:" << endl;
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
	while (top != -1)
	{
		p = stack[top--];

		// 左右孩子均不能大于根结点
		if (p->lchild != NULL)
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

void PreOrderBiTreeWithOutLeaf(BTree *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		if (T->lchild != NULL || T->rchild != NULL) {
			printf("%d ", T->data);
		}
		PreOrderBiTreeWithOutLeaf(T->lchild);
		PreOrderBiTreeWithOutLeaf(T->rchild);
	}
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

void PreOrderBiTree_char(BTree_char *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%c ", T->data);
		PreOrderBiTree_char(T->lchild);
		PreOrderBiTree_char(T->rchild);
	}
}

void InOrderBiTree_char(BTree_char *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		//	printf("%d ", T->data);
		InOrderBiTree_char(T->lchild);
		cout << T->data << " ";
		InOrderBiTree_char(T->rchild);
	}
}

void BTree_char2Exp(BTree_char * T, int deep) {

	//    cout<<"-->\n";
	if (T == NULL)
		return;
	else if (T->lchild == NULL && T->rchild == NULL)
		printf("%c", T->data);
	else {
		if (deep>1) {
			printf("(");
		}
		BTree_char2Exp(T->lchild, deep + 1);
		printf("%c", T->data);
		BTree_char2Exp(T->rchild, deep + 1);
		if (deep>1)
			printf(")");
	}
}
void BTree_char2E(BTree_char * T) {
	BTree_char2Exp(T, 1);
}



// 二叉树的层序遍历 使用队列若该节点的左右孩子不为空，则入队
void LeverOrder(BTree * root)
{
	int front = -1;
	int rear = -1;
	BTree * Q[1000];
	Q[++rear] = root;
	BTree * q = (BTree*)malloc(sizeof(BTree));
	while (front != rear)
	{
		q = Q[++front];
		cout << q->data << endl;
		// 左右孩子入队
		if (q->lchild != NULL)
			Q[++rear] = q->lchild;
		if (q->rchild != NULL)
			Q[++rear] = q->rchild;
	}

}
// 非递归前序遍历 OK
void PreOrder(BTree * T)
{
	cout << "非递归前序遍历" << endl;
	int top = -1;
	BTree * s[1000];
	while (T != NULL || top != -1)
	{
		while (T != NULL)
		{
			cout << T->data << endl;
			s[++top] = T;
			T = T->lchild;
		}
		if (top != -1)
		{
			T = s[top--];
			T = T->rchild;
		}
	}
}

//寻找最近的公共祖先
void ancestor(BTree* tree, BTree *m, BTree *n)
{

	int i = 0;
	TStack s;

	s.top = -1;
	BTree * p = tree;
	BTree * r = NULL;
	while (p != NULL || !isEmpty(s))
	{
		if (p != NULL) {
			push(&s, p);
			p = p->lchild;
		}
		else
		{

			p = getTop(s);
			if (p->rchild&&p->rchild != r)
			{
				p = p->rchild; //上一个结点向右边走
				push(&s, p);
				p = p->lchild;
			}
			else
			{
				p = pop(&s);
				printf("%5d", p->data);
				r = p;
				p = NULL;
			}
		}
	}
	printf("\n");
}

//非递归后序遍历
void postOrder(BTree * tree)
{

	int i = 0;
	TStack s;

	s.top = -1;
	BTree * p = tree;
	BTree * r = NULL;
	while (p != NULL || !isEmpty(s))
	{
		//cout<<"if "<<s.top<<"----------"<<s.data[s.top]->data<<endl;
		if (p != NULL) {
			push(&s, p);
			p = p->lchild;
			//            if(p==NULL){
			//              cout<<"left finish"<<endl;
			//        }
		}
		else
		{
			//      cout<<"tetst111111"<<endl;
			p = getTop(s);
			if (p->rchild&&p->rchild != r)
			{
				p = p->rchild; //上一个结点向右边走
				push(&s, p);
				p = p->lchild;
			}
			else
			{
				p = pop(&s);
				printf("%5d", p->data);
				r = p;
				p = NULL;
			}
		}
	}
	printf("\n");
}



void swap(BTree * b) {
	if (b) {
		swap(b->lchild);
		swap(b->rchild);
		// 从最底端开始交换，子结点所有子结点交换了之后
		// 交换这个两个上头的子结点
		BTree * temp = b->lchild;
		b->lchild = b->rchild;
		b->rchild = temp;
	}
}
//将前序变成后序序列
void preToPost(char pre[], int l1, int h1, char post[], int l2, int h2) {

	if (l1 <= h1) {

		// 处理结点，的第一个结点即为  的最后一个结点
		post[h2] = pre[l1];
		// 处理左边的左子树
		int half = (h1 - l1) / 2;
		preToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
		preToPost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1);
	}
}

void testBtree() {
	BTree *T = NULL;
	cout << "--------------- create tree-------------------\n";
	T = createTree(T);
	cout << "\n---------------   finish  ---------------------\n";
	cout << "test" << endl;
	PreOrderBiTree(T);
	cout << endl << "非叶子结点：";
	PreOrderBiTreeWithOutLeaf(T);
	cout << endl;
	char * pre = "1245367";
	char post[100];
	preToPost(pre, 0, 6, post, 0, 6);
	cout << "pre order:" << pre << endl;
	cout << "post order :" << post << endl;

}

void testBtree_char() {
	BTree_char * T = NULL;
	T = createTree_char(T);
	PreOrderBiTree_char(T);
	cout << endl;
	InOrderBiTree_char(T);
	cout << endl;
	BTree_char2E(T);
	cout << endl;
}
int main()
{
	//testBtree();
	testBtree_char();
	//int echoLeverWidth[100];
	/*
	int max = BTWidth(T);
	cout<<"max width is:"<<max<<endl;
	*/

	/*
	cout<<"\n------------------------------\n";
	//cout<<endl;
	postOrder(T);
	cout<<"\n------------------------------"<<endl;
	swap(T);
	PreOrderBiTree(T);
	postOrder(T);
	//PreOrder(T);

	*/



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
#ifdef WINVER
	printf("win");
	system("pause");
#endif // WINVER

	cout << endl;
	return 0;
}

