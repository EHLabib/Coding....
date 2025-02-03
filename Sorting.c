//...................Sorting...................
#include<stdio.h>
#include<stdlib.h>

/////..............Printing the Array...............
void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\t%d",arr[i]);
    }
    printf("\n\n");
}
/////...........Bubble Sort........................
void bubbleSort(int arr[] ,int n)
{
    printf("\n After Bubble Sort :");
    int temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    print(arr, n);
}
/////.........Selection Sort.................
void selectionSort(int arr[] ,int n)
{
    printf("\n After Selection Sort :");
    int min,minpos,i,j;
    for( i=0; i<n-1; i++)
    {
        min = arr[i];
        minpos = i;
        for( j=i+1; j<n; j++)
        {
            if( arr[j] < min )
            {
                min = arr[j];
                minpos = j;
            }
        }
        int temp = arr[i];
        arr[i] =  arr[minpos];
        arr[minpos] = temp;
    }
    print(arr, n);
}
/////.............Insertion Sort...............
void insertionSort(int arr[] , int n)
{
    printf("\n After Insertion Sort :");
    int i,j;
    for(i=0; i<n; i++)
    {
        int key = arr[i];
        j = i-1;
        while(j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    print(arr , n);
}

int main()
{
    int n;
    printf("\n Enter size of Array : ");
    scanf("%d",&n);
    int arr[n];

    printf("\n Enter Array element : ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n Before Sort : ");
    print(arr, n);
    bubbleSort(arr , n);
    selectionSort(arr , n);
    insertionSort(arr , n);
}
