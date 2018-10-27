#include <iostream>
#include <string>

class Node
{
    public:
        int name;
        Node* left = NULL;
        Node* right = NULL;
};

Node* insert(Node* root, int key)
{
    if(root==NULL)
    {
        Node* temp=new Node();
        temp->name=key;
        return temp;
    }
    if (key < root->name)
        root->left  = insert(root->left, key);
    else if (key > root->name)
        root->right = insert(root->right, key);

    return root;
}

int countLeaves(Node* head)
{

    if(head == NULL){
        return 0;
    }
    else if(head->left == NULL && head->right == NULL){
        return 1;
    }
    else {
        return countLeaves(head->left)+countLeaves(head->right);
    }
}

int main()
{
    Node* root=NULL;
    int x;
    int num;
    std::cin >> num;
    for(int i=0;i<num;i++)
    {
         std::cin>>x;

        root=insert(root,x);

    }
    std::cout << countLeaves(root);
}
