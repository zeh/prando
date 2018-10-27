import java.util.*;
public class Test {

   public static void main(String args[]) 
   {int sum1=0;
       int sum2=0;
       int sum=0;
       String t;
       boolean isvalid=false;
       System.out.println("Please enter your cradit card number");
       Scanner d=new Scanner(System.in);
       t=d.nextLine();
      isvalid =check(t);
      System.out.println(isvalid);
      if(isvalid==true)
      {
          int k;
          for(int x=(t.length())-2;x>=0;x-=2)
          {
              char c=t.charAt(x);
              int b=Integer.parseInt(c+"");
              int r=b*2;
              if(r>9)
              {
                 k=r%10+r/10;
                sum1+=k;
            }
            else
            {
                sum1+=r;
            
            }
        }
            
            for(int x=(t.length())-1;x>=0;x-=2)
            {
                char c=t.charAt(x);
                int g=Integer.parseInt(c+"");
                sum2+=g;
            }
        sum=sum1+sum2;         
         if(sum%10==0)
       {
        System.out.println("credit card number is valid");
       MII(t);
       IIN(t);
       account(t);
      }
    else
    {System.out.println("Not valid");
     char f=t.charAt(t.length()-1);
     int u=Integer.parseInt(f+"");
     int i=sum-u;
     int x=i%10;
     int z=10-x;
     
     System.out.println("Check Digit will be:"+z);
        
    }
        
    }
}
    public static boolean check(String s)
    {
        int count=0;
     for(int x=0;x<s.length();x++)
     {
         char c=s.charAt(x);
        if(Character.isDigit(c))
        {
         count++;
        }
    }
         if(count==s.length()&&(s.length()>=12||s.length()<=19))
         return true;
        else
        return false;
}
public static void MII(String n)
               {
                   if(n.charAt(0)=='1'||n.charAt(0)=='2')
                                     System.out.println("Airlines");
                                     else
                                         if(n.charAt(0)=='3')
                                     System.out.println("Travel");
                                     else
                                         if(n.charAt(0)=='4'||n.charAt(0)=='5')
                                     System.out.println("Banking And Financial");
                                     else
                                        if(n.charAt(0)=='6')
                                           System.out.println("Merchandising And Banking/Financial"); 
                                    else
                                          if(n.charAt(0)=='7')
                                        System.out.println("Petrolium");
                                        else
                                            if(n.charAt(0)=='8')
                                               System.out.println("Healthcare And Telecommunications");
                                               else
                    
                                  System.out.println("Unknown");  
                    } 
                    public static void IIN(String h)
                    {
                        String q=h.substring(0,2);
                        String o=h.substring(0,1);
                        String p=h.substring(0,4);
                        if(q.equals("34")||q.equals("37"))
                        System.out.println("Amex");
                        else if(q.equals("51")||q.equals("52")||q.equals("53")||q.equals("54")||q.equals("55"))
                        System.out.println("Mastercard");
                        else if(o.equals("4"))
                        System.out.println("Visa");
                        else if(p.equals("6011")||p.equals("644")||p.equals("65"))
                        System.out.println("Discover");
                        else
                        System.out.println("Unknown");
                    }
                    public static void account(String v)
                    {
                        String w=v.substring(7,v.length()-1);
                        System.out.println("Account Number is"+' '+w);  
                        
                    }
      
