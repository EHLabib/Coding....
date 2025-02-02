////............Linear Search.........
#include<stdio.h>

void linearSearch(int arr[], int n)
{
    int keyValue,count=0;
    printf("\n Enter key = ");
    scanf("%d",&keyValue);
    for(int i=0; i<n; i++)
    {
        if(arr[i] == keyValue)
            count++;
    }
    if(count > 0)printf("\nKey value is found.");
    else printf("\n Key value is not found.");
}

int main()
{
    int size;
    printf("\n Enter size of Array : ");
    scanf("%d",&size);
    int arr[size];
    printf(" Enter  element :  ");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n Element : ");
    for(int i=0; i<size; i++)
    {
        printf("%d \t",arr[i]);
    }
    linearSearch(arr, size);
}


