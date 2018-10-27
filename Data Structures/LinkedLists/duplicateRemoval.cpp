#include<bits/stdc++.h>
#include <map>
using namespace std;

unordered_set<int> dup;
std::map<int, int> map1;

typedef struct Node{
  int data;
  struct Node *next;
}node;

node * head = NULL;


void printlist(struct Node * head){
  struct Node * temp = head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}

struct Node* createNode(int data){
  struct Node * temp = new Node;
  temp->data = data;
  temp->next = NULL;
  return temp;
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

void duplicate(node * head){
	node * temp = head, * temp1 = NULL;
	while(temp != NULL){
		if(dup.find(temp->data) != dup.end()){
			temp1 -> next = temp ->next;
		}
		else{
			 dup.insert(temp -> data);
			 temp1 = temp;
		}
		temp = temp1 -> next;
	}
	cout<<"After Removal Of duplicates : ";
	printlist(head);
 } 

void duplicate1(node * head){
	node * temp = head, * temp1 = NULL;
	while(temp != NULL){
		map1[temp->data]++;
		if(map1[temp->data] == 1){
			temp1 =  temp;
		}
		else if(map1[temp -> data] > 1){
			temp1 -> next = temp ->next;
		}
		temp = temp1->next;
	}
	cout<<"After Removal Of duplicates : ";
	printlist(head);
}

int main(){
  int t,n;
  cin>>t;
  CreateList(t);
  cout<<"Real List : ";
  printlist(head);
  duplicate(head);
  return 0;
}
