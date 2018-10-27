#include<iostream>
using namespace std;

class sllnode
{
   public:
    int info;
    sllnode*next;
    sllnode()
      {
	info=0;
	next=NULL;
      }
};
class sll
{
  public:
  sllnode*head;
  sllnode*tail;
  sll()
    {
	head=NULL;
	tail=NULL;
    }
  public:
	void addtotail(int );
	void traverse();
	void visit(int );
	void addtohead(int);
        bool search(int);
};
void sll:: addtohead(int h)
{
	sllnode*n1=new sllnode();
	if(head==NULL)
	  {
	     n1->info=h;
	     head=n1;
	     tail=n1;
	  }
	else
	  {
	    n1->info=h;
	    n1->next=head;
	    head=n1;
	  }


}

void sll:: addtotail(int a)
{
	 sllnode *n1=new sllnode;

	   if(tail==NULL)
	     {
	       n1->info=a;

	       head=n1;
	       tail=n1;
	     }
	   else
	     {
		n1->info=a;
		tail->next=n1;
		tail=n1;
	     }

}
  bool sll:: search( int n)
{
  bool value=false;
  sllnode*temp=head;
  while(temp!=NULL)
   {
	if(temp->info==n)
	 return true;
        else
          temp= temp->next;
   }


        return value;
}
void sll:: traverse()
{
        sllnode*temp=head;
	if(tail==NULL)
	{
	 cout<<"     empty        ";
	}
        else
	{
	 while(temp!=NULL)
	{
	   visit(temp->info);
	    temp=temp->next;
	}
	}

}
void sll::visit(int k)
{
	cout<<k<<"  ";
}
int main()

{
	sll a;
	int choice;
	cout<<"1 for eneter the element to tail "<<endl;
	cout<<"2 to enter element at head"<<endl;
    cout<<"3 to print "<<endl;
	cout<<"4 for search"<<endl;
	cout<<"5 for EXIT"<<endl;
	cin>>choice;
	while(choice!=5)
         {
	  switch(choice)
	    {
		case 1:
			{       int value;
				cout<<"enter  the element to be added to tail"<<endl;
				cin>>value;
				a.addtotail(value);
				break;
			}
		case 2:
			{
				int value;
				cout<<"enter the element to be added to head";
				cin>>value;
				a.addtohead(value);
				break;

			}
		case 3:
			{
				a.traverse();
				break;
			}
		case 4:
			{
				int h;
				cout<<"###  ENTER THE ELEMENT TO BE SEARCHED  ###";
	                        cin>>h;
                                bool check;
			        check=a.search(h);
				if (check==true)
                                   cout<<"element found "<<endl;
                                else
                                   cout<<"not found"<<endl;
					break;
			}

	          }
		cout<<"**************enter your choice again***************";
		cin>>choice;
	}



return 0;
}

