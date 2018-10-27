#include<iostream>
using namespace std;

struct Node 
{ 
int data; 
struct Node* next; 
}; 
  
/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct Node* head, int n) 
{ 
    int len = 0, i; 
    struct Node *temp = head; 
  
    // 1) count the number of nodes in Linked List 
    while (temp != NULL) 
    { 
        temp = temp->next; 
        len++; 
    } 
  
    // check if value of n is not more than length of the linked list 
    if (len < n) 
    return; 
  
    temp = head; 
  
    // 2) get the (len-n+1)th node from the begining 
    for (i = 1; i < len-n+1; i++) 
    temp = temp->next; 
  
    printf ("%d", temp->data); 
  
    return; 
} 
  
void push(struct Node** head_ref, int new_data) 
{ 
/* allocate node */
struct Node* new_node = new Node;
       
  
/* put in the data */
new_node->data = new_data; 
  
/* link the old list off the new node */
new_node->next = (*head_ref); 
  
/* move the head to point to the new node */
(*head_ref) = new_node; 
} 
  
/* Drier program to test above function*/
int main() 
{ 
/* Start with the empty list */
struct Node* head = NULL; 
  
int n,t;
    cout<<"enter no. of elements to enter\n";
    cin>>n;
    cout<<"enter elements\n";
    for(int i=0;i<n;i++)
    {
    	
    	cin>>t;
    	push(&head, t);
	}
cout<<"enter n\n"; 
  cin>>t;
printNthFromLast(head, t%n); 
return 0;  
} 

