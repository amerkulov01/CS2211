/*
Title: CS2211 Assignment 5
Purpose: Creating a group table for the 2211 World Cup using structs and user inputs for the team data
Author: Andrei Merkulov
Student Number: 251145994
*/

#include "worldCupDB.h"

int main (void) {
    struct teamNode *teamTBL = NULL;
    struct playerNode *playerTBL = NULL;

    char cmnd, opCommand;
    printf("****************************");
    printf("*   2211 Winter Olympics   *");
    printf("****************************");

    for (;;) {
        printf("\n\nPlease enter a command (h for help, t for teams, p for players, q to quit): ");
        scanf(" %c", &cmnd);
        while (getchar() != '\n')
        ;
        if (cmnd == 'h') {
            print_help();
        } else if (cmnd == 't') {
            printf("Teams:\n");
            printf("\nEnter operation code\ni : to enter a new team\ns : to search for a team\nu : to update a team\np : to list all teams\nd : to delete a team\n");
            scanf(" %c", &opCommand);
            while (getchar() != '\n')
            ;
            switch (opCommand) {
                case 'i':
                    new_Team(teamTBL);
                    break;
                case 's':
                    search_Team(teamTBL);
                    break;
                case 'u':
                    update_Team(teamTBL);
                    break;
                case 'p':
                    print_Team(teamTBL);
                    break;
                case 'd':
                    delete_Team(teamTBL);
                    break;
                default:
                    printf("Invalid command\n");
                    break;
            }
        } else if (cmnd == 'p') {
            printf("Players:\n");
            printf("\nEnter operation code\ni : to enter a new player\ns : to search for a player\nu : to update a player\np : to list all players\nd : to delete a player\n");
            scanf(" %c", &opCommand);
            while (getchar() != '\n')
            ;
            switch (opCommand) {
                case 'i':
                    new_Player(playerTBL);
                    break;
                case 's':
                    search_Player(playerTBL);
                    break;
                case 'u':
                    update_Player(playerTBL);
                    break;
                case 'p':
                    print_Player(playerTBL);
                    break;
                case 'd':
                    delete_Player(playerTBL);
                    break;
                default:
                    printf("Invalid command\n");
                    break;
            }
        } else if (cmnd == 'q') {
            printf("Quitting...\n");
            break;
        } else {
            printf("Invalid command\n");
        }
    }
}

void print_help(void) {
    printf("\nEnter a command to perform the following actions: 't' to control teams, 'p' to control players, 'q' to quit");
}
