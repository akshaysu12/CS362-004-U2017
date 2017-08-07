/********************
drawCard Unit Tests
********************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main() {
    printf("--------------------- TEST GAIN CARD FUNCTION TEST ---------------------\n");
    int i;
    int seed = 1000;
    int numPlayers = 2;
    struct gameState state;
	  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
  	initializeGame(numPlayers, k, seed, &state);

    //initialize game starts us off with each player having a deck of 3 estates, 7 coppers. The first player has 5 cards.
    int currPlayer = whoseTurn(&state);

    //get initial starting vars for curr Player
    int preHandSize = state.handCount[currPlayer];        //get current Player's handSize
    int preDeckSize = state.deckCount[currPlayer];        //get current Player's deckSize
    int preDiscardSize = state.discardCount[currPlayer];  //get current Player's discardSize

    int returnVal;  //will hold the returnVal to check

    //array for other players' hand,deck and discard piles
    int otherPlayerHandSizes[numPlayers-1];
    int otherPlayerDeckSizes[numPlayers-1];
    int otherPlayerDiscardSizes[numPlayers-1];

    for (i = 0; i < numPlayers; i++) {
      if (i != currPlayer) {
        otherPlayerHandSizes[i] = state.handCount[i];
        otherPlayerDeckSizes[i] = state.deckCount[i];
        otherPlayerDiscardSizes[i] = state.discardCount[i];
      }
    }

    /***********
    -1 Test Results
    ***********/

    //int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)

    printf("\n");
    printf("------TESTING EMPTY SUPPLY ------\n");
    state.supplyCount[7] = 0;

    //test try to get card where supply is 0
    //call gainCard
    returnVal = gainCard(7, &state, 0, currPlayer);
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", -1, returnVal);
    if (returnVal == -1) {
      printf("EMPTY SUPPLY GAIN CARD: TEST PASSED\n");
    }
    else
      printf("EMPTY SUPPLY GAIN CARD: TEST FAILED\n");

}
