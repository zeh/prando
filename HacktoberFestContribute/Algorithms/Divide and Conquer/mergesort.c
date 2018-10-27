#include<stdio.h>
#define Max 10
int a[Max] , n;
void merge(int a[], int low , int mid , int high)
{
   int temp[n];
   int l=low , m = mid+1 , k=0 , i;
   while((l<=mid) && (m<=high))
   {
      if(a[l]<a[m])
      {
        temp[k]=a[l];
        k++;
        l++;
      }
      else
      {
        temp[k]=a[m];
        k++;
        m++;
      }
     
   }
  
  if(l>mid)
  { while(m<=high)
    {
      temp[k]=a[m];
        m++;
        k++;
    }
  } 
  if(m>high) 
  { while(l<=mid)
    {
      temp[k]=a[l];
        l++;
        k++;
    }
  }

   for(i=low,k=0;i<=high;i++,k++)
   { a[i]=temp[k];
   }

}

void sort(int a[], int low , int high)
{ int mid;
  if(low<high)
   {
    mid=(low+high)/2;
    sort(a,low,mid);
    sort(a,mid+1,high);
    merge(a,low,mid,high);
   }
   
}

void main()
{  int i;
   printf("enter no. of elements:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
  {
    printf("Enter element\n");
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
     
  }
  printf("\n"); 
  
  //Merge Sort
  sort(a,0,n-1);
  printf("After sort\n");
 for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
     
  }
  

}
