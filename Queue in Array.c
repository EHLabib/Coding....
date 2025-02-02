/////..........Queue in Array...................
#include<stdio.h>
#define size 5
int queue[size];
int front = -1, rear = -1;
void enque()
{
    if(rear == size-1) printf("\n Queue is full.");
    else
    {
        int x;
        if(front == -1) front = 0;

        rear++;
        printf("\n Enter data : ");
        scanf("%d",&x);
        queue[rear]=x;
    }
}
void deque()
{
    if(front == -1) printf("\n Queue is empty.");
    else
    {
        printf("\n Deque data : %d",queue[front]);
        front++;
        if(front > rear)
            front = rear = -1;
    }
}
void display()
{
    if(rear == -1) printf("\n Queue is empty.");
    else
    {
        printf("\n Queue data :");
        for(int i=front; i<=rear; i++)
        {
            printf("\t%d",queue[i]);
        }
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n\n 1.Enque   2.Deque   3.Display   4.Exit");
        printf("\n \t  Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :
            enque();
            break;
        case 2 :
            deque();
            break;
        case 3 :
            display();
            break;
        case 4 :
            return 0;
            break;
        default :
            printf("\n Invalid choice.");
        }
    }
}
