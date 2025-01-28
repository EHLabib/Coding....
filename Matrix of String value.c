//  Matrix of String value..........
#include<stdio.h>
#include<string.h>
main()
{
    int i,j,row,col;
    printf("  Enter Row :");
    scanf("%d",&row);
    printf("\n  Enter Column :");
    scanf("%d",&col);
    char A[row][col];

    printf("\n Enter Matrix of  String Value :\n");
    for(i=0; i<row; i=i+1)
    {
        for(j=0; j<col; j=j+1)
        {
            printf("A[%d][%d] = ",i,j);
            scanf(" %c", &A[i][j]);
        }
    }
    printf("\n \nMatrix of String = \n");
    for(i=0; i<row; i=i+1)
    {
        for(j=0; j<col; j=j+1)
        {
            printf(" %c", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
