#include<iostream>
#include<string>
#include "BST.h"

using namespace std;

int BST::maximum(int a,int b)
{
    	if(a>b)
      		return a;
    	else
      		return b;
}

node* BST::createnode(string key,int Tcount)
{
    	node *temp=new node;
    	temp->name=key;
    	temp->count=Tcount;
    	temp->left=temp->right=NULL;
   	return temp;
}

node* BST::insert(node *temp,string key,int Tcount)
{
   	node *temp1=new node;
    	temp1=temp;
    	if(temp1==NULL)
      		return(createnode(key,Tcount));
    	if(key<(temp1->name))
      		temp1->left=insert(temp1->left,key,Tcount);
    	else if(key>(temp->name))
      		temp1->right=insert(temp1->right,key,Tcount);
    	else 
      		temp1->count=temp1->count+Tcount;
   	return temp1;
}

int BST::search(string key,node* temp)
{
   	if(temp==NULL){
     		return 0;
    	}
   	else if(key<(temp->name))
     		return search(key,temp->left);
   	else if(key>(temp->name))
     		return search(key,temp->right);
   	else if(key==(temp->name)){
     		return temp->count;
   	}
}

node* BST::locate(string key,node* root)
{
   	if(root==NULL)
     		return root;
   	else if(key==(root->name))
     		return root;
   	else if(key<(root->name))
     		return locate(key,root->left);
   	else if(key>(root->name))
     		return locate(key,root->right);
}

int BST::height(node* root) 
{
   	if(root==NULL)
     		return 0;
   	else
     		return (1+maximum(height(root->left),height(root->right)));
}
 
int BST::depth(string key,node* root)
{
    	if(root==NULL)
      		return 0;
    	else if(key==(root->name))
      		return 0;
    	else if(key<(root->name))
      		return 1+depth(key,root->left);
    	else if(key>(root->name))
      		return 1+depth(key,root->right);
}

node* BST::findmin(node *temp){
	//node *temp1=new node;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}

/*node* BST::parent(string name1,node* temp){
	if(name1==temp->left->name){
		return temp;
	}
	else if(name1==temp->right->name){
		return temp;
	}
	else if(name1<temp->name){
		return parent(name1,temp->left);
	}
	else if(name1>temp->name){
		return parent(name1,temp->right);
	}

}*/

node* BST::deletekey(string name,node *root)
{
        if(root == NULL)
              return root;
        else if(name < root->name)
              root->left = deletekey(name,root->left);
        else if (name > root->name)
              root->right = deletekey(name,root->right);  
        else
        {
        	if(root->left == NULL && root->right == NULL)
                {
                	delete root;
            		root = NULL;
         	}
        	else if(root->left == NULL)
                {
             		node *temp = root;
             		root = root->right;
             		delete temp;
          	}
        	else if(root->right == NULL)
                {
             		node *temp = root;
             		root = root->left;
             		delete temp;
          	}
        	else
                {
             		node *temp = findmin(root->right);
             		root->name = temp->name;
             		root->right = deletekey(temp->name,root->right);
          	}
        }
        return root;
}


string BST::label(node* temp)
{
    	if(temp==NULL)
      		return "Node doesnot exist";
    	else
      		return temp->name;
}

string BST::mostpopular(node* root)
{
    	string mp="",l,r,max,empty;
	int a,b,c;
    	if(root==NULL)
      		return mp;
    	else 
      		mp=root->name;
    	l=mostpopular(root->left);
    	r=mostpopular(root->right);
	empty="";
    
    	node *temp1=locate(l,root);
    	node *temp2=locate(r,root);
    	a=temp1->count;
    	b=temp2->count;

    	if(l==empty&&r==empty)
       		max=empty;
    	else if(l==empty&&r!=empty)
       		max=r;
    	else if(l!=empty&&r==empty)
       		max=l;
    	else if(a<b)
        	max=r;
    	else
        	max=l;
    
    	node *temp3=locate(max,root);
    	c=(temp3->count);
    	//cout<<c<<endl;
    	if(max==empty)
        	return mp;
    	else if((root->count)<c)
       	{
         	cout<<root->count<<endl;
          	return max;
       	}
    	else 
       		return mp;
}

void BST::inorder(node* root)
 {
   	if (root!=NULL){
  		inorder(root->left);
  		cout<<root->name<<" ";
  		inorder(root->right);
	}  
}

void BST::printnodes(string name1,string name2,struct node* root)                
  {
    if(root==NULL)
      	return;
    else if(root->name<name1)
      	printnodes(name1,name2,root->right);
    else if(root->name>name2)
      	printnodes(name1,name2,root->left);
    else
      {
         printnodes(name1,name2,root->left);
	 cout<<root->name<<" ";
	 printnodes(name1,name2,root->right);
     }
  }

