#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *add;
};
struct node *start=NULL,*new1,*temp,*prev,*next;

void main()
{
    int choice;
    do
    {
        printf("\n..............Linked List Menu.................");
        printf("\n\t 1. Create ");
        printf("\n\t 2. Display ");
        printf("\n\t 3. Insert First ");
        printf("\n\t 4. Insert Middle ");
        printf("\n\t 5. Insert Last ");
        printf("\n\t 6. Delete First ");
        printf("\n\t 7. Delete Middle ");
        printf("\n\t 8. Delete Last ");
        printf("\n\t 9. Count Node ");
        printf("\n\t 10. Search ");
        printf("\n\t 11. Reverse ");
        printf("\n\t 12. Clear ");
        printf("\n\t 13. Exit ");
        printf("\n......................................................");
        printf("\n\t\t Enter your choice : ");
        scanf("%d",&choice);


        switch(choice)
        {
        case 1 :
            create();
            break;
        case 2 :
            display();
            break;
        case 3 :
            insert_First();
            break;
        case 4 :
            insert_Middle();
            break;
        case 5 :
            insert_Last();
            break;
        case 6 :
            delete_First();
            break;
        case 7 :
            delete_Middle();
            break;
        case 8 :
            delete_Last();
            break;
        case 9 :
            count_Node();
            break;
        case 10 :
            search_Data();
            break;
        case 11 :
            reverse_Node();
            break;

        case 12 :
            system("cls");
            break;
        default :
            printf("\n Invalid choice \n");
        }
    }
    while(choice != 13);
}
create()
{
    int n;
    char ch;
    printf("\n\t Enter First element : ");
    scanf("%d",&n);
    start = (struct node*)(malloc (sizeof(struct node)));
    start -> data = n;
    start -> add = NULL;
    temp = start;
    printf("\n Do you want to continue (Y/N) : ");
    ch = getche();
    while(ch=='y' || ch=='Y')
    {
        printf("\n Enter next element : ");
        scanf("%d",&n);
        new1=(struct node*)(malloc(sizeof(struct node)));
        new1 -> data = n;
        new1 -> add = NULL;
        temp -> add = new1;
        temp = temp -> add;
        printf("\n Do you want to continue (Y/N) : ");
        ch = getche();
    }
}
display()
{
    if(start == NULL)  printf("\n List not found.");
    else
    {
        temp = start;
        while(temp != NULL)
        {
            printf("%d\t",temp -> data);
            temp = temp -> add;
        }
    }

}
insert_First()
{
    int n;
    if(start == NULL) printf("\n List not found.");
    else
    {
        printf("\n Enter element : ");
        scanf("%d",&n);
        new1 = (struct node*)(malloc(sizeof(struct node)));
        new1 -> data = n;
        new1 -> add = NULL;
        new1 -> add = start;
        start = new1;
    }
}
insert_Middle()
{
    int n,pos,i=1;
    if(start == NULL) printf("\n List not found.");
    else
    {
        printf("\n Enter element : ");
        scanf("%d",&n);
        new1=(struct node*)(malloc(sizeof(struct node)));
        new1 -> data = n;
        new1 -> add = NULL;
        printf("\n Enter position : ");
        scanf("%d",&pos);
        next = start;
        while(i<pos)
        {
            prev = next;
            next = next -> add;
            i++;
        }
        prev -> add = new1;
        new1 -> add = next;
    }
}
insert_Last()
{
    int n;
    if(start == NULL)  printf("\n List not found.");
    else
    {
        printf("\n Enter element : ");
        scanf("%d",&n);
        new1 = (struct node*)(malloc(sizeof(struct node)));
        new1 -> data = n;
        new1 -> add = NULL;
        temp = start;
        while(temp -> add != NULL)
        {
            temp = temp -> add;
        }
        temp -> add = new1;
    }

}
delete_First()
{
    if(start == NULL) printf("\n List not found.");
    else
    {
        temp = start;
        start = start -> add;
        printf("\n Deleted element : %d ",temp -> data);
        free(temp);
    }
}
delete_Middle()
{
    int pos,i=1;
    if(start == NULL) printf("\n List is not found. ");
    else
    {
        printf("\n Enter the position : ");
        scanf("%d",&pos);
        temp = start;
        while(i<pos)
        {
            prev = temp;
            temp = temp->add;
            i++;
        }
        next = temp->add;
        prev->add = next;
        printf("\n Deleted element : %d ",temp->data);
        free(temp);
    }
}
delete_Last()
{
    if(start == NULL) printf("\n List not found.");
    else
    {
        temp = start;
        while( temp -> add != NULL)
        {
            prev = temp;
            temp = temp -> add;
            prev -> add = NULL;
            printf("\n Deleted element : %d ",temp->data);
            free(temp);
        }
    }
}
count_Node()
{
    int count=0;
    if(start == NULL) printf("\n List not found.");
    else
    {
        temp = start;
        while(temp != NULL)
        {
            count++;
            temp = temp->add;
        }
        printf("\n Total Node : %d ",count);
    }
}
search_Data()
{
    int search,F=0;
    if(start == NULL) printf("\n List not found. ");
    else
    {
        printf("\n Enter element for Search : ");
        scanf("%d",&search);
        temp = start;
        while(temp != NULL)
        {
            if(temp->data == search)
            {
                F=1;
                break;
            }
            temp = temp->add;
        }
        if(F==1) printf("\n\t Element found.");
        else printf("\n\t Element not found.");
    }
}
reverse_Node()
{
    if(start == NULL) printf("\n List not found. ");
    else
    {
        prev = NULL;
        temp = next = start;
        while(next != NULL)
        {
            next = next->add;
            temp->add = prev;
            prev = temp;
            temp = next;
        }
        start = prev;
    }

}
