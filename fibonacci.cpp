#include<iostream.h>
#include<conio.h>
void fibonacci(int p,int q,int r)
{
  int a,b,c;
  a=0;
  b=1;
  cout<<"number of terms of fibanocci terms are to be printed: "<<endl;
  cin>>n>>endl;
  for(i=0;i<n;i++)
  {
    c=a+b;
    b=c;
    a=b;
    cout<<c;
  }
}
int main()
{
 int p,q,r;
 fibonacci(p,q,r);
 return 0;
}
