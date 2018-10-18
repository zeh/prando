import java.util.*;
class Nqueens{
  int n=4,a[][]=new int[n][n],b[]=new int[n+1];
  public static void main(String args[]){
    Nqueens m=new Nqueens();
    m.queen(0);
  }
  void queen(int i)
  {
    for(int j=1;j<n+1;j++)
    {
       if(kill(i,j)==0)
       {
         b[i]=j;
         if(i==n)
         {
           print();
         }
         else
         queen(i+1);
       }
    }
  }
  void print()
  {
    for(int q=1;q<=n;q++)
     System.out.print(b[q]);
     System.out.println();
  }
  int kill(int i,int j)
  {
    int p=0;
    for(int k=1;k<i;k++)
      if(j==b[k] || Math.abs(b[k]-j)==Math.abs(k-i))
      {
        p=1;
        break;
      }
    return p;
  }
}
