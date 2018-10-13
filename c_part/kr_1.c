#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
void printString(char str[]);
void reverse(char s[],int size)
{
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
int main()
{
    char s[MAXLINE];
    getLine(s,MAXLINE);
    char str[] = {'a','b','c','d','e','f','g','h','j','k','\0'};
    reverse(str,10);
    return 0;
}

