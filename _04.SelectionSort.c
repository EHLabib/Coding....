//  Selection Sorting.......
#include<stdio.h>
int main()
{
    int n,i,j;
    printf(" Enter size : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter Array elements : \n");
    for(i=0; i<n; i++)
    {
        printf("A[%d] = ",i);
        scanf("%d",&a[i]);
    }
    printf("\n\t Befofe Sort : ");
    for(i=0; i<n; i++)
    {
        printf("  %d",a[i]);
    }
    //  Selection sort : 
    int min,minpos;
    for(i=0; i<n-1; i++)
    {
        min = a[i];
        minpos = i;
        for(j=i+1; j<n; j++)
        {
            if( a[j] < min )
            {
                min = a[j];
                minpos = j;
            }
        }
        int temp = a[i];
        a[i] =  a[minpos];
        a[minpos] = temp;
    }
    printf("\n\t After Sort : ");
    for(i=0; i<n; i++)
    {
        printf("  %d",a[i]);
    }
    
}
