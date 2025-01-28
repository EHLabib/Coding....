#include<stdio.h>
int main()
{
    int n,m;
    printf(" n = ");
    scanf("%d",&n);
    printf("\n m = ");
    scanf("%d",&m);
    int *p1=&n,*p2=&m;

    printf("\n &n = %d \n &m = %d \n",p1,p2);
    printf("\n n = %d \n m = %d \n",*p1,*p2);
    *p1= *p1+*p2;
    *p2=*p1-*p2;
    *p1= *p1-*p2;

    printf("\n n = %d \n m = %d \n",*p1,*p2);

    printf("Sum = %d \n",*p1+*p2);

    int **pp1=&p1,**pp2=&p2;
    printf("\n &n = %d \n &m = %d \n",pp1,pp2);
    printf("\n n = %d \n m = %d \n",**pp1,**pp2);
/////////////////////////////////////////////////////////////////////////////////
    int ***ppp1=&pp1,***ppp2=&pp2;
    printf("\n &n = %d \n &m = %d \n",ppp1,ppp2);
    printf("\n n = %d \n m = %d \n",***ppp1,***ppp2);
////////////////////////////////////////////////////////////////////////////////////
    int ****pppp1=&ppp1,****pppp2=&ppp2;
    printf("\n &n = %d \n &m = %d \n",pppp1,pppp2);
    printf("\n n = %d \n m = %d \n",****pppp1,****pppp2);

    ****pppp1= ****pppp1+****pppp2;
    ****pppp2=****pppp1-****pppp2;
    ****pppp1= ****pppp1-****pppp2;

    printf("\n ****n = %d \n ****m = %d \n",****pppp1,****pppp2);

    printf("Sum ****= %d \n",(****pppp1+100)+****pppp2);
//////////////////////////////////////////////////////////////////////
    int *****ppppp1 = &pppp1, *****ppppp2 = &pppp2;
    printf("\n &n = %d \n &m = %d \n",ppppp1, ppppp2);
    printf("\n n = %d \n m = %d \n",*****ppppp1, *****ppppp2);

    *****ppppp1= *****ppppp1 + *****ppppp2;
    *****ppppp2=*****ppppp1 - *****ppppp2;
    *****ppppp1= *****ppppp1 - *****ppppp2;

    printf("\n n 5* = %d \n m 5* = %d \n",*****ppppp1,*****ppppp2);

    printf("Sum 5*= %d \n",(*****ppppp1+200)+*****ppppp2);

    return 0;
}
