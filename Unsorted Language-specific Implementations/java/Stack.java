import java.util.*;
public class Stack {
    int s, t, l; //s defines the size and t points to the top most element
    int a[];

    Stack(int n) {
        s = n;
        t = -1;
        a = new int[s];
        l = 0;
    }
    public boolean isEmpty() // checks if empty

    {

        return t == -1;

    }



    public boolean isFull() //checks if it is full

    {

        return t == s - 1;

    }


    public int getSize()

    {

        return l; //returns the size

    }



    public int peek()

    {

        if (isEmpty())

            throw new NoSuchElementException("Underflow Exception");

        return a[t]; // returns top most element of stack

    }



    public void push(int e) //Function to add elements

    {

        if (t + 1 >= s)

            throw new IndexOutOfBoundsException("Overflow Exception");

        if (t + 1 < s)

            a[++t] = e;

        l++;

    }



    public int pop() //Function to delete an element

    {

        if (isEmpty())

            System.out.println("Underflow Exception");

        l--;

        return a[t--];

    }



    public void display()

    {

        System.out.println("Stack = ");

        if (l == 0)

        {

            System.out.println("Empty");

            return;

        }

        for (int i = t; i >= 0; i--)

            System.out.print(a[i] + " ");

        System.out.println();

    }
    public static void main(String[] args)

    {
        Scanner s = new Scanner(System.in);

        System.out.println("Enter Size of Integer Stack ");

        int n = s.nextInt();

        /* Creating object of class arrayStack */

        Stack k = new Stack(n);

        /* Perform Stack Operations */

        int ch = 1;

        do {

            System.out.println("Enter your choice");

            System.out.println("1. push");

            System.out.println("2. pop");

            System.out.println("3. peek");

            System.out.println("4. check empty");

            System.out.println("5. check full");

            System.out.println("6. size");
            System.out.println("7. Display");

            int choice = s.nextInt();

            switch (choice)

            {

                case 1:

                    System.out.println("Enter integer element to push");
                    k.push(s.nextInt());
                    break;

                case 2:

                    System.out.println("Popped Element = " + k.pop());

                    break;

                case 3:

                    System.out.println("Peek Element = " + k.peek());

                    break;

                case 4:

                    System.out.println("Empty status = " + k.isEmpty());

                    break;

                case 5:

                    System.out.println("Full status = " + k.isFull());

                    break;

                case 6:

                    System.out.println("Size = " + k.getSize());

                    break;
                case 7:
                    k.display();
                    break;
                default:

                    System.out.println("Wrong Entry \n ");

                    break;

            }


            System.out.println("\nDo you want to continue (Type 1 or 0) \n");

            ch = s.nextInt();



        } while (ch == 1);

        s.close();

    }
}
