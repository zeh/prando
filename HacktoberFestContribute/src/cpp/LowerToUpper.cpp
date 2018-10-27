// File name: LowerToUpper.cpp
// Author: Viet Than
// Email: viet.than@vanderbilt.edu, thanhoangviet@gmail.com
// Repository owner: rathoresrikant
// Repository name: HacktoberFestContribute
// Honor statement: I attest that I understand the honor code for this class
// and have neither given nor received any unauthorized aid on this assignment.
//
// Issue: In a string, convert all the lowercase letters to upper case and vice versa.

#include <iostream>
#include <string>

int main(){
    std::string input;

    std::cout << "This function will turn characters in string from lowercase"
                 "to uppercase and vice versa.\nPlease input string:\n";
    std::cin >> input;

    std::cout << "The value you entered is: " << input << std::endl;

    for (char &i : input) {
        if (islower(i)){
            i = static_cast<char>(toupper(i));
        } else {
            i = static_cast<char>(tolower(i));
        }
    }
    std::cout << "The resulting changed string is: "<< input;


    return 0;
}

