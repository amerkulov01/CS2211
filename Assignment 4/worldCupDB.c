/*
Title: CS2211 Assignment 4
Purpose: Creating a group table for the 2211 World Cup using structs and user inputs for the team data
Author: Andrei Merkulov
Student Number: 251145994
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char opCommand = ' ';
int count = 0;                //variable to keep track of where we store the data in the allTeams array, start at index 0
int tempCode;            //variable to temporarily hold team code, in order to check if valid
char tempSeed[];          //variable to temporarily hold group seed, in order to check if valid
char tempColour;              //variable to temporarily hold Kit colour, in order to check if it is valid
int i,j; 

struct team {   //structure to hold team information
    int teamCode;   //team code
    char teamName[26];  //team name
    char teamSeed[3];   //  team seed
    char kitColour[10]; //team kit colour
};
struct team allTeams[32];   //array to hold all teams

int new_Team(char c);       //function to add a new team
int search_Team(char c);    //function to search for a team
int update_Team(char c);    //function to update a team
int print_Team(char c);     //function to print a team

int main() {        //main function to run the program and call the functions 
    
    printf("******************\n");
    printf("* 2211 World Cup *\n");
    printf("******************\n");
    
    while (opCommand != 'q') { //while loop to keep the program running until the user enters q to quit
        printf("\nEnter operation code\ni : to enter a new team\ns : to search for a team\nu : to update a team\np : to list all teams\nq : to quit\n");
        scanf(" %c",&opCommand);   //scan in the operation code
        switch (opCommand) {   //switch statement to call the functions based on the user input
            case 'i': 
                new_Team(opCommand);   //call the new_Team function
                break;
            case 's':
                search_Team(opCommand);     //call the search_Team function
                break;
            case 'u':
                update_Team(opCommand);    //call the update_Team function
                break;
            case 'p':
                print_Team(opCommand);   //call the print_Team function
                break;
        }
    }
    printf("Program Terminated");  //print out when the user enters q to quit
    return 0;  //end the program
}

int new_Team(char opCommand) {  //function to add a new team
    //scan in new Team code
    printf("\nPlease enter the team code: ");
    scanf("  %d", &tempCode);   //scan in the team code
    if (count == 32) {  //if the count is 32, then the array is full and the user cannot add any more teams
        printf(" \nArray is full, try updating an existing team\n");
        return main();  //return to the main function
    }
    if ((tempCode<0)||(tempCode>32)) {  //if the team code is not between 0 and 31, then it is invalid
        printf("\nThat is not a valid team code :(\n");
        return new_Team(opCommand); //return to the new_Team function
    }
    for (i=0;i<=count;i++) {    //for loop to check if the team code already exists
        if ((allTeams[i].teamCode == tempCode)&&(allTeams[i].teamCode != 0)) {  //if the team code already exists, then it is invalid
            printf("\nThis team code already exists\n");
            return new_Team(opCommand); //return to the new_Team function
        }
    }
    allTeams[count].teamCode = tempCode;    //if the team code is valid, then store it in the array
    fgetc(stdin);   //clear the buffer

    //scan in the team name
    printf("\nPlease enter a team name: "); 
    fgets(allTeams[count].teamName, 26, stdin); //scan in the team name
    for (i=0;i<26;i++) {    //for loop to check if the team name is valid
        if (allTeams[count].teamName[i] == '\n') {  //if the team name is valid, then store it in the array
            allTeams[count].teamName[i] = '\0'; //replace the new line character with a null character
        } 
    }

    //scan in the team seed
    char group_letters[] = {'A','B','C','D','E','F','G','H'};   //array to hold the group letters
    int group_nums[] = {1, 2, 3, 4};    //array to hold the group numbers
    printf("\nPlease enter the Group Seed: ");  
    char grpLetter; //variable to hold the group letter
    int grpNum; 
    scanf(" %s", &tempSeed);    //scan in the group seed
    sscanf(tempSeed, " %c%d", &grpLetter, &grpNum); //split the group letter and number into seperate variables
    for (i=0;i<8;i++) {     //for loop to check if the group letter is valid
        if (grpLetter == group_letters[i]){     //if the group letter is valid, then store it in the array
            for (j=0;j<4;j++) {     //for loop to check if the group number is valid
                if (group_nums[j] == grpNum){       //if the group number is valid, then store it in the array
                    strcpy(allTeams[count].teamSeed, tempSeed);     //copy the group seed into the array
                }
            }
        }
    }
    if (allTeams[count].teamSeed[0] == '\0') {      //if the group seed is invalid, then print out an error message
        printf("\nThat is not a valid Group Seed :(\n");
        allTeams[count].teamCode = NULL;    //set the team code to null
        allTeams[count].teamName[0] = '\0'; //set the team name to null
        return new_Team(opCommand);         //return to the new_Team function
    }
    fflush(stdin);  //clear the buffer

    //scan in the team kit colour
    char redColour[] = "Red";           //array to hold the red colour
    char orangeColour[] = "Orange";     //array to hold the orange colour
    char yellowColour[] = "Yellow";     //array to hold the yellow colour
    char greenColour[] = "Green";       //array to hold the green colour
    char blueColour[] = "Blue";         //array to hold the blue colour
    char indigoColour[] = "Indigo";     //array to hold the indigo colour
    char violetColour[] = "Violet";     //array to hold the violet colour         
    printf("\nPlease enter the primary kit colour: ");
    scanf(" %c", &tempColour);      //scan in the kit colour
    switch (tempColour) {           //switch statement to check if the kit colour is valid
        case 'R':
            strcpy(allTeams[count].kitColour, redColour);       //if the kit colour is valid, then store it in the array
            break;
        case 'O':
            strcpy(allTeams[count].kitColour, orangeColour);    //if the kit colour is valid, then store it in the array
            break;
        case 'Y':
            strcpy(allTeams[count].kitColour, yellowColour);    //if the kit colour is valid, then store it in the array
            break;
        case 'G':
            strcpy(allTeams[count].kitColour, greenColour);     //if the kit colour is valid, then store it in the array
            break;
        case 'B':
            strcpy(allTeams[count].kitColour, blueColour);      //if the kit colour is valid, then store it in the array
            break;
        case 'I':
            strcpy(allTeams[count].kitColour, indigoColour);    //if the kit colour is valid, then store it in the array
            break;
        case 'V':
            strcpy(allTeams[count].kitColour, violetColour);    //if the kit colour is valid, then store it in the array
            break;
        default:    //if the kit colour is invalid, then print out an error message
            printf("That was an invalid input, please try again\n");
            allTeams[count].teamCode = NULL;        //set the team code to null
            allTeams[count].teamName[0] = '\0';     //set the team name to null
            strcpy(allTeams[count].teamSeed, "");   //set the group seed to null
            return new_Team(opCommand);             //return to the new_Team function
    }

    count ++;       //increment the count
    return 0;       //return to the main function
    
}
int search_Team(char opCommand) {   //function to search for a team 
    int check = 0;
    int x;
    printf("      Please enter team code: ");
    scanf(" %d", &tempCode);
    for (i=0;i<=count;i++) {    //for loop to check if the team code exists
        if (allTeams[i].teamCode == tempCode) {     //if the team code exists, then print out the team details
            check = 1; //set the check variable to 1
            x = i; //store the index of the team in the array
        }
    }
    if (check == 1) {  //if the team code exists, then print out the team details
            printf("Team Code   Team Name                 Group Seeding               Primary Kit Colour\n");
            printf("%-12d%-26s%-28s%s\n", allTeams[x].teamCode, allTeams[x].teamName, allTeams[x].teamSeed, allTeams[x].kitColour); 
            fflush(stdin);  //clear the buffer
            return 0;    //return to the main function
        } else {    //if the team code does not exist, then print out an error message
            printf("That was not a valid Team Code\n");
            return search_Team(opCommand);  //return to the search_Team function
        }
}

int update_Team(char opCommand) {   //function to update a team
    char grpLetters;    //variable to hold the group letter
    int grpNum;         //variable to hold the group number
    char group_letters[] = {'A','B','C','D','E','F','G','H'};   //array to hold the group letters
    int group_nums[] = {1, 2, 3, 4};    //array to hold the group numbers
    int x;  //variable to hold the team code
    int check = 0;
    printf("Enter team code: ");
    scanf(" %d", &tempCode);
    for (i=0;i<=count;i++) {    //for loop to check if the team code exists
        if (allTeams[i].teamCode == tempCode) { //if the team code exists, proceed
            x = i;      //store the index of the team in the array
            check = 1; //set the check variable to 1
        }
    }
    if (check == 1) {   //if the team code exists, then proceed    
        fgetc(stdin);
        printf("\nPlease enter team name: ");
        fgets(allTeams[x].teamName, 26, stdin);   //scan in the team name
        for (i=0;i<26;i++) {    
            if (allTeams[x].teamName[i] == '\n') {      
                allTeams[x].teamName[i] = '\0'; 
            }
        }
        printf("\nPlease enter group seeding: "); 
        scanf(" %s", &tempSeed);    //scan in the group seed
        sscanf(tempSeed, " %c%d", &grpLetters, &grpNum);    //split the group letter and number into separate variables
        for (i=0;i<8;i++) {    //for loop to check if the group letter is valid
            if (grpLetters == group_letters[i]){    //if the group letter is valid, proceed
                for (j=0;j<4;j++) {   //for loop to check if the group number is valid
                    if (group_nums[j] == grpNum){   //if the group number is valid, proceed
                        strcpy(allTeams[x].teamSeed, tempSeed);  //store the group seed in the array
                    }
                } 
            } 
        }
        if (allTeams[x].teamSeed[0] == '\0') {  //if the group seed is invalid, then print out an error message
            printf("\nThat is not a valid Group Seed :(\n");
            return update_Team(opCommand);  //return to the update_Team function
        }
        
        char redColour[] = "Red";       //array to hold the red colour
        char orangeColour[] = "Orange"; //array to hold the orange colour
        char yellowColour[] = "Yellow"; //array to hold the yellow colour
        char greenColour[] = "Green";   //array to hold the green colour
        char blueColour[] = "Blue";     //array to hold the blue colour
        char indigoColour[] = "Indigo"; //array to hold the indigo colour
        char violetColour[] = "Violet"; //array to hold the violet colour
        printf("\nPlease enter the primary kit colour: ");
        scanf(" %c", &tempColour);  //scan in the kit colour
        switch (tempColour) {   //switch statement to check if the kit colour is valid
            case 'R':
                strcpy(allTeams[x].kitColour, redColour);       //if the kit colour is valid, then store it in the array
                break;
            case 'O':
                strcpy(allTeams[x].kitColour, orangeColour);    //if the kit colour is valid, then store it in the array
                break;
            case 'Y':
                strcpy(allTeams[x].kitColour, yellowColour);    //if the kit colour is valid, then store it in the array
                break;
            case 'G':
                strcpy(allTeams[x].kitColour, greenColour);     //if the kit colour is valid, then store it in the array
                break;
            case 'B':
                strcpy(allTeams[x].kitColour, blueColour);      //if the kit colour is valid, then store it in the array
                break;
            case 'I':
                strcpy(allTeams[x].kitColour, indigoColour);    //if the kit colour is valid, then store it in the array
                break;
            case 'V':
                strcpy(allTeams[x].kitColour, violetColour);    //if the kit colour is valid, then store it in the array
                break;
            default:    //if the kit colour is invalid, then print out an error message
                printf("That was an invalid input, please try again\n");
                return update_Team(opCommand);  //return to the update_Team function
        }
        fflush(stdin);  //clear the buffer
        return 0;   //return to the main function
    } else {    //if the team code does not exist, then print out an error message
        printf("\nThat team does not exist\n");
        return update_Team(opCommand);  //return to the update_Team function
    }
}

int print_Team(char opCommand) {    //function to print out all the teams
    for (i=0;i<count;i++) {         //for loop to print out all the teams
            printf("Team Code   Team Name                 Group Seeding               Primary Kit Colour\n");
            printf("%-12d%-26s%-28s%s\n", allTeams[i].teamCode, allTeams[i].teamName, allTeams[i].teamSeed, allTeams[i].kitColour);
            fflush(stdin);  //clear the buffer
    }
    return 0;   //return to the main function
}
