// Insertion Sorting...............
#include<stdio.h>
int main()
{
    int n,i,j;
    printf("Enter Array Size : ");
    scanf("%d",&n);
    int a[n];
    printf("\n Enter Array Elements : \n");
    for(i=0; i<n; i++)
    {
        printf("A[%d] = ",i);
        scanf("%d",&a[i]);
    }
    printf("\n Before Sort : ");
    for(i=0; i<n; i++)
    {
        printf("  %d",a[i]);
    }

    //Insertion Sort 
    for(i=0; i<n; i++)
    {
        int key = a[i];
        j = i-1;
        while(j >= 0  &&  key < a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    printf("\n After Sort : ");
    for(i=0; i<n; i++)
    {
        printf("  %d",a[i]);
    }    

}
