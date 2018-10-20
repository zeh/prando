#include<iostream>
using namespace std;

typedef struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
}node;

struct Node * head;

struct Node * createNode(int data){
  struct Node * temp = new Node;
  temp->data = data;
  temp->next = NULL;
  temp ->prev = NULL;
  return temp;
}

void printList(node * head){
  node * temp = head;
  while(temp != NULL){
    cout<<temp->data<<"-> ";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}

void * CreateList(int data){
  node * temp = createNode(data);
  if (head==NULL)
    head = temp;
  else{
    node * p = head;
    while(p -> next != NULL){
      p = p -> next;
    }
    p ->next = temp;
    temp -> prev = p;
  }
}


int main(){
  int n,m;
  cin>>n;
  while (n >= 0) {
    cin>>m;
    CreateList(m);
    n--;
  }
  cout<<"Normal List : ";
  printList(head);
  return 0;
}
