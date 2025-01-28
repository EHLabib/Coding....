#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL,*newnode,*temp,*prev,*next,*tail;

int main()
{
    int choice;
    while(1)
    {
        printf("\n\t............Circular Linked List..............");
        printf("\n\t\t 1. Create \t 2. Display ");
        printf("\n\t\t 3. Insertion \t 4. Deletion ");
        printf("\n\t\t 5. Reverse \t 6. Exit ");
        printf("\n\t...............................................");
        printf("\n\n\t\t Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            Delete();
            break;
        case 5:
            reverse();
            break;
        case 6 :
            exit(0);
            break;
        default:
            printf("\n Invalid choice.");
        }

    }

    return 0;
}
//.............Creating a new node...............
void create()
{
    char choice;
    tail = NULL;
    do
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter data :   ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        if(tail == NULL)
        {
            tail = newnode;
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        printf("\n Want to continue (Y/N):   ");
        getchar();
        choice = getchar();
    }
    while(choice == 'Y' || choice == 'y');
}
void display()
{
    if(tail == NULL )  printf("\n List is not found.");
    else
    {
        printf("\n Data :  ");
        temp = tail->next;
        do
        {
            printf(" %d \t",temp->data);
            temp = temp->next;
        }
        while(temp != tail->next);
    }
}
//.............Insertion.........
void insert()
{
    if(tail->next == NULL) printf("\n The list not found.");
    else
    {
        int choice;
        printf("\n 1. Insert First \t 2. Insert Middle \t 3. Insert Last ");
        printf("\n\t\t Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :
            insert_First();
            break;
        case 2 :
            insert_Middle();
            break;
        case 3 :
            insert_Last();
            break;
        default :
            printf("\n Invalid choice.");
        }
    }
}
void insert_First()
{
    char choice;
    do
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter data :   ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        newnode->next = tail->next;
        tail->next = newnode;
        printf("\n Want to continue (Y/N):   ");
        getchar();
        choice = getchar();
    }
    while(choice == 'Y' || choice == 'y');
}
void insert_Middle()
{
    int pos,i=1;
    char choice;
    do
    {
        printf("\n Enter the position :  ");
        scanf("%d",&pos);
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter data :   ");
        scanf("%d",&newnode->data);
        temp = tail->next;
        while(i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        printf("\n Want to continue (Y/N):  ");
        getchar();
        choice = getchar();
    }
    while(choice == 'Y' || choice == 'y');
}
void insert_Last()
{
    char choice;
    do
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter data :  ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
        printf("\n Want to continue (Y/N):   ");
        getchar();
        choice = getchar();
    }
    while(choice == 'Y' || choice == 'y');
}
//............Deletion.................
void Delete()
{
    int choice;
    if(tail->next = NULL) printf("\n List is not found.");
    else
    {
        printf("\n 1. Delete First \t 2. Delete Middle \t 3. Delete Last ");
        printf("\n\t\t Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :
            delete_First();
            break;
        case 2 :
            delete_Middle();
            break;
        case 3 :
            delete_Last();
            break;
        default :
            printf("\n Invalid choice.");
        }
    }
}
void delete_First()
{
    temp = tail->next;
    if( temp->next == temp )
    {
        tail = NULL;
        printf("\n Deleted data :  %d ",temp);
        free(temp);
    }
    else
    {
        tail->next = temp->next;
        printf("\n Deleted data : %d  ",temp);
        free(temp);
    }
}
void delete_Middle()
{
    int pos,i=1;
    temp = tail->next;
    printf("\n Enter the position  :  ");
    scanf("%d",&pos);
    while(i < pos)
    {
        temp = temp->next;        // temp = current_node
        i++;
    }
    newnode = temp->next;        // new_node = next_node
    temp->next = newnode->next;
    printf("\n Deleted data : %d ",temp);
    free(temp);
}
void delete_Last()
{
    struct node *prev_Node;
    temp = tail->next;
    if(temp->next == temp)
    {
        tail = NULL;
        printf("\n Deleted data :   ");
        free(temp);
    }
    else
    {
        while(temp->next != tail->next)
        {
            prev_Node = temp;
            temp = temp->next;
        }
        prev_Node->next = tail->next;
        tail = prev_Node;
        printf("\n Deleted data :  %d",temp);
        free(temp);
    }
}
void reverse()
{
    struct node *current,*prev,*next_Node;
    current = tail->next;
    if(tail == NULL)  printf("\n List is not found.");
    else
    {
        while(current != tail)
        {
            prev = current;
            current = next_Node;
            next_Node = current->next;
            current->next = prev;
        }
        next_Node->next = tail;
        tail = next_Node;
    }
}
