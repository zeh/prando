#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void push(Node **head_ref, int new_data)
{
    Node* new_node = new Node;
    new_node->data = new_data;
    if(*head_ref == NULL)
    {
        new_node->next = new_node;
        (*head_ref) = new_node;
        return;
    }
    Node* last = *head_ref;
    while(last->next != *head_ref)
    last= last->next;
    new_node->next = (*head_ref);
    last->next = new_node;
    (*head_ref) = new_node;
}
void printList(Node *head_ref)
{
    Node* temp = head_ref;
    if (head_ref != NULL) 
    {
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        while (temp != head_ref);
    }
}
int main() {
	Node* head = NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	printList(head);
	return 0;
}
