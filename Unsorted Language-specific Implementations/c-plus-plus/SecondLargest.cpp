# include<bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin>>t; // For no:of test cases
   while(t--){
   int n;
   cin>>n;
   int a[n], l=0, s=0;
   for(int i=0; i<n; i++) {
      cin>>a[i];  //array elements
   }

   if(a[0]<a[1]){
      l = a[1];
      s = a[0];
   }
   else{
      l = a[0];
      s = a[1];
   }
   for (int i = 2; i< n ; i ++) {

      if (a[i] > l) {
         s = l;
         l = a[i];
      }

      else if (a[i] > s && a[i] != l) {
         s = a[i];
      }
   }
   cout<<s<<endl;//Second Largest element
   }
   return 0;
}
