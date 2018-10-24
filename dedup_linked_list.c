#include <stdio.h>
#include <stdlib.h>

// define struct recursively
typedef struct node {
  int val;
  struct node* next;
} node_t;

// iterating over a list
void print_list(node_t*head) {

  // current pointer keeps track of the node currently being printed
  node_t* current = head;

  // print until the next node is NULL
  while(current != NULL) {

    printf("%d\n", current->val);
    current = current->next; // set current pointer to the next node
  }
}

// adding an item to the end of the list
void add(node_t* head, int val) {

  // set current to the start
  node_t* current = head;

  // continuously advance pointer to the next item 
  while(current->next != NULL) {
    current = current->next;
  }

  // add new variable to list
  current->next = malloc(sizeof(node_t));
  current->next->val = val;
  current->next->next = NULL;
}

// adding an item to the beginning of the list (pushing to the list)

// Pass a pointer to the pointer variable (a double pointer) to modify the
// pointer itself
void push(node_t** head, int val) {

  // create variable for new head 
  node_t* new_node;
  new_node = malloc(sizeof(node_t));

  // set value for new item
  new_node->val = val;
  // link the new item to point to the head of the list
  new_node->next = *head;
  // set the head of the list to be the new item
  *head = new_node;
}

// removing the first item from the list(popping from the list)
int pop(node_t** head) {

  int retval = -1;
  node_t* next_node = NULL;

  if(*head == NULL)
    return -1;
  
  // save item that head currently points to
  next_node = (*head)->next;
  retval = (*head)->val;
  // free the head item 
  free(*head);
  // set the head item to be previously saved item
  *head = next_node;

  return retval;
}

// removing the last item from the list
int remove_last(node_t* head) {
  int retval = 0;
  // remove item for single item list
  if(head->next == NULL) {
    retval = head->val;
    free(head);
    return retval;
  }

  // get penultimate (next to the last) node in list
  // look two items ahead to confirm if it is the last
  node_t* current = head;
  while(current->next->next != NULL) {
    current = current->next;
  }

  // now current points to the penultimate item & current->next can be removed
  retval = current->next->val;
  free(current->next);
  current->next = NULL;
  
  return retval;
}

// removing a specific item 
int remove_by_index(node_t** head, int n) {
  
  int retval = -1;
  node_t* current = *head;
  node_t* temp_node = NULL;

  if(n == 0)
    return pop(head);

  // iterate to the node before the specified item
  for(int i = 0; i < n - 1; ++i) {
    if(current->next == NULL) {
      return -1;
    }
    current = current->next;
  }
  // save the node to be deleted in temp pointer
  temp_node = current->next;
  retval = temp_node->val;
  // set previous node's next pointer to point to the node after the node to be
  // deleted
  current->next = temp_node->next;
  // delete the node using the temporary pointer
  free(temp_node);

  return retval;

}

void remove_duplicate(node_t* head) {

  node_t* node;
  node_t* other;
  node_t* dup;

  while(node!= NULL && node->next != NULL) {
    other = node;

    // compare item with all values
    while(other->next != NULL) {
      // free node if duplicate
      if(node->val == other->next->val) {
        dup = other->next;
        other->next = other->next->next;
        free(dup);
      }
      else
        other = other->next;
    }
    node = node->next;
  }
}

int main(void) {

  // head points to the first item of the list
  node_t* head = NULL;
  head = malloc(sizeof(node_t));
  // check weather malloc returned a NULL value or not
  if(head == NULL)
    return 1;

  head->val = 1;     // set the value of the first item
  head->next = NULL; // set the next item to be empty

  // test add function: which adds to the end of the list
  add(head, 2);

  // test push function
  push(&head, 3);

  // add duplicate value deliberately
  add(head, 3);

  // test print function
  print_list(head);

  // test remove_duplicate
  remove_duplicate(head);
  printf("\nLinked list after removing duplicate values\n");
  print_list(head);

  return 0;
}
