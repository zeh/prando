#include<bits/stdc++.h>
using namespace std;

struct node{
	long val;
	node *link;
};
void insert(node **list,long n,node **last)
{
	node *temp;
	temp=new node;
	temp->val=n;
	temp->link=NULL;
	if((*last)==NULL){
		(*last)=temp;
		*list=*last;
	}
	else{
		(*last)->link=temp;
		(*last)=temp;
	}
}
int main()
{
	node *list,*mid,*last,*prev;
	list=mid=prev=last=NULL;
	long count=0;
	long n;
	while(scanf("%ld",&n))
	{
		if(n==0){
			count=0;
			list=last=mid=prev=NULL;
		}
		else if(n!=-1)
		{	
			count++;
			insert(&list,n,&last);
			if(count%2==1){
				prev=mid;
				if(mid==NULL){
					prev=list;
					mid=list;
				}
				else
					mid=mid->link;
			}
		}
		else
		{
			printf("%d\n",mid->val);
			prev->link=mid->link;
			if(count%2==1)
				mid=prev;
			else
				mid=mid->link;
			count--;
			if(count==0)
			list=last=mid=prev=NULL;
			}
	}return 0;
}