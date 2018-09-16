/*************************************************************************
	> File Name: test.c
	> Author:黄大神 
	> Mail: 
	> Created Time: Sun 16 Sep 2018 04:23:46 PM CST
 ************************************************************************/



// 帮助理解指针以及指向指针的指针
#include<stdio.h>
#include<stdlib.h>


int b = 123;
void test(int * p)
{
    printf("xin p : %p\n",&p);
    *p = 10000;
    p = &b;
}


void change(int **p){
    *p = &b;
}

int main()
{
    int a = 1;
    printf("a address:%p, b address:%p\n",&a,&b);
    int *p = &a;
    printf("a = %d:,%p, p->%p\n",a,&p,p);
    test(p);
    printf("a = %d:, *p = %d,%p,p->%p\n",a,*p,&p,p); 
    change(&p);
    printf("*p = %d,p->%p\n",*p,p);
    return 0;
}

