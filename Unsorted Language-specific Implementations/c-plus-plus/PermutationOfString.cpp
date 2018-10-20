// File name: LowerToUpper.cpp
// Author: Viet Than
// Email: viet.than@vanderbilt.edu, thanhoangviet@gmail.com
// Repository owner: rathoresrikant
// Repository name: HacktoberFestContribute
// Honor statement: I attest that I understand the honor code for this assignment
// and has only worked with one other person
//
// Issue: Print all permutation of a string

#include <iostream>
#include <string>

std::string StringPermutation(std::string input);

int main(){
    std::string input = "abcd";
    std::string undividedString = StringPermutation(input);
    size_t inputSize = input.length();
    size_t undividedSize = undividedString.length();

    for (size_t i= 0; i< undividedSize; i=i+inputSize){
        std::cout << undividedString.substr(i, inputSize)<<std::endl;
    }

    return 0;
}

std::string StringPermutation(std::string input){
    size_t inputSize = input.length();

    if (inputSize==1){
        return input;
    } else {
        std::string total;
        for (size_t i=0; i<inputSize; i++){
            std:: string toPass = input;
            toPass.erase(i, 1);
            char first = input[i];
            std::string result = StringPermutation(toPass);
            size_t toPassLength, resultLength;
            toPassLength = toPass.length();
            resultLength = result.length();

            if (resultLength==1){
                total = total+first+result+result+first;
                return total;
            } else {
                for (size_t j = 0; j<resultLength/toPassLength; j++){
                    total = total+first+result.substr(toPassLength*(j), toPassLength);
                }
            }

        }
        return total;
    }
}
