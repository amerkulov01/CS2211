/*
Title: CS2211 Assignment 4
Purpose: Creating a group table for the 2211 World Cup using structs and user inputs for the team data
Author: Andrei Merkulov
Student Number: 251145994
*/

#include "worldcup_team.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char opCommand = ' ';
int teamCodeArray[33];
int teamSeedArray[33];
int count = 0;                //variable to keep track of where we store the data in the allTeams array, start at index 0
int tempCode;            //variable to temporarily hold team code, in order to check if valid
char tempSeed[];          //variable to temporarily hold group seed, in order to check if valid
char tempColour;              //variable to temporarily hold Kit colour, in order to check if it is valid
int i,j,z;                //variables to be used in loops


void new_Team(teamNode **sPtr) {  //function to add a new team
    teamNode *newPtr;   //pointer to new node
    newPtr = malloc(sizeof(teamNode));  //allocate memory for new node
    printf("\nPlease enter the team code: ");
    scanf("  %d", &tempCode);   //scan in the team code
    if (tempCode<0) {  //if the team code is not between 0 and 31, then it is invalid
        printf("\nThat is not a valid team code :(\n");
        fgetc(stdin);
        free(newPtr);
        return; //return to the new_Team function
    }
    for (i=0;i<=count;i++) {    //for loop to check if the team code already exists
        if ((teamCodeArray[i] == tempCode)&&(teamCodeArray[i] != 0)) {  //if the team code already exists, then it is invalid
            printf("\nThis team code already exists\n");
            fgetc(stdin);
            free(newPtr);
            return; //return to the new_Team function
        }
    }
    teamCodeArray[count] = tempCode;    //if the team code is valid, then store it in the array
    newPtr->teamCode = tempCode;    //store the team code in the new node
    fgetc(stdin);   //clear the buffer

    //scan in the team name
    printf("\nPlease enter a team name: "); 
    fgets(newPtr->teamName, 25, stdin); //scan in the team name
    for (i=0;i<25;i++) {    //for loop to check if the team name is valid
        if (newPtr->teamName[i] == '\n') {  //if the team name is valid, then store it in the array
            newPtr->teamName[i] = '\0'; //replace the new line character with a null character
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
    //loop to check if tempSeed is unique
    for (i=0;i<=count;i++) {    //for loop to check if the group seed already exists
        if (teamSeedArray[i] == tempSeed) {  //if the group seed already exists, then it is invalid
            printf("\nThis group seed already exists\n");
            fgetc(stdin);
            return; //return to the new_Team function
        }
    }
    for (i=0;i<8;i++) {     //for loop to check if the group letter is valid
        if (grpLetter == group_letters[i]){     //if the group letter is valid, then store it in the array
            for (j=0;j<4;j++) {     //for loop to check if the group number is valid
                if (group_nums[j] == grpNum){       //if the group number is valid, then store it in the array
                    teamSeedArray[count] = tempSeed;    //if the group seed is valid, then store it in the array
                    strcpy(newPtr->teamSeed, tempSeed);     //copy the group seed into the array
                }
            }
        }
    }
    if (newPtr->teamSeed == '\0') {      //if the group seed is invalid, then print out an error message
        printf("\nThat is not a valid Group Seed :(\n");
        newPtr->teamCode = NULL;    //set the team code to null
        newPtr->teamName[0] = '\0'; //set the team name to null
        return new_Team(opCommand);         //return to the new_Team function
    }
    fgetc(stdin);   //clear the buffer

    //scan in the team kit colour
    char redColour[4] = "Red";           //array to hold the red colour
    char orangeColour[7] = "Orange";     //array to hold the orange colour
    char yellowColour[7] = "Yellow";     //array to hold the yellow colour
    char greenColour[6] = "Green";       //array to hold the green colour
    char blueColour[5] = "Blue";         //array to hold the blue colour
    char indigoColour[7] = "Indigo";     //array to hold the indigo colour
    char violetColour[7] = "Violet";     //array to hold the violet colour         
    printf("\nPlease enter the primary kit colour: ");
    scanf(" %c", &tempColour);      //scan in the kit colour
    switch (tempColour) {           //switch statement to check if the kit colour is valid
        case 'R':
            strcpy(newPtr->kitColour, redColour);
            break;
        case 'O':
            strcpy(newPtr->kitColour, orangeColour);    //if the kit colour is valid, then store it in the array
            break;
        case 'Y':
            strcpy(newPtr->kitColour, yellowColour);    //if the kit colour is valid, then store it in the array
            break;
        case 'G':
            strcpy(newPtr->kitColour, greenColour);     //if the kit colour is valid, then store it in the array
            break;
        case 'B':
            strcpy(newPtr->kitColour, blueColour);   //if the kit colour is valid, then store it in the array
            break;
        case 'I':
            strcpy(newPtr->kitColour, indigoColour);   //if the kit colour is valid, then store it in the array
            break;
        case 'V':
            strcpy(newPtr->kitColour, violetColour);   //if the kit colour is valid, then store it in the array
            break;
        default:    //if the kit colour is invalid, then print out an error message
            printf("That was an invalid input, please try again\n");
            free(newPtr);
            return;             //return to the new_Team function
    }
    fgetc(stdin);  //clear the buffer
    newPtr->next = NULL;    //set the next pointer to null
    if (newPtr != NULL) {
        if (*sPtr == NULL) {   //if the current pointer is null, then set the start pointer to the new pointer
            *sPtr = newPtr;
        } else {
            struct teamNode *lastNode = *sPtr;  //create a new pointer to the start pointer
            while (lastNode->next != NULL) {   //while the current pointer is not null, then set the current pointer to the next pointer
                lastNode = lastNode->next;
            }
            lastNode->next = newPtr;  //set the next pointer to the new pointer, which adds it to the end of the list
        }
        count +=1;       //increment the count
    } else {
        printf("No memory available\n");    //if the new pointer is null, then print out an error message
    }
}


void search_Team(teamNode **sPtr) {   //function to search for a team 
    printf("      Please enter team code: ");
    scanf(" %d", &tempCode);
    teamNode *currentPtr;   //create a pointer to a teamNode
    currentPtr = *sPtr;     //set the current pointer to the start pointer
    if (currentPtr == NULL) {
        printf("List is empty\n");  //if the current pointer is null, then print out an error message
    } else {
        printf("Team Code   Team Name                 Group Seeding               Primary Kit Colour\n");
        while (currentPtr != NULL) {    //while the current pointer is not null, then set the current pointer to the next pointer
            if (currentPtr->teamCode == tempCode) {  //if the team code is found, then print out the team details
                printf("%-12d%-26s%-28s%s\n", currentPtr->teamCode, currentPtr->teamName, currentPtr->teamSeed, currentPtr->kitColour);
                return;
            }
            currentPtr = currentPtr->next;  //set the current pointer to the next pointer
        }
        if ((currentPtr->next == NULL) && (currentPtr->teamCode == tempCode)) { //if the team code is found, then print out the team details
            printf("%-12d%-26s%-28s%s\n", currentPtr->teamCode, currentPtr->teamName, currentPtr->teamSeed, currentPtr->kitColour);
            return;
        }
        printf("Team not found\n");    //if the team code is not found, then print out an error message
    }
}

void update_Team(teamNode **sPtr) {   //function to update a team
    char grpLetter;    //variable to hold the group letter
    int grpNum;         //variable to hold the group number
    char group_letters[] = {'A','B','C','D','E','F','G','H'};   //array to hold the group letters
    int group_nums[] = {1, 2, 3, 4};    //array to hold the group numbers
    int x;  //variable to hold the team code
    int check = 0;
    printf("Enter team code: ");
    scanf(" %d", &tempCode);
    teamNode *currentPtr;   //create a pointer to a teamNode
    currentPtr = *sPtr;     //set the current pointer to the start pointer
    if (currentPtr == NULL) {
        printf("List is empty\n");  //if the current pointer is null, then print out an error message
        return;
    } else {
        while (currentPtr->next != NULL) {
            if (currentPtr->teamCode == tempCode) {
                printf("\nPlease enter a team name: "); 
                fgets(currentPtr->teamName, 25, stdin); //scan in the team name
                for (i=0;i<25;i++) {    //for loop to check if the team name is valid
                    if (currentPtr->teamName[i] == '\n') {  //if the team name is valid, then store it in the array
                        currentPtr->teamName[i] = '\0'; //replace the new line character with a null character
                    } 
                }
                printf("\nPlease enter the Group Seed: ");  
                scanf(" %s", &tempSeed);    //scan in the group seed
                sscanf(tempSeed, " %c%d", &grpLetter, &grpNum); //split the group letter and number into seperate variables
                //loop to check if tempSeed is unique
                for (i=0;i<=count;i++) {    //for loop to check if the group seed already exists
                    if (teamSeedArray[i] == tempSeed) {  //if the group seed already exists, then it is invalid
                        printf("\nThis group seed already exists\n");
                        return; //return to the new_Team function
                    }
                }
                for (i=0;i<8;i++) {     //for loop to check if the group letter is valid
                    if (grpLetter == group_letters[i]){     //if the group letter is valid, then store it in the array
                        for (j=0;j<4;j++) {     //for loop to check if the group number is valid
                            if (group_nums[j] == grpNum){       //if the group number is valid, then store it in the array
                                teamSeedArray[x] = tempSeed;    //if the group seed is valid, then store it in the array
                                strcpy(currentPtr->teamSeed, tempSeed);     //copy the group seed into the array
                            }
                        }
                    }
                }
                if (currentPtr->teamSeed == '\0') {      //if the group seed is invalid, then print out an error message
                    printf("\nThat is not a valid Group Seed :(\n");
                    currentPtr->teamCode = NULL;    //set the team code to null
                    currentPtr->teamName[0] = '\0'; //set the team name to null
                    return;         //return to the new_Team function
                }
                fgetc(stdin);   //clear the buffer

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
                        fgetc(stdin);   //clear the buffer
                        strcpy(currentPtr->kitColour, redColour);        //if the kit colour is valid, then store it in the array
                        break;
                    case 'O':
                        fgetc(stdin);   //clear the buffer
                        strcpy(currentPtr->kitColour, orangeColour);     //if the kit colour is valid, then store it in the array
                        break;
                    case 'Y':
                        fgetc(stdin);   //clear the buffer
                        strcpy(currentPtr->kitColour, yellowColour);     //if the kit colour is valid, then store it in the array
                        break;
                    case 'G':
                        fgetc(stdin);   //clear the buffer
                        strcpy(currentPtr->kitColour, greenColour);      //if the kit colour is valid, then store it in the array
                        break;
                    case 'B':
                        fgetc(stdin);   //clear the buffer
                        strcpy(currentPtr->kitColour, blueColour);       //if the kit colour is valid, then store it in the array
                        break;
                    case 'I':
                        fgetc(stdin);   //clear the buffer
                        strcpy(currentPtr->kitColour, indigoColour);     //if the kit colour is valid, then store it in the array
                        break;
                    case 'V':
                        fgetc(stdin);   //clear the buffer
                        strcpy(currentPtr->kitColour, violetColour);     //if the kit colour is valid, then store it in the array
                        break;
                    default:    //if the kit colour is invalid, then print out an error message
                        printf("That was an invalid input, please try again\n");
                        free(currentPtr);   //free the memory
                        return;             //return to the new_Team function
                }
                fgetc(stdin);   //clear the buffer
                return;
            }
            currentPtr = currentPtr->next;  //set the current pointer to the next pointer
            x++;
        }        
        if ((currentPtr->next == NULL) && (currentPtr->teamCode == tempCode)) {
            printf("\nPlease enter a team name: "); 
                fgets(currentPtr->teamName, 25, stdin); //scan in the team name
                for (i=0;i<25;i++) {    //for loop to check if the team name is valid
                    if (currentPtr->teamName[i] == '\n') {  //if the team name is valid, then store it in the array
                        currentPtr->teamName[i] = '\0'; //replace the new line character with a null character
                    } 
                }
                printf("\nPlease enter the Group Seed: ");  
                scanf(" %s", &tempSeed);    //scan in the group seed
                sscanf(tempSeed, " %c%d", &grpLetter, &grpNum); //split the group letter and number into seperate variables
                //loop to check if tempSeed is unique
                for (i=0;i<=count;i++) {    //for loop to check if the group seed already exists
                    if (teamSeedArray[i] == tempSeed) {  //if the group seed already exists, then it is invalid
                        printf("\nThis group seed already exists\n");
                        return; //return to the new_Team function
                    }
                }
                for (i=0;i<8;i++) {     //for loop to check if the group letter is valid
                    if (grpLetter == group_letters[i]){     //if the group letter is valid, then store it in the array
                        for (j=0;j<4;j++) {     //for loop to check if the group number is valid
                            if (group_nums[j] == grpNum){       //if the group number is valid, then store it in the array
                                teamSeedArray[x] = tempSeed;    //if the group seed is valid, then store it in the array
                                strcpy(currentPtr->teamSeed, tempSeed);     //copy the group seed into the array
                            }
                        }
                    }
                }
                if (currentPtr->teamSeed == '\0') {      //if the group seed is invalid, then print out an error message
                    printf("\nThat is not a valid Group Seed :(\n");
                    currentPtr->teamCode = NULL;    //set the team code to null
                    currentPtr->teamName[0] = '\0'; //set the team name to null
                    return;         //return to the new_Team function
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
                        strcpy(currentPtr->kitColour, redColour);       //if the kit colour is valid, then store it in the array
                        break;
                    case 'O':
                        strcpy(currentPtr->kitColour, orangeColour);    //if the kit colour is valid, then store it in the array
                        break;
                    case 'Y':
                        strcpy(currentPtr->kitColour, yellowColour);    //if the kit colour is valid, then store it in the array
                        break;
                    case 'G':
                        strcpy(currentPtr->kitColour, greenColour);     //if the kit colour is valid, then store it in the array
                        break;
                    case 'B':
                        strcpy(currentPtr->kitColour, blueColour);      //if the kit colour is valid, then store it in the array
                        break;
                    case 'I':
                        strcpy(currentPtr->kitColour, indigoColour);    //if the kit colour is valid, then store it in the array
                        break;
                    case 'V':
                        strcpy(currentPtr->kitColour, violetColour);    //if the kit colour is valid, then store it in the array
                        break;
                    default:    //if the kit colour is invalid, then print out an error message
                        printf("That was an invalid input, please try again\n");
                        free(currentPtr);   //free the memory
                        return;             //return to the new_Team function
                }
                fgetc(stdin);   //clear the buffer
                return;
        }
        printf("Event code does not exist\n");
    }
}
void print_Team(teamNode **sPtr) {    //function to print out all the teams
    teamNode *currentPtr;
    currentPtr = *sPtr;
    if (currentPtr == NULL) {   //if the list is empty, then print out an error message
        printf("There are no teams in the list\n");
    } else {
        printf("Team Code   Team Name                 Group Seeding               Primary Kit Colour\n");
        while (currentPtr->next != NULL) {  //while loop to print out all the teams
            printf("%-12d%-26s%-28s%s\n", currentPtr->teamCode, currentPtr->teamName, currentPtr->teamSeed, currentPtr->kitColour);
            currentPtr = currentPtr->next;  //set the current pointer to the next pointer
        }
        printf("%-12d%-26s%-28s%s\n", currentPtr->teamCode, currentPtr->teamName, currentPtr->teamSeed, currentPtr->kitColour);
    }
}

void delete_Team(teamNode **sPtr) {
    printf("Enter the team code of the team you would like to delete: ");
    scanf(" %d", &tempCode); //scan in the team code
    teamNode *currentPtr;
    teamNode *previousPtr;
    currentPtr = *sPtr;

    if (currentPtr != NULL && currentPtr->teamCode == tempCode) { //if the team code is the first in the list, then delete it
        *sPtr = currentPtr->next;
        free(currentPtr);
    }
    while (currentPtr == NULL && currentPtr->teamCode != tempCode) { //while loop to find the team code
        previousPtr = currentPtr;
        currentPtr = currentPtr->next;
    }
    if (currentPtr == NULL) {
        printf("Team code does not exist\n");
        return;
    }
    previousPtr->next = currentPtr->next;
    free(currentPtr);
}
