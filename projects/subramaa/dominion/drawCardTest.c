/********************
drawCard Unit Tests
********************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main() {
    int seed = 1000;
    int numPlayers = 2;
    struct gameState state;
	  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
  	initializeGame(numPlayers, k, seed, &state);

    //initialize game starts us off with each player having a deck of 3 estates, 7 coppers. The first player has 5 cards.
    int currPlayer = whoseTurn(&state);

    /************
    Testing if there are currently cards in the deck to draw from
    ************/

    int preHandSize = state.handCount[currPlayer];        //get current Player's handSize
    //int preDeckSize = state.deckCount[currPlayer];        //get current Player's deckSize

    int cardToAdd = state.deck[currPlayer][state.deckCount[currPlayer]-1];

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

    printf("\n");
    printf("------TESTING CASE 1: CARDS IN DECK TO DRAW FROM -------\n");

    drawCard(currPlayer, &state);
    printf("\n");
    printf("------TESTING HAND SIZE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preHandSize+1, state.handCount[currPlayer]);
    if (preHandSize + 1 == state.handCount[currPlayer]) {
      printf("HAND SIZE: TEST PASSED\n");
    }
    else
      printf("HAND SIZE: TEST FAILED\n");

    printf("\n");
    printf("------TESTING CARD -------\n");
    if (state.hand[currPlayer][state.handCount[currPlayer]-1] == cardToAdd) {
      printf("ADDED CORRECT CARD: TEST PASSED\n");
    }
    else
      printf("ADDED CORRECT CARD: TEST FAILED\n");

      printf("\n");
      printf("------TESTING OTHER PLAYERS VALUES -------\n");
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

    /************
    Set up game such that currPlayer has no cards in deck
    ************/

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &state);

    //initialize game starts us off with each player having a deck of 3 estates, 7 coppers. The first player has 5 cards.
    currPlayer = whoseTurn(&state);

    //move all of the cards from the deck to the discard
    for (int i = 0; i < state.deckCount[currPlayer]; i++) {
      state.discard[currPlayer][state.discardCount[currPlayer]] = state.deck[currPlayer][state.deckCount[currPlayer]-1];
      state.discardCount[currPlayer]++;
    }

    int discardTotal = state.discardCount[currPlayer];
    drawCard(currPlayer, &state);

    printf("\n");
    printf("------TESTING CASE 2: NO CARDS IN DECK TO DRAW FROM -------\n");

    printf("\n");
    printf("------TESTING HAND SIZE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preHandSize+1, state.handCount[currPlayer]);
    if (preHandSize + 1 == state.handCount[currPlayer]) {
      printf("HAND SIZE: TEST PASSED\n");
    }
    else
      printf("HAND SIZE: TEST FAILED\n");

    printf("\n");
    printf("------TESTING DECK SIZE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", state.deckCount[currPlayer]+1, discardTotal);
    if (state.deckCount[currPlayer]+1 == discardTotal) {
      printf("HAND SIZE: TEST PASSED\n");
    }
    else
      printf("HAND SIZE: TEST FAILED\n");

    printf("\n");
    printf("------TESTING OTHER PLAYERS VALUES -------\n");

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

    supplyFail = 0;
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
