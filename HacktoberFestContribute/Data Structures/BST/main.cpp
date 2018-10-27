#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<ctime>
#include"BST.h"

using namespace std;


int main(int argc,char* argv[])
{
   BST T;
   int option;
   string name,name1,name2;
   option=atoi(argv[1]);
   if(option==1||option==3||option==4)
     {
	name=argv[2];
     }
   else if(option==5)
	{
	   name1=atoi(argv[2]);
	   name2=atoi(argv[3]);
	}
   int year,Tcount,Mcount,Fcount;
   string key;
   struct node *temp;
   struct node *root;
   root=NULL;
   ifstream f;
   f.open("input1.txt");
   while(f>>year){
	f>>Tcount;
	f>>Mcount;
	f>>Fcount;
	f>>key;
	root=T.insert(root,key,Tcount);
   }
	temp=root;
   if(option==1){
	cout<<T.search(name,root)<<endl;}
   else if(option==2)
	cout<<T.height(root)-1<<endl;
   else if(option==3)
	cout<<T.depth(name,root)<<endl;
   else if(option==4){
	T.deletekey(name,root);
	cout<<T.search(name,root)<<endl;}
   else if(option==5){
	T.printnodes(name1,name2,root);                                      
        cout<<endl;
   }
   else if(option==6)
	cout<<T.mostpopular(root)<<endl;
   else
	cout<<"Not a valid option"<<endl;
 return 0;
}
