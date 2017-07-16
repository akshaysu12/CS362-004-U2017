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

    //get initial starting vars for curr Player before smithy is called
    int preHandSize = state.handCount[currPlayer];        //get current Player's handSize
    int preDeckSize = state.deckCount[currPlayer];        //get current Player's deckSize
    int preDiscardSize = state.discardCount[currPlayer];  //get current Player's discardSize

    /***********
    -1 Test Results
    ***********/

    //test try to get card where supply is 0

    //test try to get card that is not being used in the game

    /***********
    0 Test Results
    ************/

    //For each supplyCard in the game
    //test 1 2 and else test if incremented for currPlayer - deck, hand, discard
    //test that nothing changed for the other players
}
