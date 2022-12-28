#include "worldcup_player.h"
#include <stdlib.h>

int tempPlID;
int playerIDArray[99999];
int tempAge;
char tempName[50];
char tempTeam[50];
int m;
int count2 = 0;

void new_Player(playerNode **sPtr) {
    playerNode *newPlayerNode;
    newPlayerNode = malloc(sizeof(playerNode));

    printf("Enter player ID: ");
    scanf("%d", &tempPlID);
    if (tempPlID<0) {  //if the team code is not between 0 and 31, then it is invalid
        printf("\nThat is not a valid team code :(\n");
        fgetc(stdin);
        free(newPlayerNode);
        return; //return to the new_Team function
    }
    for (m=0;m<=count2;m++) {    //for loop to check if the team code already exists
        if ((playerIDArray[m] == tempPlID)&&(playerIDArray[m] != 0)) {  //if the team code already exists, then it is invalid
            printf("\nThis team code already exists\n");
            return; //return to the new_Team function
        }
    }
    playerIDArray[count2] = tempPlID;    //if the team code is valid, then store it in the array
    newPlayerNode->playerID = tempPlID;    //store the team code in the new node
    fgetc(stdin);   //clear the buffer

    printf("Enter player name: ");
    fgets(newPlayerNode->playerName, 50, stdin);    //store the team name in the new node
    for (m=0;m<50;m++) {    //for loop to remove the new line character from the end of the team name
        if (newPlayerNode->playerName[m] == '\n') {
            newPlayerNode->playerName[m] = '\0';
        }
    }

    printf("Enter player age: ");
    scanf("%d", &tempAge);
    if ((tempAge<17)||(tempAge>99)) {
        printf("\nThat is not a valid age:(\nEnter an age in between 17 and 99\n");
        fgetc(stdin);
        free(newPlayerNode);
        free(newPlayerNode->playerName);
        free(newPlayerNode->playerID);
        return; //return to the new_Team function
    } 
    
    newPlayerNode->playerAge = tempAge;    //store the team code in the new node
    fgetc(stdin);   //clear the buffer

    printf("Enter player's club affiliation: ");
    fgets(newPlayerNode->playerClub, 50, stdin);    //store the team name in the new node
    for (m=0;m<50;m++) {    //for loop to remove the new line character from the end of the team name
        if (newPlayerNode->playerClub[m] == '\n') {
            newPlayerNode->playerClub[m] = '\0';
        }
    }

    newPlayerNode->nextPlayerPtr = NULL;  //set the next pointer to NULL
    playerNode *currentPtr = *sPtr; //set the current pointer to the start of the list
    if (newPlayerNode != NULL) {   //if the new node is not NULL
        if (currentPtr == NULL) {   //if the current pointer is NULL
            *sPtr = newPlayerNode;  //set the start of the list to the new node
        }
        else {  //if the current pointer is not NULL
            while (currentPtr->nextPlayerPtr != NULL) {    //while the next pointer is not NULL
                currentPtr = currentPtr->nextPlayerPtr;    //set the current pointer to the next pointer
            }
            if (currentPtr->nextPlayerPtr == NULL) {  //if the next pointer is NULL
                currentPtr->nextPlayerPtr = newPlayerNode;  //set the next pointer to the new node
            }
        }
        count2++;   //increment the count
    } else {
        printf("Error: Memory not allocated");
    }
}

void search_Player(playerNode **sPtr) {
    printf("Enter the Player ID you would like to search for: ");
    scanf("%d", &tempPlID);
    playerNode *currentPtr = *sPtr; //set the current pointer to the start of the list
    if (currentPtr == NULL) {   //if the current pointer is NULL
        printf("The list is empty.");
        return;
    } else {
        printf("Player ID   Player Name                 Player Age               Club Affilation\n");
        while (currentPtr->nextPlayerPtr != NULL) {    //while the next pointer is not NULL
            if (currentPtr->playerID == tempPlID) {    //if the team code matches the team code entered by the user
                printf("%-12d%-26s%-28s%s\n", currentPtr->playerID, currentPtr->playerName, currentPtr->playerAge, currentPtr->playerClub);
                return;
            }
            currentPtr = currentPtr->nextPlayerPtr;    //set the current pointer to the next pointer
        }
        if ((currentPtr->nextPlayerPtr == NULL)&&(currentPtr->playerID == tempPlID)) {  //if the next pointer is NULL
            printf("%-12d%-26s%-28s%s\n", currentPtr->playerID, currentPtr->playerName, currentPtr->playerAge, currentPtr->playerClub);
            return;
        }
        printf("Player not found\n");
    }
}

void update_Player(playerNode **sPtr) {
    printf("Enter the Player ID you would like to update: ");
    scanf("%d", &tempPlID);
    playerNode *currentPtr = *sPtr; //set the current pointer to the start of the list
    if (currentPtr == NULL) {   //if the current pointer is NULL
        printf("The list is empty.");
        return;
    } else {
        while (currentPtr->nextPlayerPtr != NULL) {    //while the next pointer is not NULL
            if (currentPtr->playerID == tempPlID) {    //if the team code matches the team code entered by the user
                printf("Enter player name: ");
                fgets(currentPtr->playerName, 50, stdin);    //store the team name in the new node
                for (m=0;m<50;m++) {    //for loop to remove the new line character from the end of the team name
                    if (currentPtr->playerName[m] == '\n') {
                        currentPtr->playerName[m] = '\0';
                    }
                }

                printf("Enter player age: ");
                scanf("%d", &tempAge);
                if ((tempAge<17)||(tempAge>99)) {
                    printf("\nThat is not a valid age:(\nEnter an age in between 17 and 99\n");
                    fgetc(stdin);
                    return; //return to the new_Team function
                }
                currentPtr->playerAge = tempAge;    //store the team code in the new node
                fgetc(stdin);   //clear the buffer

                printf("Enter player's club affiliation: ");
                fgets(currentPtr->playerClub, 50, stdin);    //store the team name in the new node
                for (m=0;m<50;m++) {    //for loop to remove the new line character from the end of the team name
                    if (currentPtr->playerClub[m] == '\n') {
                        currentPtr->playerClub[m] = '\0';
                    }
                }
                return;
            }
            currentPtr = currentPtr->nextPlayerPtr;    //set the current pointer to the next pointer
        }
        if ((currentPtr->nextPlayerPtr == NULL)&&(currentPtr->playerID == tempPlID)) {  //if the next pointer is NULL
            printf("Enter player name: ");
            fgets(currentPtr->playerName, 50, stdin);    //store the team name in the new node
            for (m=0;m<50;m++) {    //for loop to remove the new line character from the end of the team name
                if (currentPtr->playerName[m] == '\n') {
                    currentPtr->playerName[m] = '\0';
                }
            }

            printf("Enter player age: ");
            scanf("%d", &tempAge);
            if ((tempAge<17)||(tempAge>99)) {
                printf("\nThat is not a valid age:(\nEnter an age in between 17 and 99\n");
                fgetc(stdin);
                return; //return to the new_Team function
            }
            currentPtr->playerAge = tempAge;    //store the team code in the new node
            fgetc(stdin);   //clear the buffer

            printf("Enter player's club affiliation: ");
            fgets(currentPtr->playerClub, 50, stdin);    //store the team name in the new node
            for (m=0;m<50;m++) {    //for loop to remove the new line character from the end of the team name
                if (currentPtr->playerClub[m] == '\n') {
                    currentPtr->playerClub[m] = '\0';
                }
            }
            return;
        }
        printf("Player not found\n");
    }
}

void print_Player(playerNode **sPtr) {
    playerNode *currentPtr = *sPtr; //set the current pointer to the start of the list
    if (currentPtr == NULL) {   //if the current pointer is NULL
        printf("The list is empty.");
        return;
    } else {
        printf("Player ID   Player Name                 Player Age               Club Affilation\n");  //print the header
        while (currentPtr->nextPlayerPtr != NULL) {    //while the next pointer is not NULL
            printf("%-12d%-26s%-28s%s\n", currentPtr->playerID, currentPtr->playerName, currentPtr->playerAge, currentPtr->playerClub);
            currentPtr = currentPtr->nextPlayerPtr;    //set the current pointer to the next pointer
        }
        printf("%-12d%-26s%-28s%s\n", currentPtr->playerID, currentPtr->playerName, currentPtr->playerAge, currentPtr->playerClub);
    }
}

void delete_Player(playerNode **sPtr) {
    printf("Enter the Player ID you would like to delete: ");
    scanf("%d", &tempPlID);
    playerNode *currentPtr;
    currentPtr = *sPtr;
    playerNode *previousPtr;

    if (currentPtr != NULL && currentPtr->playerID == tempPlID) { //if the current pointer is not NULL and the team code matches the team code entered by the user
        *sPtr = currentPtr->nextPlayerPtr;  //set the start of the list to the next pointer
        free(currentPtr);   //free the memory
    }
    while (currentPtr != NULL && currentPtr->playerID != tempPlID) {  //while the current pointer is not NULL and the team code does not match the team code entered by the user
        previousPtr = currentPtr;   //set the previous pointer to the current pointer
        currentPtr = currentPtr->nextPlayerPtr;    //set the current pointer to the next pointer
    }
    if (currentPtr == NULL) {   //if the current pointer is NULL
        printf("Player not found");
        return;
    }
    previousPtr->nextPlayerPtr = currentPtr->nextPlayerPtr;  //set the next pointer of the previous pointer to the next pointer of the current pointer
    free(currentPtr);   //free the memory
}
        
