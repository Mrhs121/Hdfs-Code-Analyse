#include <stdio.h>

int main()
{
    FILE * fin = fopen("aa.txt","r");
    char a ;
    fscanf(fin,"%c\n",&a);
    printf("%c\n",a);
        fscanf(fin,"%c",&a);
    printf("%c\n",a);
   fscanf(fin,"%c\n",&a);
    printf("%c\n",a);
   fscanf(fin,"%c\n",&a);
    printf("%c\n",a);
   fscanf(fin,"%c\n",&a);
    printf("%c\n",a);
   fscanf(fin,"%c\n",&a);
    printf("%c\n",a);

    printf("Hello world\n");
    return 0;
}

