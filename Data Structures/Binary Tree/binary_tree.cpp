#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
// Binary Tree definition
typedef struct Btree
{
    int data;
    struct Btree *left;
    struct Btree *right;
} Btree;


// function to insert values inside a binary tree
Btree *putValue(Btree *root, int data)
{
    Btree *nn = new Btree();
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    if (root == NULL)
        return nn;

    queue<Btree *> q;
    q.push(root);
    while (!q.empty())
    {
        Btree *node = q.front();
        q.pop();
        if (node->left)
            q.push(node->left);
        else
        {
            node->left = nn;
            return root;
        }
        if (node->right)
            q.push(node->right);
        else
        {
            node->right = nn;
            return root;
        }
    }
}

// inorder traversal of binary tree using recursion
void inOrder(Btree *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// preorder traversal of binary tree using recursion
void preOrder(Btree *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
// postorder traversal of binary tree using recursion
void postOrder(Btree *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// inorder traversal of binary tree iteratively

void inOrderIterative(Btree *root)
{
    stack<Btree *> stk;
    while (1)
    {
        while (root)
        {
            stk.push(root);
            root = root->left;
        }
        if (stk.empty())
            return;
        root = stk.top();
        stk.pop();
        printf("%d ", root->data);
        root = root->right;
    }
}

// preorder traversal of binary tree iteratively
void preOrderIterative(Btree *root)
{
    stack<Btree *> stk;
    while (1)
    {
        while (root)
        {
            printf("%d ", root->data);
            stk.push(root);
            root = root->left;
        }
        if (stk.empty())
            return;
        root = stk.top();
        stk.pop();
        root = root->right;
    }
}
// using  2 stacks postorder iterative traversal
void postOrderIterative(Btree *root)
{
    stack<Btree *> stk1;
    stack<Btree *> stk2;
    stk1.push(root);
    while (1)
    {
        if (stk1.empty())
            break;
        root = stk1.top();
        stk1.pop();
        stk2.push(root);
        if (root->left)
            stk1.push(root->left);
        if (root->right)
            stk1.push(root->right);
    }
    while (!stk2.empty())
    {
        Btree *node = stk2.top();
        printf("%d ", node->data);
        stk2.pop();
    }
}

// height of binary tree
int height(Btree *root) {
    if(root==NULL)
        return 0;
    return 1+(max(height(root->left), height(root->right)));
}


int main()
{
    Btree *root = NULL;
    root = putValue(root, 1);
    root = putValue(root, 2);
    root = putValue(root, 3);
    root = putValue(root, 4);
    root = putValue(root, 5);
    root = putValue(root, 6);
    root = putValue(root, 7);

    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrderIterative(root);
    cout << endl;
    return 0;
}
