#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};

// A utility function to create a new node 
ListNode *newNode(int key) 
{ 
    ListNode *temp = new ListNode; 
    temp->val = key; 
    temp->next = NULL; 
    return temp; 
} 

//function to reverse the linked list. 
void reverseList(ListNode **A) {
    
    ListNode *current, *next, *prev;
    current = *A;
    prev = NULL;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *A = prev;
    //return A;
}

// A utility function to print a linked list 
void printlist(ListNode *head) 
{ 
    while(head != NULL) 
    { 
        cout << head->val << " "; 
        head = head->next; 
    } 
    cout << endl; 
}

// Driver program to test above functions 
int main() 
{ 
    ListNode *head1 = newNode(1); 
    head1->next = newNode(2);
    head1->next->next = newNode(3); 
    head1->next->next->next = newNode(4); 
    head1->next->next->next->next = newNode(5); 
    head1->next->next->next->next->next = newNode(6); 
    head1->next->next->next->next->next->next = newNode(7); 
    head1->next->next->next->next->next->next->next = newNode(8); 
    
    cout << "Given linked list\n"; 
    printlist(head1); 
    
    reverseList(&head1); 
    
    cout << "\nReversed linked list\n"; 
    printlist(head1); 
    
    return 0; 
}
