import java.util.Random;
import java.util.Scanner;
class Guess
{
    public static void main()
    {
        System.out.println("###############"+" "+"MATHEMATICS QUIZ"+" "+"###############");
        int score,a,b,c;
        score=0;
        Random rg=new Random(System.currentTimeMillis());
        Scanner d=new Scanner(System.in);
        for(int x=1;x<=10;x++)
        {
            System.out.println("QUESTION"+" "+x);
           a=rg.nextInt(39);
           b=rg.nextInt(100);
           System.out.println(a+"+"+b+"="+"__");
           c=d.nextInt();
           
           if(a+b==c)
           {
            score++;
           System.out.println("Correct Answer");
           System.out.println("Score:"+" "+score);
          
           }
           else
           {
               System.out.println("Incorrect Answer");
               System.out.println("Score:"+" "+score);
            }
         
       }
    
        System.out.println("Total Score"+"="+score);
        System.out.println("Thanks for playing this game");
    }
}

           
           
           
          
