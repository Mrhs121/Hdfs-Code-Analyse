#include <stdio.h>
#define TURE 1
#define FALSE 0

int isspace(char c){
    if(c==' ')
        return TURE;
    return FALSE;    
}



void printString(char str[]){
    char c;
    int i=0;
    while((c=str[i++])!='\0')
        printf("%c",c);
    printf("\n");
}

void expend(char s1[],char s2[]){
    char c;
    int i,j;
    i = j = 0;
    while(  (c=s1[i++])!='\0'   ){
        if(s1[i]=='-' && s1[i+1]>=c){
            i++;
            while(c<s1[i])
                s2[j++] = c++;
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}

int main()
{
    char str[] = {' ','h','s'};
    printf("%d %d\n",isspace(str[0]),isspace(str[1]));
    char s1[] = {'a','-','b','-',',','f','-','z'};
    char s2[] = {};
    expend(s1,s2);
    printString(s2);
    printf("Hello world\n");
    return 0;
}

