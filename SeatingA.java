
import java.util.Scanner;
class Arrange
{
    public static void main()
    { 
        int t;
        
        
 int a[]={1,2,3,4,5,6,13,14,15,16,17,18,25,26,27,28,29,30,37,38,39,40,41,42,49,50,51,52,53,54,61,62,63,64,65,66,73,74,75,76,77,78,85,86,87,88,89,90,97,98,99,100,101,102};
 int b[]={12,11,10,9,8,7,24,23,22,21,20,19,36,35,34,33,32,31,48,47,46,45,44,43,60,59,58,57,56,55,72,71,70,69,68,67,84,83,82,81,80,79,96,95,94,93,92,91,108,107,106,105,104,103};
         Scanner sc=new Scanner(System.in);
         t=sc.nextInt();
         for(int k=0;k<t;k++)
         {
         int n;       
         int m=0;
         n=sc.nextInt();
         for(int x=0;x<a.length;x++)
         {
             if(a[x]==n)
             {
                 m=x;
                 System.out.print(b[m]);
                 break;
             }
         }
            for(int x=0;x<b.length;x++)
            {
                if(b[x]==n)
                {
                    m=x;
                    System.out.print(a[m]);
                    break;
                }
            }
            if(b[m]-a[m]==11||b[m]-a[m]==1)
            System.out.print(" "+"WS");
            else if(b[m]-a[m]==9||b[m]-a[m]==3)
            System.out.print(" "+"MS");
            else if(b[m]-a[m]==5||b[m]-a[m]==7)
            System.out.print(" "+"AS");
            System.out.println();
        }
        }
    }

            
         
