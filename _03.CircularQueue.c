//..........(DSA)- Circular Queue implementation using C..................

#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10

int cqueue[MAXSIZE], rear = -1,front = -1;

int main()
{
    int choice;
    while(1)
    {
        printf("\n\n.........................Circular Queue Menu..............................\n");
        printf("\n\t 1.Insert \n\t 2.Delete \n\t 3.Display \n\t 4.Clear \n\t 5.Exit \n");
        printf("..........................................................................\n");
        printf("\n\t\t Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1 :
            insert();
            break;
        case 2 :
            Delete();
            break;
        case 3 :
            display();
            break;
        case 4 :
            system("cls");
            break;
        case 5 :
            printf("\n\n Thanks for co-operation.\n");
            exit(0);
        default :
            printf("\n Invalid Choice. \n");
        }
    }
}
//......Insert function.............
void insert()
{
    int n;
    if((rear+1)%MAXSIZE == front )
        printf("\n********** The Circular Queue is over-flow. **********\n");
    else
    {
        printf("\n\t\t\t Enter an elements : ");
        scanf("%d",&n);
        if(front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
            rear = (rear+1)%MAXSIZE;
        cqueue[rear] = n;
    }
}
//........Display function..............
void display()
{
    int i;
    if(rear == -1 && front == -1)  printf("\n********* The Circular Queue is empty. ***********\n");
    else
    {
        printf("\n Elements of Circular Queue is : ");
        for(i=front; i != rear; (i=((i+1)%MAXSIZE)) )
            printf("%d ",cqueue[i]);
    }
    printf("%d ",cqueue[i]);
}
//........Delete function..........
void Delete()
{
    int n;
    if(rear == -1 && front == -1)
        printf("\n********** The Circular Queue is empty. ***********\n");
    else
    {
        n= cqueue[front];
        printf("\n\t Deleted element is : %d \n",n);
        if(rear == front)
        {
            rear = -1;
            front = -1;
        }
        front = ((front+1)%MAXSIZE);
    }
}
