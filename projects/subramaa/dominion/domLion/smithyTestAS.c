/************
smithy test card
*************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
    printf("--------------------- SMITHY CARD TEST ---------------------\n");
    //int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    //int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &state);

    //initialize game starts us off with each player having a deck of 3 estates, 7 coppers. The first player has 5 cards.
    int currPlayer = whoseTurn(&state);

    //get initial starting vars for curr Player before smithy is called
    int preHandSize = state.handCount[currPlayer];        //get current Player's handSize

    cardEffect(smithy, choice1, choice2, choice3, &state, handpos, &bonus);

    printf("\n");
    printf("------TESTING HAND SIZE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", 8, state.handCount[currPlayer]);
    if (preHandSize + 3 == state.handCount[currPlayer]) {
        printf("HAND SIZE: TEST PASSED\n");
    }
    else
        printf("HAND SIZE: TEST FAILED\n");


}
