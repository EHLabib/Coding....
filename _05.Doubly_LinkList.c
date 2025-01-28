#include <stdio.h>
#include <stdlib.h>
// Define the node structure
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
// Declare head, temp, and newnode pointers
struct node *head = NULL, *temp, *newnode;


// Function to create the doubly linked list
void create()
{
    char choice;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter first data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    head = temp = newnode;
    printf("\n Want to continue (Y/N): ");
    getchar(); // To consume the newline character left by the previous scanf
    choice = getchar();

    while(choice == 'y' || choice == 'Y')
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter next data: ");
        scanf("%d", &newnode->data);
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
        temp = newnode;
        printf("\n Want to continue (Y/N): ");
        getchar(); // To consume the newline character left by the previous scanf
        choice = getchar();
    }
}
// Function to display the doubly linked list
void display()
{
    if(head == NULL) printf("\n The list not found.");
    else
    {
        temp = head;
        printf("\n Doubly Linked List :  ");
        while(temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
//Insertion.........
void insert()
{
    if(head == NULL) printf("\n The list not found.");
    else
    {
        int choice;
        printf("\n 1. Insert First \t 2. Insert Middle \t 3. Insert Last ");
        printf("\n\t\t 4. Exit ");
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
    if(head == NULL) printf("\n The list not found.");
    else
    {
        do
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("\n Enter data : ");
            scanf("%d",&newnode->data);
            newnode->prev = NULL;
            newnode->next = NULL;
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
            printf("\n Want to continue (Y/N) : ");
            getchar(); // To consume the newline character left by the previous scanf
            choice = getchar();
        }
        while(choice == 'y' || choice == 'Y');
    }
}
void insert_Middle()
{
    int pos,i=1;
    char choice;
    if(head == NULL) printf("\n The list not found.");
    else
    {
        do
        {
            temp = head;
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("\n Enter position :  ");
            scanf("%d",&pos);
            printf("\n\t Enter data :  ");
            scanf("%d",&newnode->next);
            while( i < pos-1)
            {
                temp = temp->next;
                i++;
            }
            newnode->prev = temp;
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->next->prev = newnode;
            printf("\n Want to continue (Y/N) :  ");
            getchar();
            choice = getchar();
        }
        while(choice == 'y' || choice == 'Y');
    }
}
void insert_Last()
{
    char choice;
    if(head == NULL) printf("\n The list not found.");
    else
    {
        do
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("\n Enter data : ");
            scanf("%d",&newnode->data);
            newnode->prev = NULL;
            newnode->next = NULL;
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
            printf("\n Want to continue (Y/N) : ");
            getchar(); // To consume the newline character left by the previous scanf
            choice = getchar();
        }
        while(choice == 'y' || choice == 'Y');
    }
}
//Deletion........
void Delete()
{
    int choice;
    printf("\n 1. Delete First \t 2. Delete Middle \t 3. Delete Last ");
    printf("\n\t\t 4. Exit ");
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
void delete_First()
{
    if(head == NULL) printf("\n List is not found.");
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        printf("\n Deleted data :  %d ",temp->data);
        free(temp);
    }
}
void delete_Middle()
{
    int pos,i=0;
    char choice;
    if(head == NULL) printf("\n List is not found.");
    else
    {
        do
        {
            temp = head;
            printf("\n Enter the position :  ");
            scanf("%d",&pos);
            while(i<pos)
            {
                temp = temp->next;
                i++;
            }
            newnode = temp->prev;
            newnode->next = temp->next;
            printf("\n Deleted data : %d ",temp->data);
            free(temp);
            printf("\n Want to continue (Y/N) :  ");
            getchar();
            choice = getchar();
        }
        while(choice == 'Y' || choice == 'y');
    }
}
void delete_Last()
{
    char choice;
    if(head == NULL) printf("\n List is not found.");
    else
    {
        do
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            newnode = temp->prev;
            newnode->next = NULL;
            printf("\n Deleted data :  %d ",temp->data);
            free(temp);
            printf("\n Want to continue (Y/N) :  ");
            getchar();
            choice = getchar();
        }
        while(choice == 'Y' || choice == 'y');
    }
}

void reverse()
{
    if(head == NULL) printf("\n List not found.");
    else
    {
        newnode = head;
        while(newnode != NULL)
        {
            temp = newnode->next;
            newnode->next = newnode->prev;
            newnode->prev = temp;
            newnode = temp;
        }
        newnode = head;
        head = temp;
        temp = newnode;
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n.........Doubly Linked List.........");
        printf("\n\t 1. Create \t 2. Display ");
        printf("\n\t 3. Insertion \t 4. Deletion ");
        printf("\n\t 5. Reverse \t 6. Exit ");
        printf("\n....................................");
        printf("\n\n\t Enter your choice: ");
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
