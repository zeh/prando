import java.util.Scanner;
import java.util.Random;
class Hangman
{   

    public static void main(String[] args)
    {   
        System.out.println(" @@@@@@@@@@@@@ PLAY HANGMAN @@@@@@@@@@@@@" );
        String[] s={"DELHI","KARACHI","NEWYORK","LONDON","TOKYO","SURAT","KABUL","DUBAI","JAIPUR","PUNE"};
        Random r=new Random();
        System.out.println("GUESS THE WORLD'S LARGEST CITY");
        System.out.println("Rule: You have 10 chances for correct guess");
        for(;;)
        {

            int randomNumber=r.nextInt(s.length);
            String sw=s[randomNumber];

            String incorrect="";

            String guess="";
            Scanner sc=new Scanner(System.in);
            
            for(int x=0;x<sw.length();x++)
            {
                guess+="_";

            }
            int numLives=0;
            for(;;)
            {   

                System.out.println("YOUR CORRECT GUESSES");
                for(int x=0;x<sw.length();x++)
                {
                    char p=guess.charAt(x);
                    System.out.print(p+" ");
                }
                System.out.println();
                System.out.println("GUESS A LETTER");
                String l=sc.nextLine().toUpperCase();
                char c=l.charAt(0);
                String ssw="";
                if(incorrect.indexOf(c)!=-1)
                    continue;
                else if(guess.indexOf(c)!=-1)
                    continue;
                else if(incorrect.indexOf(c)==-1)
                {
                    if(sw.indexOf(c)!=-1 && guess.indexOf(c)==-1)

                    {
                        for(int x=0;x<sw.length();x++)
                        {
                            char a=sw.charAt(x);
                            char b=guess.charAt(x);
                            if(a==c)
                            {
                                ssw+=c;
                            }
                            else
                            {
                                ssw+=b;
                            }
                        }
                        guess=ssw;
                    }

                    else
                    {
                        incorrect+=c;

                        System.out.println("MISSES = "+incorrect);
                        numLives++;
                        
                    }
                }

                if(guess.indexOf('_')==-1 )
                    break;
                if(numLives==10)
                    break;
            }
            System.out.println();
            if(guess.indexOf('_')!=-1) 
            {System.out.println(sw);
                System.out.println("@@ YOU HAVE LOST THE GAME @@ ");}
            else
            {System.out.print(sw);
                System.out.println("@@ WON! CONGRATULATION GET YOUR PRICE @@");
            }
            String Q;
            char P=0;
            System.out.println("DO YOU WANT TO CONTINUE PLAY AGAIN IF YES THEN CLICK Y OR IF NOT THEN CLICK SOMETHING ELSE");
            boolean repeat=false;
            do
            {
                repeat=false;
                try
                {
                    Q=sc.nextLine();
                    P=Q.charAt(0);
                    if(!Character.isLetter(P))
                        throw new Exception();
                }
                catch (Exception e)
                {
                    repeat=true;
                }
            }
            while(repeat==true);
            if(P=='y'||P=='Y')
                continue;
            else
            {
                break;

            }

        }

    }
    }
