#include<stdio.h>
#include<stdlib.h>

int size=0;
int a[128]={0};

void swap(int *i,int *j)
{
   *i=*i+*j;
   *j=*i-*j;
   *i=*i-*j;
}

void ins_adjust()
{
  int i=size;
  int f=(i-1)/2;
  while(i>=0&&a[i]>a[f])
  {
     swap(&a[i],&a[f]);
     i--;
     f=(i-1)/2;
  }
}

int large(int l,int r)
{
  if(a[l]>a[r])
  return l;
  else
  return r;
}

void del_adjust()
{
   int i=0;
   int big,l,r;
   while(i<size/2)
   {
      l=2*i+1;
      r=2*i+2;
      big=large(l,r);
      if(a[i]<a[big])
        swap(&a[i],&a[big]);
      i++;
   }
}

void insert(int k)    //inserts a no. into heap
{
  a[size]=k;
  ins_adjust();       //after insertion, rebuilding the heap
  size++;
}

int delete()          //deletes a no. from heap
{
  int k=a[0];
  a[0]=a[size-1];
  size--;
  del_adjust();       //after deletion, rebuilding the heap
  return k;
}

int main()
{
  int ch,k;
  while(1)
  {
     printf("1.Insert\n");
     printf("2.Delete max\n");
     printf("3.Size\n");
     printf("4.Exit\n");
     printf("Enter your choice\n");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1:printf("Enter a no.\n");
               scanf("%d",&k);
               insert(k);
               break;
        case 2:if(size>0)
                 printf("%d\n",delete());
               else
                 printf("Underflow\n");
               break;
        case 4:return 0;
        case 3:printf("%d\n",size);
               break;
       default:printf("Invalid\n");
               break;
     }
  }
  return 0;
}
