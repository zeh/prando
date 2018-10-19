#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;


class queue1
{

public:

struct node
{
int value;
int flag;
struct node *next;

};

struct node *rear=NULL,*frnt=NULL;


  void enqueue();
  void dequeue();
  void display();
  void check()
  {
      int flag1=0;

      struct node *ptr1=frnt;
      struct node *ptr2=frnt->next;


      while(ptr2!=NULL)
      {

          if(ptr1==ptr2)
          {

              flag1=1;
              break;
          }


            ptr1=ptr1->next;
          ptr2=ptr2->next->next;
      }
if(flag1==0)
  {
      cout<<"NO LOOP"<<endl;

  }
  else
  {
      cout<<"YES LOOP"<<endl;

  }


  }



};
void queue1::enqueue()
{
    cout<<"Enter item"<<endl;
     int item;
 if(rear==NULL)
{

     struct node *temp=new node;
 cin>>item;
 temp->value=item;
 temp->next=NULL;
 temp->flag=0;
 frnt=temp;
 rear=frnt;
}
else
{
    struct node *temp=new node;
cin>>item;
temp->value=item;
temp->flag=0;
rear->next=temp;
rear=temp;
rear->next=frnt;
}
}
void queue1::dequeue()
{
    if(frnt==NULL)
    {
        cout<<"LINK LIST EMPTY"<<endl;

    }
    else if(frnt==rear)
    {

        int item=frnt->value;
           free(frnt);
           free(rear);
           frnt=NULL;
           rear=NULL;

    }
else
{
struct node *temp=frnt;
frnt=frnt->next;
int item=temp->value;
temp->next=NULL;
    free(temp);
rear->next=frnt;

}

}
void queue1::display()
{
   struct node *temp=frnt;
   cout<<temp->value<<" ";
   temp=temp->next;

   while(temp!=frnt)
   {

       cout<<temp->value<<" ";
       temp=temp->next;
   }
}


int main()
{

    queue1 q;
    int ch;

    while(1)
    {

        cout<<"Enter 1 to enter element in circular queue"<<endl;
        cout<<"Enter 2 to delete an element in circular queue"<<endl;
        cout<<"Enter 3 to display circular queue"<<endl;
        cout<<"Enter 4 to check whether cycle exist in link list or not"<<endl;
        cout<<"Enter 5 to exit"<<endl;


           cin>>ch;

           switch(ch)
           {
           case 1:
               q.enqueue();


            break;
           case 2:
               q.dequeue();
            break;
           case 3:
               q.display();
            break;
           case 4:
               q.check();
            break;
            case 5:
                exit(0);
                break;

}

    }


}
