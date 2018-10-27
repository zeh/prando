#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int key)
{
    Node* new_node = new Node;
    new_node->data = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void Inorder(Node* temp)
{
    if(temp==NULL)
    return;
    Inorder(temp->left);
    cout<<temp->data<<" ";
    Inorder(temp->right);
}
void insert(Node* root, int key)
{
    Node* temp = root;
    queue <struct Node*> q;
    q.push(temp);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(!temp->left)
        {
            temp->left = newNode(key);
            break;
        }
        else
            q.push(temp->left);
        if(!temp->right)
        {
            temp->right = newNode(key);
            break;
        }
        else
            q.push(temp->right);
    }
    
}
int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(11);
    root->left->left = newNode(15);
    root->right->left = newNode(7);
    root->left->right = newNode(14);
    root->right->right = newNode(25);
    cout<<"Inorder traversal :\n";
    Inorder(root);
    insert(root,24);
    insert(root,6);
    insert(root,13);
    cout<<"\n After insertion :\n";
    Inorder(root);
    return 0;	
}
