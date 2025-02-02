////..........Binary Search...........
#include<stdio.h>

void binarySearch(int arr[], int low, int high)
{
    int key, count = 0;
    printf("\n Enter key value : ");
    scanf("%d",&key);

    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == key)
        {
            printf("\n Element found at %d position.\n",mid+1);
            count = 1;
            return;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(count == 0) printf("\n Element not found.\n");

}

int main()
{
    int size;
    printf("\n Enter size of Array : ");
    scanf("%d",&size);
    int arr[size];
    printf("\n Enter Array element : ");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }

    binarySearch(arr, 0, size-1);
}
