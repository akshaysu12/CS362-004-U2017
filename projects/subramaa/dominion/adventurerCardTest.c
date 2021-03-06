/************
Adventurer test card
*************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
  printf("--------------------- ADVENTURER CARD TEST ---------------------\n");
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

    int preHandSize = state.handCount[currPlayer];        //get current Player's handSize
    int preDeckSize = state.deckCount[currPlayer];        //get current Player's deckSize
    int preDiscardSize = state.discardCount[currPlayer];  //get current Player's discardSize

    //array for other players' hand,deck and discard piles
    int otherPlayerHandSizes[numPlayers-1];
    int otherPlayerDeckSizes[numPlayers-1];
    int otherPlayerDiscardSizes[numPlayers-1];

    for (int i = 0; i < numPlayers; i++) {
      if (i != currPlayer) {
        otherPlayerHandSizes[i] = state.handCount[i];
        otherPlayerDeckSizes[i] = state.deckCount[i];
        otherPlayerDiscardSizes[i] = state.discardCount[i];
      }
    }

    //initial starting vars for other players and supply
    int supplyCards[27];                                   //get supplyCard count for all cards
    for (int i = 0; i < 28; i++) {
      supplyCards[i] = state.supplyCount[i];
    }

    cardEffect(adventurer, choice1, choice2, choice3, &state, handpos, &bonus);
    printf("\n");
    printf("------TESTING HAND SIZE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", 7, state.handCount[currPlayer]);
    //handSize should increase by exactly two
    if (preHandSize + 2 == state.handCount[currPlayer]) {
      printf("HAND SIZE: TEST PASSED\n");
    }
    else
      printf("HAND SIZE: TEST FAILED\n");

    printf("\n");
    printf("------TESTING DECK SIZE -------\n");
    //Decksize before must be greater than the deck size after
    if (preDeckSize > state.deckCount[currPlayer]) {
      printf("DECK SIZE: TEST PASSED\n");
    }
    else
      printf("DECK SIZE: TEST FAILED\n");

    printf("\n");
    printf("------TESTING DISCARD SIZE -------\n");
    //discard will have either the same amount of more cards after adventurer cardEffect
    if (preDiscardSize <= state.discardCount[currPlayer]) {
      printf("DISCARD SIZE: TEST PASSED\n");
    }
    else
      printf("DISCARD SIZE: TEST FAILED\n");

    printf("\n");
    printf("------TESTING OTHER PLAYERS -------\n");

    //for all players hand,discard and deck size should not have changed
    for (int i = 0; i < numPlayers; i++) {
      if (i != currPlayer) {
        //test hand size
        if (otherPlayerHandSizes[i] != state.handCount[i]) {
          printf("HAND SIZE: TEST FAILED FOR PLAYER: %d\n",i);
        }
        else
          printf("HAND SIZE: TEST PASSED FOR PLAYER: %d\n",i);

        //test deck size
        if (otherPlayerDeckSizes[i] != state.deckCount[i]) {
          printf("DECK SIZE: TEST FAILED FOR PLAYER: %d\n",i);
        }
        else
          printf("DECK SIZE: TEST PASSED FOR PLAYER: %d\n",i);

        //test discard size
        if (otherPlayerDiscardSizes[i] != state.discardCount[i]) {
          printf("DISCARD SIZE: TEST FAILED FOR PLAYER: %d\n",i);
        }
        else
          printf("DISCARD SIZE: TEST PASSED FOR PLAYER: %d\n",i);

      }
    }
    printf("\n");
    printf("------TESTING SUPPLY CARDS-------\n");

    int supplyFail = 0;
    //the supply cards should not have been affected by playing smithy
    for (int i = 0; i < 28; i++) {
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
