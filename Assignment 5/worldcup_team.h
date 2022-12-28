#include <stdio.h>

struct teamNode {   //structure to hold team information
    int teamCode;   //team code
    char teamName[25];  //team name
    char teamSeed[3];   //  team seed
    char kitColour[7]; //team kit colour
    struct teamNode *next;  //pointer to next team
};
typedef struct teamNode teamNode;   //array to hold all teams

extern void new_Team(teamNode **sPtr);
extern void search_Team(teamNode **sPtr);
extern void update_Team(teamNode **sPtr);
extern void print_Team(teamNode **sPtr);
extern void delete_Team(teamNode **sPtr);
