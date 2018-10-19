//My Hackerrank solution.(just the algorithm here)



struct Node {
        int data;
        struct Node* next;
    }

int has_cycle(Node* head) {
    
if(head==NULL){
    return 0;
}
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return 1;
        }
    
    }
  
    return 0;
}


/* Explanation 

We first initialize two pointers, slow and fast and make them point to head node of list.
Slow pointer moves by one node at a time and fast pointer moves by two nodes at a time, meaning slow pointer points to next node, while fast pointer points to next to next node.
If at some point, slow and fast pointer point to same node, then a loop is present in linked list.


1---2---3---4-----5
                /  \                
               9    6
                \   /
                 8-7


Let slow pointer ='S' and fast pointer ='F'.

step 1: S,F point to 1.
step 2: S points to 2, F points to 3.
step 3: S points to 3, F points to 5.
step 4: S points to 4, F points to 7.
step 5: S points to 5, F points to 9.
step 6: S points to 6, F points to 6. Loop detected!(as S,F point to same node).









*/
