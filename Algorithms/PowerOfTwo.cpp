#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin>>n;
	  if ((n > 0) && (n & (n - 1)) == 0) 
    {
      cout<<n<<" is power of two"<<"\n";
	  }
    else
	  {
      cout<<n<<" is NOT a power of two"<<"\n";
	  }
  return 0;
}
