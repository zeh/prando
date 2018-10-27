// palindrome2
#include <iostream>
using namespace std;

typedef struct StackNode
{
	int data;
	struct StackNode * next;	
}Snode;

Snode * root = NULL;

Snode * newNode(int data){
	Snode * snode = new Snode;
	snode->data = data;
	snode->next = NULL;
	return snode;
}


int isEmpty(Snode * root){
	return !root;
}

Snode * push(int data){
	Snode * node = newNode(data);
	node->next = root;
	root = node;
	cout<<data<<" Pushed To stack\n";
	return root;
}

int pop(){
	if(isEmpty(root))
		return -1;
	Snode * temp = root;
	root = root->next;
	int popped = temp->data;
	cout<<popped<<"Value Popped Out"<<endl;
	delete temp;
	return popped;
}

int peak(Snode * root){
	if(isEmpty(root))
		return -1;
	else
		return root->data;
}

void printStack(Snode * root){
	Snode * temp = root;
	cout<<endl;
	cout<<"YOUR STACK : ";
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

typedef struct Node{
  int data;
  struct Node *next;
}node;

struct Node * head = NULL;


struct Node* createNode(int data){
  struct Node * temp = new Node;
  temp->data = data;
  temp->next = NULL;
  return temp;
}

void printlist(struct Node * head){
  struct Node * temp = head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}

struct Node * CreateList(int n){
  struct Node * temp;
  struct Node * p = NULL;
  int data;
  for(int i=0;i<n;i++){
  cin>>data;
  temp = createNode(data);
  if(head == NULL){
    head = temp;
  }
  else{
    p = head;
    while(p->next != NULL){
      p = p->next;
    }
    p->next = temp;
  }
}
 return head;
}

void palindrome( Snode * root){

	bool t = true;
	node * temp = head;
	node * temp1 = head;
	while(temp1 != NULL && temp1 -> next != NULL){
		push(temp->data);
		temp = temp ->next;
		temp1 = temp1 -> next ->next;
	}
	if(temp1 != NULL){
		temp = temp -> next;
	}
	while(temp != NULL){
		int k = pop();
		if(k != temp -> data){
			t = false;
		}
		temp = temp -> next;
	}
	if(t == false){
		cout<<"List is not palindrome"<<endl;
	}
	else
		cout<<"List is palindrome"<<endl;
}


int main(){
  int t,n;
  cin>>t;
  CreateList(t);
  cout<<"Real list :";
  printlist(head);
  palindrome(root);
  return 0;
}
