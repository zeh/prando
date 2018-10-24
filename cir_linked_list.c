#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {

  int data;
  struct node* next;

} node_t;

node_t* head    = NULL;
node_t* current = NULL;

bool empty() {return head == NULL;}

int length() {
  int length = 0;

  //if list is empty
  if(head == NULL)
    return 0;

  current = head->next;

  while(current != head) {
    length++;
    current = current->next;   
  }

  return length;
}

void push(int data) {

  //create a link
  node_t* link = malloc(sizeof(node_t));
  link->data = data;

  if (empty()) {
    head = link;
    head->next = head;
  } else {
    //point it to old first node
    link->next = head;

    //point first to new first node
    head = link;
  }    
}

//delete first item
node_t* pop() {

  //save reference to first link
  node_t* temp = head;

  if(head->next == head) {  
    head = NULL;
    return temp;
  }     

  //mark next to first link as first 
  head = head->next;

  //return the deleted link
  return temp;
}

//display the list
void print() {

  node_t* current= head;
  printf(" [ ");

  //start from the beginning
  if(head != NULL) {

    while(current->next != current) {     
      printf("%d ", current->data);
      current = current->next;
    }
  }

  printf(" ]");
}

int main(void) {

  push(10);
  push(20);
  push(30);
  push(1);
  push(40);
  push(56); 

  printf("Original List: "); 

  //print list
  print();

  while(!empty()) {            
    node_t* temp = pop();
    printf("\nDeleted value:");  
    printf("%d ",temp->data);
  }   

  printf("\nList after deleting all items: ");
  print();   

  return 0;
}
