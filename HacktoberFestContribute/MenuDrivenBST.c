#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left, *right;  
}*root=NULL;

struct node* insert(struct node* root, int ele)
{
  if(root == NULL)
  {
    root = (struct node*) malloc(sizeof(struct node));
    root->data = ele;
    root->left = NULL;
    root->right = NULL;
  }
  if (ele < root->data) 
        root->left  = insert(root->left, ele); 
    else if (ele > root->data) 
        root->right = insert(root->right, ele);        
    return root; 
}

void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
} 

void preorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
      printf("%d \n", root->data);
        preorder(root->left);  
        preorder(root->right); 
    } 
} 

void postorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left);  
        postorder(root->right); 
        printf("%d \n", root->data);
    } 
}

int search(struct node *root)
{
  int ele;
  printf("\nEnter the element to be searched: ");
  scanf("%d", &ele);
  while(root != NULL)
  {
    if(ele > root->data)
      root = root->right;
    else if(ele < root->data)
      root = root->left;
    else
      return 1;
  }
  return 0;
}

int main()
{
  int opt, opt1, opt2, ele;
  do
  {
    printf("\nBST Menu: \n1.Insert \n2.Traversal \n3.Search \n");
    printf("\nEnter your choice: ");
    scanf("%d", &opt1);
    switch(opt1)
    {
      case 1:
        printf("\nEnter the data of the node: ");
        scanf("%d", &ele);
        root = insert(root, ele);
        break;
      case 2:
        printf("\nTraversal Menu: \n1.In-order \n2.Pre-order \n3.Post-order \n");
        printf("\nEnter your choice: ");
        scanf("%d", &opt2); 
        switch(opt2)
        {
          case 1: 
            printf("\nIn-order traversal: \n");
            inorder(root);
            break;
          case 2:
            printf("\nPre-order traversal: \n");
            preorder(root);
            break;
          case 3:
            printf("\nPost-order traversal: \n");
            postorder(root);
            break;
          default:
            printf("\nEnter valid choice.");
        }
        break;
      case 3:
        if(search(root) == 1)
          printf("\nElement found.\n");
        else
          printf("\nElement not found.\n");
        break;
      default:
        printf("Enter valid choice.\n");
    }
  printf("\nDo you want to continue? Press 1 to continue, 0 to exit: ");
  scanf("%d", &opt);  
  }while(opt!=0);
  return 0;
}
