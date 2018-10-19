# include<bits/stdc++.h>
using namespace std;
int main()
{
 int r;//No of test cases
 cin>>r;
 while(r--){

  int t;
  cin>>t;
  while(t%2==0)
  {
      t=t/2;
  }
  if(t==1){
     cout<<"Power of Two"<<endl;
  }
  else{
      cout<<"Not a power of two"<<endl;
  }
 }
} 
