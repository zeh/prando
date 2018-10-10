// for more info refer http://www.techiedelight.com/spiral-order-traversal-binary-tree/

// code for spiral order tree traversal 
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

// traverse the tree in pre-order fashion and store nodes into the map
// corresponding to their level
void preorder(Node *root, int level, auto &map)
{
    // base case: empty tree
    if (root == nullptr)
        return;

    // insert current node and its level into the map

    // if level is odd insert at back, else insert at front
    if (level & 1)
        map[level].push_back(root->key);
    else
        map[level].push_front(root->key);

    // recurse for left and right subtree by increasing level by 1
    preorder(root->left, level + 1, map);
    preorder(root->right, level + 1, map);
}

// Recursive function to print spiral order traversal of given binary tree
void levelOrderTraversal(Node *root)
{
    // create an empty map to store nodes between given levels
    map<int, list<int>> map;

    // traverse the tree and insert its nodes into the map
    // corresponding to the their level
    preorder(root, 1, map);

    // iterate through the map and print all nodes present in very level
    for (auto it: map)
    {
        cout << "Level " << it.first << ": ";
        for (int i: it.second)
            cout << i << " ";

        cout << endl;
    }
}

// main function
int main()
{
    Node* root = nullptr;
    vector<pair<string, int> > keys =
    {
        {"", 15}, {"L", 10}, {"R", 20}, {"LL", 8},
        {"LR", 12}, {"RL", 16}, {"RR", 25}, {"LLL", 20}, {"RRR", 30}
    };

    for (auto pair: keys)
        insert(root, pair.first, pair.second);

    levelOrderTraversal(root);

    return 0;
}
