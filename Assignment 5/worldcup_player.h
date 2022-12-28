#include <stdio.h>
#include <stdlib.h>

struct playerNode {
    int playerID;
    char playerName[50];
    int playerAge;
    char playerClub[50];
    struct playerNode *nextPlayerPtr;
};
typedef struct playerNode playerNode;

extern void new_Player(playerNode **sPtr);

extern void search_Player(playerNode **sPtr);

extern void update_Player(playerNode **sPtr);

extern void print_Player(playerNode **sPtr);

extern void delete_Player(playerNode **sPtr);
