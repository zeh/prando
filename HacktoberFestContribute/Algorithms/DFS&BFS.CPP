#include<iostream.h>
#include<string.h>
#include<conio.h>
class BST
{
struct Node
{
  int Data;
  Node *Left,*Right;
  Node(){ Left=Right=NULL; }
} *Root;
public:
BST(){Root=NULL;}
void Create();
void  Insert(int); //Binary Search Tree Creation
int Search(int);//Non Recursive Search
int Rsearch(int); //Recursive Search
void DFS();//Depth First Search (Display)
void BFS();//Breath First Search Non Recursive(Levelwise Display)
	   //Count Number of Node,No of Leaf Node & Height of the Tree
void mirror(); //Display mirror image
void mirror_BFS(); //Find mirror image
void Dsearch(int); //Delete Node
};
//create tree
void BST::Create()
{
  int Num;
  char ans;
  do
   {

	cout<<"Enter Number";
	cin>>Num;
	Insert(Num);
	//RDFS();
	getch();
	cout<<"\nAdd More...(Y/N)";
	cin>>ans;
   }while(ans=='y' || ans=='Y');
}
//Binary Search Tree Creation
void BST::Insert(int Num)
{
   Node *nNode,*Temp;
   nNode=new Node;
   nNode->Data=Num;
   if(Root==NULL)
      Root=nNode;
   else
     {
      Temp=Root;
      while(1)
	  {
	    if(nNode->Data>Temp->Data)
	     {
	       if(Temp->Right==NULL)
		{Temp->Right=nNode;break;}
	       else Temp=Temp->Right;
	     }
	    else if(nNode->Data<Temp->Data)
	     {
	       if(Temp->Left==NULL)
		{Temp->Left=nNode;break;}
	       else Temp=Temp->Left;
	      }
	     else { cout<<"\nNumber already present";break;}
	 }//while
    }
}
//Non Recursive Search
int BST::Search(int Num)
{
Node *Tree=Root;
  while(Tree!=NULL)
      {
	if(Num>Tree->Data)
	 Tree=Tree->Right;
	else if(Num<Tree->Data)
	      Tree=Tree->Left;
	     else return 1;
       }
return 0;
}
//Recursive Search
int BST::Rsearch(int Num)
{
static int Flag=0;
static Node *Tree=Root;
if(Tree!=NULL)
 {
  if(Num>Tree->Data)
    { Tree=Tree->Right;Rsearch(Num);}
  else if(Num<Tree->Data)
	{ Tree=Tree->Left; Rsearch(Num);}
       else
	   Flag=1;
   }
return Flag;
}
//Depth First Search Non Recursive
void BST::DFS() //Display
{
Node *Stack[20],*Tree=Root;
int Top=0;
do
{
 cout<<Tree->Data;
 if(Tree->Right!=NULL)
   Stack[Top++]=Tree->Right;
 Tree=Tree->Left;
 if(Tree==NULL)
   Tree=Stack[--Top];
}while(Top>=0);
}
//Breath First Search Non Recursive(Levelwise Display)
//Count Number of Node,No of Leaf Node & Height of the Tree
void BST::BFS()
{
Node *Queue[20],*Temp=Root;
int Front=0,Rear=1,Level=-1;
if(Temp==NULL)
cout<<"\nEmpty Tree";
else
{
Queue[0]=Temp;
Queue[1]=NULL;
cout<<"\nLevel "<<++Level;
do
 {
  Temp=Queue[Front++];
  if(Temp==NULL)
   {
    Queue[++Rear]=NULL;
    cout<<"\nLevel "<<++Level;
   }

  else
   {
     cout<<" "<<Temp->Data<<" ";
     if(Temp->Left!=NULL)
      Queue[++Rear]=Temp->Left;
     if(Temp->Right!=NULL)
      Queue[++Rear]=Temp->Right;
    }
 }while(Front<Rear);
}
}

//Display Mirror image
void BST::mirror()
{
Node *Queue[20],*Temp;
int Front=0,Rear=1;
Queue[0]=Root;
Queue[1]= NULL;
while(Front<Rear)
 {
  Temp=Queue[Front++];
  if(Temp==NULL)
   {
    cout<<endl;
    Queue[++Rear]=NULL;
   }
  else
   {
     cout<<Temp->Data;
     if(Temp->Right!=NULL)
      Queue[++Rear]=Temp->Right;
     if(Temp->Left!=NULL)
      Queue[++Rear]=Temp->Left;
    }
 }
}

//Find Mirror Image
void BST::mirror_BFS()
{
Node *Queue[20],*Temp,*Temp1;
int Front=0,Rear=1;
Queue[0]=Root;
do
 {
    Temp=Queue[Front++];
    Temp1=Temp->Left;
    Temp->Left=Temp->Right;
    Temp->Right=Temp1;
    if(Temp->Left!=NULL)
     Queue[Rear++]=Temp->Left;
    if(Temp->Right!=NULL)
     Queue[Rear++]=Temp->Right;
 }while(Front<Rear);
}

//Delete Node
void BST::Dsearch(int Num)
{
Node *Stack[10],*pTemp=Root,*Temp=Root,*RTemp,*pRTemp;
char Flag;
while(Temp->Data!=Num &&Temp!=NULL)
   {
      if(Num>Temp->Data)
       {
	 pTemp=Temp;
	 Flag='R';
	 Temp=Temp->Right;
       }
      else
       {
	 pTemp=Temp;
	 Flag='L';
	 Temp=Temp->Left;
	}
    }//while
if(Temp!=NULL)
{
 if(Temp->Left==NULL && Temp->Right==NULL)
  {
   if(Root==Temp) Root=NULL;
   if(Flag=='R') pTemp->Right=NULL;
   else pTemp->Left=NULL;
  }


 else // delete Node with Left and Right children
  if(Temp->Left!=NULL && Temp->Right!=NULL)
   {
     pRTemp=RTemp=Temp->Right;
     while(RTemp->Left!=NULL)
      {
	pRTemp=RTemp;
	RTemp=RTemp->Left;
      }
    pRTemp->Left=RTemp->Right;
    if(Temp==Root)
	Root=RTemp;
   else if(Flag=='L') pTemp->Left=RTemp;
   else if(Flag=='R') pTemp->Right=RTemp;
   RTemp->Left=Temp->Left;
   if(RTemp!=pRTemp)
    RTemp->Right=Temp->Right;
   } //if
  else
	if(Temp->Right!=NULL)//with Right child
	{
	   if(Root==Temp)  Root=Root->Right;
	   else if(Flag=='L') pTemp->Left=Temp->Right;
	   else pTemp->Right=Temp->Right;
	}
       else if(Temp->Left!=NULL) //with Left child
	     {
	       if(Root==Temp) Root=Root->Left;
	       else if(Flag=='L') pTemp->Left=Temp->Left;
	       else pTemp->Right=Temp->Left;
	     }
 delete Temp;
}
else
 cout<<"\nNode is not present";

}//Function end


/********** Main  ********/
void main()
{
  BST B;
  int n;
  B.Create();
  B.BFS();
  B.mirror_BFS();
  B.BFS();
getch();
}



