#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void push(Node **head, int new_data)
{
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}
void printList(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int decimal(Node *head)
{
    int sum = 0;
    Node *curr = head;
    while(curr != NULL)
    {
        sum = (sum << 1) + curr->data;
        curr = curr->next;
    }
    return sum;
}
int main() {
	Node *head = NULL;
	push(&head,1);
	push(&head,1);
	push(&head,1);
	push(&head,1);
	printList(head);
	cout<<decimal(head);
	return 0;
}
