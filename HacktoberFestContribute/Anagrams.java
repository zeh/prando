/*
a simple program that sees if the two given strings are the anagrams of each other
How to use: 
1. Type in the words
2. Magic
3. See the result :)

Created by Miautawn
 */

package com.Miautawn;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        boolean flag = true;
        Scanner scan = new Scanner(System.in);
        System.out.println("Please enter the xdd word: ");
        char[] firstWord = scan.next().toCharArray();  // instantly convert both strings to character arrays
        System.out.println("Please enter the second word: ");
        char[] secondWord = scan.next().toCharArray(); //

        if(firstWord.length == secondWord.length)
        {
            // we are checking if those two word have the same amount of letters

        }
        else
        {
            System.out.println("These are not anagrams!");

            System.exit(-1);

        }

        for (int i = 0; i < firstWord.length; i++)
        {
            flag = true;

            for (int j = 0; j < secondWord.length; j++)
            {
                if(firstWord[i] == secondWord[j])
                {
                    System.out.println("there is one " + secondWord[j]);
                    flag = false;
                    firstWord[i] = '\0';
                    secondWord[j] = '\0';
                    break;
                }
                else
                {
                   //keep looking
                }
            }
            if (flag == true)
            {

                System.out.println("One word does not contain the same letter as the other: The first one has " + firstWord[i] + " and the other word does not have it! So these are not anagrams!");
                System.exit(0);
            }
            else
            {
                //nothing
            }

        }
        System.out.println("Congratulations - These two word are anagrams");
    }
}