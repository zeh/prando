#include<iostream>
#include<string>

using namespace std;

struct node
{
    string name;
    int count;
    node *left,*right;
};

class BST
 {
   //private:
	  // node* root;
   public:
	  int maximum(int a,int b);
          node* createnode(string key,int Tcount);
	  node* insert(node *root,string key,int Tcount);
	  int search(string key,node *temp);
	  node* locate(string key,node *temp);
	  int height(node *temp);
	  int depth(string key,node *temp);
	  node* deletekey(string key,node *temp);
	  node* findmin(node *temp);
	  node* parent(string name1,node *temp);
	  string label(node *temp);
	  string mostpopular(node *root);
	  void inorder(node *temp);
	  void printnodes(string name1,string name2,node* root);
 };
