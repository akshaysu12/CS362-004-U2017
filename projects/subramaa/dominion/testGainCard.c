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

    for (int i = 0; i < numPlayers; i++) {
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


    // Re-initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &state);

    /***********
    0 Test Results
    ************/

    int notUsedCards[10];
    notUsedCards[0] = 9;
    notUsedCards[1] = 10;
    notUsedCards[2] = 12;
    notUsedCards[3] = 15;
    notUsedCards[4] = 16;
    notUsedCards[5] = 18;
    notUsedCards[6] = 20;
    notUsedCards[7] = 23;
    notUsedCards[8] = 24;
    notUsedCards[9] = 26;
    int notUsedArrItr = 0;

    //For each supplyCard in the game
    //test 1 2 and else test if incremented for currPlayer - deck, hand, discard
    //test that nothing changed for the other players
    for (int i = 0; i < 27; i++) {
      printf("\n");
      printf("-------------------TESTING CARD %d------------------\n", i);
      printf("\n");
      if (i == notUsedCards[notUsedArrItr]) {
        //test try to get card that is not being used in the game
        printf("\n");
        printf("------TESTING CARD NOT USED IN GAME-------\n");
        //test try to get card where supply is 0
        //call gainCard
        int returnVal = gainCard(i, &state, 0, currPlayer);
        printf("Expected Value: %d, ACTUAL VALUE: %d\n", -1, returnVal);
        if (returnVal == -1) {
          printf("INVALID CARD GAIN: TEST PASSED\n");
        }
        else
          printf("INVALID CARD GAIN: TEST FAILED\n");
        notUsedArrItr++;
      }

      else {
        for (int choice = 0; choice < 3; choice++) {
          if (choice == 0) {
            // Re-initialize a game state and player cards
            initializeGame(numPlayers, k, seed, &state);

            //test card that is being used in the game
            printf("\n");
            printf("------TESTING GAIN CARD TO DISCARD-------\n");
            //test try to get card where supply is 0
            //call gainCard
            gainCard(i, &state, choice, currPlayer);
            printf("Expected Value: %d, ACTUAL VALUE: %d\n", preDiscardSize+1, state.discardCount[currPlayer]);
            if (preDiscardSize+1 == state.discardCount[currPlayer]) {
              printf("DISCARD GAIN: TEST PASSED\n");
            }
            else
              printf("DISCARD GAIN: TEST FAILED\n");

          }

          else if (choice == 1) {
            // Re-initialize a game state and player cards
            initializeGame(numPlayers, k, seed, &state);

            //test card that is being used in the game
            printf("\n");
            printf("------TESTING GAIN CARD TO DECK-------\n");
            //test try to get card where supply is 0
            //call gainCard
            gainCard(i, &state, choice, currPlayer);
            printf("Expected Value: %d, ACTUAL VALUE: %d\n", preDeckSize+1, state.deckCount[currPlayer]);
            if (preDeckSize+1 == state.deckCount[currPlayer]) {
              printf("DECK GAIN: TEST PASSED\n");
            }
            else
              printf("DECK GAIN: TEST FAILED\n");
          }

          else {
            // Re-initialize a game state and player cards
            initializeGame(numPlayers, k, seed, &state);

            //test card that is being used in the game
            printf("\n");
            printf("------TESTING GAIN CARD TO HAND-------\n");
            //test try to get card where supply is 0
            //call gainCard
            gainCard(i, &state, choice, currPlayer);
            printf("Expected Value: %d, ACTUAL VALUE: %d\n", preHandSize+1, state.handCount[currPlayer]);
            if (preHandSize+1 == state.handCount[currPlayer]) {
              printf("HAND GAIN: TEST PASSED\n");
            }
            else
              printf("HAND GAIN: TEST FAILED\n");
          }

      }
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
    }
  }
}
