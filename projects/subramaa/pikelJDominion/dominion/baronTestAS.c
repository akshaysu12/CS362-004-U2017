/************
baron test card
*************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
    printf("--------------------- BARON CARD TEST ---------------------\n");
    int i;
    int handpos = 0, choice1 = 1, choice2 = 0, choice3 = 0, bonus = 0;
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
    int preDeckSize = state.deckCount[currPlayer];        //get current Player's deckSize
    int preDiscardSize = state.discardCount[currPlayer];  //get current Player's discardSize
    int preCoins = state.coins;
    int preEstateNumber = state.supplyCount[estate];

    // 1 = discard to Gain, 0 = gain an estate card

    /*************************************
    test discarding estate card when there is one in hand
    *************************************/
    printf("----------TEST: DISCARD ESTATE CARD - CARD IN HAND---------------\n");
    cardEffect(baron, choice1, choice2, choice3, &state, handpos, &bonus);
    //void callBaron(&state, 1, currPlayer);

    //test gain exactly 4 coins
    printf("\n");
    printf("------TESTING COIN INCREASE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preCoins+4, state.coins);
    if (preCoins+4 == state.coins) {
      printf("COIN INCREASE: TEST PASSED\n");
    }
    else
    printf("COIN INCREASE: TEST FAILED\n");

    //test hand size decrease by one
    printf("\n");
    printf("------TESTING HAND SIZE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preHandSize-1, state.handCount[currPlayer]);
    if (preHandSize-1 == state.handCount[currPlayer]) {
      printf("HAND SIZE: TEST PASSED\n");
    }
    else
    printf("HAND SIZE: TEST FAILED\n");

    //test deck is does not change
    printf("\n");
    printf("------TESTING DECK SIZE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preDeckSize, state.deckCount[currPlayer]);
    if (preDeckSize == state.deckCount[currPlayer]) {
      printf("DECK SIZE: TEST PASSED\n");
    }
    else
    printf("DECK SIZE: TEST FAILED\n");

    //test estate supply cound has not changed
    printf("\n");
    printf("------TESTING ESTATE SUPPLY -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preEstateNumber, state.supplyCount[estate]);
    if (preEstateNumber == state.supplyCount[estate]) {
      printf("ESTATE SUPPLY: TEST PASSED\n");
    }
    else
    printf("ESTATE SUPPLY: TEST FAILED\n");

    /*********************************************
    test discarding estate card when there are none in hand
    *********************************************/
    printf("----------TEST: DISCARD ESTATE CARD - CARD NOT IN HAND---------------\n");
    // re-initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &state);

    //remove any estate card from players hand - easy way is just to discard all cards from hand

    //Discard hand
    for (i = 0; i < state.handCount[currPlayer]; i++){
      state.discard[currPlayer][state.discardCount[currPlayer]++] = state.hand[currPlayer][i];//Discard
      state.hand[currPlayer][i] = -1;//Set card to -1
    }
    state.handCount[currPlayer] = 0;//Reset hand count

    int newHandSize = state.handCount[currPlayer];        //get current Player's handSize
    int newDiscardSize = state.discardCount[currPlayer];  //get current Player's discardSize

    cardEffect(baron, choice1, choice2, choice3, &state, handpos, &bonus);

    //test coins remain the same
    printf("\n");
    printf("------TESTING COINS -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preCoins, state.coins);
    if (preCoins == state.coins) {
      printf("COIN INCREASE: TEST PASSED\n");
    }
    else
    printf("COIN INCREASE: TEST FAILED\n");

    //test hand size remains the same
    printf("\n");
    printf("------TESTING HAND SIZE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", newHandSize, state.handCount[currPlayer]);
    if (newHandSize == state.handCount[currPlayer]) {
      printf("HAND SIZE: TEST PASSED\n");
    }
    else
    printf("HAND SIZE: TEST FAILED\n");

    //test discard size remains same
    printf("\n");
    printf("------TESTING DISCARD SIZE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", newDiscardSize, state.discardCount[currPlayer]);
    if (newDiscardSize == state.discardCount[currPlayer]) {
      printf("DISCARD SIZE: TEST PASSED\n");
    }
    else
    printf("DISCARD SIZE: TEST FAILED\n");

    //test deck increases by one
    printf("\n");
    printf("------TESTING DECK SIZE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preDeckSize+1, state.deckCount[currPlayer]);
    if (preDeckSize+1 == state.deckCount[currPlayer]) {
      printf("DECK SIZE: TEST PASSED\n");
    }
    else
    printf("DECK SIZE: TEST FAILED\n");

    //test that the top of the deck is now an estate
    printf("\n");
    printf("------TESTING TOP OF DECK FOR ESTATE CARD -------\n");
    if (estate == state.deck[currPlayer][state.deckCount[currPlayer]-1]) {
      printf("DECK CARD: TEST PASSED\n");
    }
    else
    printf("DECK CARD: TEST FAILED\n");

    //test estate SupplyCount has decremented
    printf("\n");
    printf("------TESTING ESTATE SUPPLY -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preEstateNumber-1, state.supplyCount[estate]);
    if (preEstateNumber-1 == state.supplyCount[estate]) {
      printf("ESTATE SUPPLY: TEST PASSED\n");
    }
    else
    printf("ESTATE SUPPLY: TEST FAILED\n");

    /*************************
    test gainining estate card
    *************************/
    printf("----------TEST: GAIN ESTATE CARD ---------------\n");

    // re-initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &state);
    choice1 = 0;
    cardEffect(baron, choice1, choice2, choice3, &state, handpos, &bonus);
    //test coins remain the same
    printf("\n");
    printf("------TESTING COINS -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preCoins, state.coins);
    if (preCoins == state.coins) {
      printf("COIN INCREASE: TEST PASSED\n");
    }
    else
    printf("COIN INCREASE: TEST FAILED\n");

    //test hand size remains the same
    printf("\n");
    printf("------TESTING HAND SIZE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preHandSize, state.handCount[currPlayer]);
    if (preHandSize == state.coins) {
      printf("HAND SIZE: TEST PASSED\n");
    }
    else
    printf("HAND SIZE: TEST FAILED\n");

    //test discard size remains same
    printf("\n");
    printf("------TESTING DISCARD SIZE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preDiscardSize+1, state.discardCount[currPlayer]);
    if (preDiscardSize == state.discardCount[currPlayer]) {
      printf("DISCARD SIZE: TEST PASSED\n");
    }
    else
    printf("DISCARD SIZE: TEST FAILED\n");

    //test deck increases by one
    printf("\n");
    printf("------TESTING DECK SIZE -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preDeckSize+1, state.deckCount[currPlayer]);
    if (preDeckSize+1 == state.deckCount[currPlayer]) {
      printf("DECK SIZE: TEST PASSED\n");
    }
    else
    printf("DECK SIZE: TEST FAILED\n");

    //test that the top of the deck is now an estate
    printf("\n");
    printf("------TESTING TOP OF DECK FOR ESTATE CARD -------\n");
    if (estate == state.deck[currPlayer][state.deckCount[currPlayer]-1]) {
      printf("DECK CARD: TEST PASSED\n");
    }
    else
    printf("DECK CARD: TEST FAILED\n");

    //test estate SupplyCount has decremented
    printf("\n");
    printf("------TESTING ESTATE SUPPLY -------\n");
    printf("Expected Value: %d, ACTUAL VALUE: %d\n", preEstateNumber-1, state.supplyCount[estate]);
    if (preEstateNumber-1 == state.supplyCount[estate]) {
      printf("ESTATE SUPPLY: TEST PASSED\n");
    }
    else
    printf("ESTATE SUPPLY: TEST FAILED\n");

}
