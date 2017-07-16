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

    state->supplyCount[province] = 10;
    for (int i = 0; i < 27; i++) {
      for (int j = 0; j < 27; j++) {
        for (int i = 0; i < 27; i++) {
          /* code */
        }
      }
    }
}
