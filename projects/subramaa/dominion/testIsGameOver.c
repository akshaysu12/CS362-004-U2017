/********************
drawCard Unit Tests
********************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main() {
    printf("--------------------- TEST IS GAME OVER FUNCTION TEST ---------------------\n");
    int i;
    int seed = 1000;
    int numPlayers = 2;
    struct gameState state;
	  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
  	initializeGame(numPlayers, k, seed, &state);

    state.supplyCount[province] = 10;
    //test a case where at least every supply is 0 and make sure that isGameOver is accurate
    for (i = 0; i < 23; i++) {
      initializeGame(numPlayers, k, seed, &state);
      state.supplyCount[i] = 0;
      state.supplyCount[i+1] = 0;
      state.supplyCount[i+2] = 0;
      int returnVal = isGameOver(&state);
      printf("\n");
      printf("---TESTING END GAME FOR SUPPLYCOUNT %d, %d, %d, = 0 ----\n", i, i+1, i+2);
      if (returnVal == 1) {
        printf("END GAME: TEST PASSED\n");
      }
      else
        printf("END GAME: TEST FAILED\n");

    }
    initializeGame(numPlayers, k, seed, &state);
    state.supplyCount[province] = 0;
    printf("---TESTING END GAME FOR PROVINCE = 0 ----\n");
    int returnVal = isGameOver(&state);
    if (returnVal == 1) {
      printf("END GAME: TEST PASSED\n");
    }
    else
      printf("END GAME: TEST FAILED\n");

}
