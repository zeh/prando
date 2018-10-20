//spiral order traversal of a binary tree




#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int key;
    Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = nullptr;

    return node;
}

// Function to insert given key into the tree
void insert(Node*& root, string level, int key)
{
    // tree is empty
    if (level.length() == 0)
    {
        root = newNode(key);
        return;
    }

    int i = 0;
    Node* ptr = root;
    while (i < level.length() - 1)
    {
        if (level[i++] == 'L')
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if (level[i] == 'L')
        ptr->left = newNode(key);
    else
        ptr->right = newNode(key);
}

// Function to print all nodes of a given level from left to right
bool printLevelLeftToRight(Node* root, int level)
{
    if (root == nullptr)
        return false;

    if (level == 1)
    {
        cout << root->key << " ";
        return true;
    }

    // process left child before right child
    bool left = printLevelLeftToRight(root->left, level - 1);
    bool right = printLevelLeftToRight(root->right, level - 1);

    return left || right;
}

// Function to print all nodes of a given level from right to left
bool printLevelRightToLeft(Node* root, int level)
{
    if (root == nullptr)
        return false;

    if (level == 1)
    {
        cout << root->key << " ";
        return true;
    }

    // process right child before left child
    bool right = printLevelRightToLeft(root->right, level - 1);
    bool left = printLevelRightToLeft(root->left, level - 1);

    return right || left;
}

// Function to print level order traversal of given binary tree
void spiralOrderTraversal(Node* root)
{
    if (root == nullptr)
        return;

    // start from level 1 -- till height of the tree
    int level = 1;

    // run till either function returns false
    while (printLevelLeftToRight(root, level++) &&
           printLevelRightToLeft(root, level++));
}

// main function
int main()
{
    Node* root = nullptr;
    vector<pair<string, int> > keys =
    {
        {"", 15}, {"L", 10}, {"R", 20}, {"LL", 8},
        {"LR", 12}, {"RL", 16}, {"RR", 25}
    };

    for (auto pair: keys)
        insert(root, pair.first, pair.second);

    spiralOrderTraversal(root);

    return 0;
}
