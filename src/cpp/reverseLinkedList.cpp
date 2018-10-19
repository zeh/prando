#include<iostream>
using namespace std;

class node{
public:
	node(int data){
		this->data=data;
		next=NULL;
	}
	int data;
	node *next;
};

node* reverse_linked_list(node *head){
	node *prev=NULL,*curr=head;
	while(curr!=NULL){
		node* x=curr->next;
		curr->next=prev;
		prev=curr;
		curr=x;
	}
	return prev;
}

node* insert_in_linkedlist(node *head,int element){
	node *np=new node(element);
	if(head==NULL){
		return np;
	}
	else{
		node *tmp=head;
		while(tmp->next!=NULL)
			tmp=tmp->next;
		tmp->next=np;
		return head;
	}
}

int main(){
	int n;
	cout<<"Enter the number of elements in the linked list: ";
	cin>>n;

	node *head=NULL;
	for(int i=0;i<n;i++){
		int element;
		cout<<"Enter element"<<i+1<<": ";
		cin>>element;
		head=insert_in_linkedlist(head,element);
	}

	node *tmp=head;
	cout<<"Linked List is: ";
	while(tmp!=NULL){
		cout<<tmp->data;
		if(tmp->next!=NULL)
			cout<<" , ";
		tmp=tmp->next;
	}
	cout<<endl;

	// REVERSING THE LINKED LIST
	head=reverse_linked_list(head);

	tmp=head;
	cout<<"Reversed Linked List is: ";
	while(tmp!=NULL){
		cout<<tmp->data;
		if(tmp->next!=NULL)
			cout<<" , ";
		tmp=tmp->next;
	}
	cout<<endl;

}