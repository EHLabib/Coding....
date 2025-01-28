#include<stdio.h>
int main()
{
    int max = -1 , smax =-1 , i, n = 5;
    int a[n];
    printf("Enter elements : ");
    for(i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
for(i=0; i<n; i++)
{
    if(a[i] > max)
    {
        smax=max;
        max=a[i];
    }
    else if(a[i] > smax )
    smax = a[i];
}
printf("Max = %d \n",max);
printf("Smax = %d",smax);
}
