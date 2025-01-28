//Circular Doubly link list......
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL,*newnode,*prev,*next,*temp,*tail;

int main()
{
    int choice;
    while(1)
    {
        printf("\n\t............Circular Doubly Linked List..............");
        printf("\n\t\t 1. Create \t 2. Display ");
        printf("\n\t\t 3. Insertion \t 4. Deletion ");
        printf("\n\t\t 5. Exit ");
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
    head = NULL;
    do
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter data :  ");
        scanf("%d",&newnode->data);
        if(head == NULL)
        {
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
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
    if(head == NULL )  printf("\n List is not found.");
    else
    {
        temp = head;
        printf("\n\t Data :  ");
        while(temp != tail)
        {
            printf(" %d \t",temp->data);
            temp = temp->next;
        }
        printf("%d \n",temp->data);
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
        printf("\n\n\t\t Enter your choice : ");
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
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
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
        printf("\n Enter position :  ");
        scanf("%d",&pos);
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter data :   ");
        scanf("%d",&newnode->data);
        while(i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
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
        newnode->prev = tail;
        tail->next = newnode;
        newnode->next = head;
        head->prev = newnode;
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
    if(head = NULL) printf("\n List is not found.");
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
    temp = head;
    if(head->next == head)
    {
        head = tail =NULL;
        printf("\n Deleted data :  %d ",temp->data);
        free(temp);
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
        printf("\n Deleted data =  %d ",temp->data);
        free(temp);
    }
}
void delete_Middle()
{
    int pos,i=1;
    temp = head;
    printf("\n Enter the position  :  ");
    scanf("%d",&pos);
    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("\n Deleted data :  %d  ",temp->data);
    free(temp);
}
void delete_Last()
{
    temp = tail;
    if(head->next == head)
    {
        head = tail = NULL;
        printf("\n Deleted data :  %d  ",temp->data);
        free(temp);
    }
    else
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        printf("\n Deleted data :  %d ",temp->data);
        free(temp);
    }
}
