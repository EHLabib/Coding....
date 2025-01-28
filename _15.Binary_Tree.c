//..........Binary tree..............
struct node
{
    int data;
    struct node *left, *right;
};
struct node *create()
{
    struct node *newnode;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter data ( -1 for exit) :  ");
    scanf("%d",&x);
    if( x == -1 ) return 0;
    newnode->data = x;
    printf("\n Enter left child of %d  :  ",x);
    newnode->left = create();
    printf("\n Enter right child of %d  :  ",x);
    newnode->right = create();
    return newnode;
};
void main()
{
    struct node *root;
    root = 0;
    root = create();
    printf("\n Pre-order  :   ");
    pre_order(root);
    printf("\n In-order  :    ");
    in_order(root);
    printf("\n Post-order  :  ");
    post_order(root);
}
void pre_order(struct node *root)
{
    if(root == 0)  return;
    printf("%d \t",root->data);
    pre_order(root->left);
    pre_order(root->right);
}
void in_order(struct node *root)
{
    if( root == 0) return;
    in_order(root->left);
    printf("%d \t",root->data);
    in_order(root->right);
}
void post_order(struct node *root)
{
    if(root == 0)    return;
    post_order(root->left);
    post_order(root->right);
    printf("%d \t",root->data);
}
