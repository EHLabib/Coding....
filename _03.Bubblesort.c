//#include<stdio.h>
#include<stdbool.h>

int main()
{
    int n=10;
    int a[10] = {3,6,20,9,30,5,81,55,120,7};
    printf(" Before sort : ");
    for(int i=0; i<n; i++)
    {
        printf("%d  ",a[i]);
    }
//............................................................................    
    printf("\n  After Sort in Assending : ");
    for(int i=0; i<n-1; i++)
    {
        bool flag = true;
        for(int j=0; j<n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = false;
            }
        }
        if(flag == true)   break;
    }
    for(int i=0; i<n; i++)
    {
        printf("%d  ",a[i]);
    }
//................................................................    
    printf("\n  After Sort in Desending : ");
    for(int i=0; i<n-1; i++)
    {
        bool flag = true;
        for(int j=0; j<n-1-i; j++)
        {
            if(a[j] < a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = false;
            }
        }
        if(flag == true) break;
    }
    for(int i=0; i<n; i++)
    {
        printf("%d  ",a[i]);
    }
}
