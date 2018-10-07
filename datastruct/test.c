#include <stdio.h>


void test()
{

}
void test2(){
    printf("i am god_huang!\n");
}


int main()
{
    int a[2][3] = {1,2,3,4,5,6};
    int i = 0;
    int j = 0;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%d,",a[i][j]);
        }
    }
    // int b[2][3] = a;
    /*
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
*/
    printf("Hello world\n");
    return 0;
}

