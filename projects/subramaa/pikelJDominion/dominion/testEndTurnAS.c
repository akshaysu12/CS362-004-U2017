/********************
endTurn Unit Tests
********************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main() {
    printf("--------------------- END TURN FUNCTION TEST ---------------------\n");
    int i;
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
    //int preDeckSize = state.deckCount[currPlayer];        //get current Player's deckSize
    int preDiscardSize = state.discardCount[currPlayer];  //get current Player's discardSize

    int Hand[preHandSize];  //duplicate hand array to check that discard pile is accurate
    for (i = 0; i < preHandSize; i++) {
      Hand[i] = state.hand[currPlayer][i];
    }

    int supplyCards[27];                                   //get supplyCard count for all cards
    for (i = 0; i < 28; i++) {
      supplyCards[i] = state.supplyCount[i];
    }

    int returnVal = endTurn(&state);
    printf("\n");
    printf("------TESTING DISCARD OF CARDS -------\n");
    printf("#Cards Removed from Hand: %d, #Cards Removed added to Discard: %d\n", preHandSize - state.handCount[currPlayer], state.discardCount[currPlayer] - preDiscardSize);
    if (preHandSize - state.handCount[currPlayer] == state.discardCount[currPlayer] - preDiscardSize) {
      printf("DISCARD SIZE: TEST PASSED\n");
    }
    else
      printf("DISCARD SIZE: TEST FAILED\n");

    int discardTest = 0;
    for (i = 0; i < preHandSize; i++) {
      if (Hand[i] != state.discard[currPlayer][i]) {
        discardTest = 1;
        printf("DISCARD CARD CHECK: TEST FAILED\n");
      }
    }
    if (discardTest == 0) {
      printf("DISCARD CARD CHECK: TEST PASSED\n");
    }
    printf("\n");
    printf("------TESTING RETURN VAL -------\n");
    if (returnVal == 0) {
      printf("RETURN VAL CHECK: TEST PASSED\n");
    }
    else
      printf("RETURN VAL CHECK: TEST FAILED\n");
    printf("\n");

    printf("------TESTING TURN INCREMENT -------\n");
    if (currPlayer+1 == whoseTurn(&state)) {
      printf("TURN CHECK: TEST PASSED\n");
    }
    else
      printf("TURN CHECK: TEST FAILED\n");

    printf("\n");
    printf("------TESTING HANDS -------\n");
    if (state.handCount[0] == 0) {
      printf("HAND SIZE: TEST PASSED\n");
    }
    else
      printf("HAND SIZE: TEST FAILED\n");

    int handValsTest = 0;
    for (i = 0; i < 5; i++) {
      if (state.hand[currPlayer][i] != -1) {
        printf("HAND VALUES: TEST FAILED\n");
        handValsTest = 1;
      }
    }
    if (handValsTest == 0) {
      printf("HAND VALUES: TEST PASSED\n");
    }

    currPlayer = whoseTurn(&state);
    if (state.handCount[currPlayer] == 5) {
      printf("HAND SIZE NEXT PLAYER: TEST PASSED\n");
    }
    else
      printf("HAND SIZE NEXT PLAYER: TEST FAILED\n");

      printf("\n");
      printf("------TESTING SUPPLY CARDS-------\n");

    int supplyFail = 0;
    //the supply cards should not have been affected by ending a turn
    for (i = 0; i < 28; i++) {
      if (supplyCards[i] != state.supplyCount[i])
      {
        printf("SUPPLY CARD TEST FAILED\n");
        supplyFail = 1;
      }
    }
    if (supplyFail == 0) {
      printf("SUPPLY CARD TEST PASSED\n");
    }
    printf("\n");



}
