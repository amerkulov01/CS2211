/*
Title: CS2211 Assignment 2
Purpose: converting integeres into their corresponding words
Author: Andrei Merkulov
Student Number: 251145994
*/

#include <stdio.h>
#include <string.h>

char * getValue(int num, int weight) {  //function to assign each digit to its corresponding word
    switch(num) {
        case 0: //if digit is 0
            if (weight == 0){
                return "ten";
            }
            if (weight == 1) {
                return "zero";
            }
            else {
                return "";
            } 
        case 1: //if digit is 1 etc...
            if (weight == 0) {
                return "eleven";
            }
            else {
                return "one";
            }
        case 2:
            if (weight == 0) {
                return "twelve";
            }
            if (weight == 2) {
                return "twenty";
            }
            else {
                return "two";
            }
        case 3:
            if (weight == 0) {
                return "thirteen";
            }
            if (weight == 2) {
                return "thirty";
            }
            else {
                return "three";
            }
        case 4:
            if (weight == 0) {
                return "fourteen";
            }
            if (weight == 2) {
                return "fourty";
            }
            else {
                return "four";
            }
        case 5:
            if (weight == 0) {
                return "fifteen";
            }
            if  (weight == 2) {
                return "fifty";
            }
            else {
                return "five";
            }
        case 6:
            if (weight == 0) {
                return "sixteen";
            }
            if  (weight == 2) {
                return "sixty";
            }
            else {
                return "six";
            }
        case 7:
            if (weight == 0) {
                return "seventeen";
            }
            if  (weight == 2) {
                return "seventy";
            }
            else {
                return "seven";
            }
        case 8:
            if (weight == 0) {
                return "eighteen";
            }
            if  (weight == 2) {
                return "eighty";
            }
            else {
                return "eight";
            }
        case 9:
            if (weight == 0) {
                return "nineteen";
            }
            if  (weight == 2) {
                return "ninety";
            }
            else {
                return "nine";
            }
        default:
            return "";
    }
}

int main() {    //main function to put the words for each digit into one phrase
    int num;
    for(;;) {
        printf("Please enter a value (1-999, 0 to quit): ");
        scanf("%d",&num);   //users input
        if (num == 0) { //quits code if input is 0
            return 1;
        }
        const int digitOne = num % 10;  //deconstructing the users integer to get the first digit
        num /= 10;
        const int digitTwo = num % 10;  //getting the second digit
        const int digitThree = num / 10;    //getting the third digit
        printf("You entered the number ");  //setting up the formatted output
        if (digitThree > 0) {   //if there are 3 digits
            printf("%s hundred", getValue(digitThree, 3)); //adds 'hundred' to the string
            if (digitTwo > 0 || digitOne > 0) { //if there is a first or second digit it prints and so that grammar is good in the output
                printf(" and ");
            }
        }
        if (digitTwo == 1) {    //for the teen digits
            printf("%s", getValue(digitOne, 0));
        }
        else if (digitTwo > 1) {    //for numbers between 20-99 
            printf("%s", getValue(digitTwo, 2));
            if (digitOne > 0) {
                printf("-%s", getValue(digitOne, 1));
            }
        }
        else if (digitOne > 0) {
            printf("%s", getValue(digitOne, 1));
        }
        printf("\n");
    }
    return 0;
}
