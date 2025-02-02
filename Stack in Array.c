/////........Stack in Array...............
#include<stdio.h>
#define n 5
int top = -1;
int stack[n];
void push()
{
    if(top == n-1)printf("\n Stack is full.");
    else
    {
        int x;
        top++;
        printf("\n Enter value : ");
        scanf("%d",&x);
        stack[top] = x;
    }
}
void pop()
{
    if(top == -1)printf("\n Stack is empty.");
    else
    {
        printf("\n Poped element = %d \n",stack[top]);
        top--;
    }
    printf("\n\n");
}
void display()
{
    if(top == -1)printf("\n Stack is empty.");
    else
    {
        printf("\n Stack element : ");
        for(int i=top; i>=0; i--)
        {
            printf("%d \t ",stack[i]);
        }
    }
    printf("\n\n");
}
void peek()
{
    if(top == -1)printf("\n Stack is empty.");
    else
    {
        printf("\n Top element = %d ",stack[top]);
    }
    printf("\n\n");
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n 1.Push  2.Pop  3.Peek  4.Display  5.Exit");
        printf("\n\n\t Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :
            push();
            break;
        case 2 :
            pop();
            break;
        case 3 :
            peek();
            break;
        case 4 :
            display();
            break;
        case 5 :
            return 0;
        default :
            printf("\n Invalid choice.");
        }
    }


}
