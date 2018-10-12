//Problem Statement:
//Given a Binary Tree and a Level. The task is to find the node with the maximum value at that given level.

#include <iostream> 
  
using namespace std; 
struct Node { 
    int data; 
    struct Node *left, *right; 
};
struct Node* newNode(int val) { 
    struct Node* temp = new Node; 
    temp->left = NULL; 
    temp->right = NULL; 
    temp->data = val; 
    return temp; 
} 
int maxAtLevel(struct Node* root, int level) { 
    if (root == NULL) 
        return 0; 
    if (level == 0) 
        return root->data; 
  
    int x = maxAtLevel(root->left, level - 1); 
    int y = maxAtLevel(root->right, level - 1); 
    return max(x, y); 
}  
int main() {
    struct Node* root = NULL; 
    root = newNode(45); 
    root->left = newNode(46); 
    root->left->left = newNode(18); 
    root->left->left->left = newNode(16); 
    root->left->left->right = newNode(23); 
    root->left->right = newNode(17); 
    root->left->right->left = newNode(24); 
    root->left->right->right = newNode(21); 
    root->right = newNode(15); 
    root->right->left = newNode(22); 
    root->right->left->left = newNode(37); 
    root->right->left->right = newNode(41); 
    root->right->right = newNode(19); 
    root->right->right->left = newNode(49); 
    root->right->right->right = newNode(29); 
  
    int level = 3; 
  
    cout << maxAtLevel(root, level); 
  
    return 0; 
} 