#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000



void printString(char str[]);
void getLine(char s[],int lim);


void reverse(char s[],int size)
{
    printf("size :%d\n",size);
    printString(s);
}
void printString(char str[]){
    int i=0;
    char c = str[i];
    while(c!='\0'){
        printf("%c",c);
        c = str[++i];
    }
    printf("\n");
    
}

void   itoa   (   unsigned   long   val,   char   *buf,   unsigned   radix    )   
{   
                char   *p;                                 /*   pointer   to   traverse   string   */   
                char   *firstdig;                   /*   pointer   to   first   digit   */   
                char   temp;                             /*   temp   char   */   
                unsigned   digval;                 /*   value   of   digit   */   

                p   =   buf;   
                firstdig   =   p;                       /*   save   pointer   to   first   digit   */   

                do   {   
                                        digval   =   (unsigned)   (val   %   radix);   
                                        val   /=   radix;               /*   get   next   digit   */   
                
                                        /*   convert   to   ascii   and   store   */   
                                        if   (digval   >   9)   
                                                *p++   =   (char   )   (digval   -   10   +   'a');     /*   a   letter   */   
                                        else   
                                                *p++   =   (char   )   (digval   +   '0');               /*   a   digit   */   
                                }   while   (val   >   0);   

                /*   We   now   have   the   digit   of   the   number   in   the   buffer,   but   in   reverse   
                 *                         order.     Thus   we   reverse   them   now.   */   

                *p--='\0';                       /*   terminate   string;   p   points   to   last   digit   */   

                do   {   
                                        temp   =   *p;   
                                        *p   =   *firstdig;   
                                        *firstdig   =   temp;       /*   swap   *p   and   *firstdig   */   
                                        --p;   
                                        ++firstdig;                   /*   advance   to   next   two   digits   */   
                                }   while   (firstdig   <   p);   /*   repeat   until   halfway   */   
}
void getLine(char s[],int lim)
{
    FILE * fin = fopen("./test.txt","r");
    char c;
    int i=0;
    int line=0;
    while( i<lim && (fscanf(fin,"%c",&c))!=EOF  ){
        s[i] = c;
        if(c=='\n')
            line++;
        i++;
        printf("%c",c);
    }
    printf("this text has %d lines\n",line);
}

void BitwiseOperation(){
    int a = 312 & 0177; // 屏蔽312的非低7位，0177为八进制，对应的二进制位000 001 111 111
    printf("%d\n",a);
    int b = ~077;
    printf("~4 = %d\n",b);
}

// 从x的第start位开始，取len位数，假定第一位从0开始
int getBits(int x,int start,int len){
    int a = x>>(start-len+1);// 先将期望得到的字段移动到最右端
    int res = a & ~(~0 << len); // ~0所有位全为1，向左移动n位，右边n位用0填补，再取反，右边n位变为1的屏蔽码
    return res;
}

int setbits(int x,int p,int n,int y){
    // 先取出这n位
    int _n = getBits(x,p,n);
    printf("_n = %d\n",_n);
    // 然后将y的右边的n全部变为0
    y = (y>>n)<<n;
    return y | _n;
} // nice

int main()
{
    char s[MAXLINE];
    getLine(s,MAXLINE);
    char str[] = {'a','b','c','d','e','f','g','h','j','k','\0'};
    //reverse(str,10);
    BitwiseOperation();
    printf("getBits %d\n",getBits(99,5,5));
    printf("setbits %d\n",setbits(17,3,3,31));
    return 0;
}

