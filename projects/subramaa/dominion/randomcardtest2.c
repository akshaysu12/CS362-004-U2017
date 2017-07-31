#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

void checkCouncil_RoomCard(int p, struct gameState *post) {
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  callCouncil_Room(post, p, 0);

  pre.handCount[0] = pre.handCount[0] + 3;
  pre.deckCount[0] = pre.deckCount[0] - 4;
  pre.numBuys = pre.numBuys + 1;

  pre.handCount[1] = pre.handCount[1] + 1;
  pre.deckCount[1] = pre.deckCount[1] - 1;

  if (pre.handCount[0] != post->handCount[0]) {
    printf("HAND INCREASE -- TEST FAILED\n");
  }

  if (pre.deckCount[0] != post->deckCount[0]) {
    printf("DECK DECREASE -- TEST FAILED\n");
  }

  if (pre.discardCount[0] != post->discardCount[0]) {
    printf("HAND DISCARD -- TEST FAILED\n");
  }

  if (pre.numBuys != post->numBuys) {
    printf("BUYS INCREASE TEST FAILED\n");
  }

  if (pre.handCount[1] != post->handCount[1]) {
    printf("OTHER PLAYER HAND INCREASE -- TEST FAILED\n");
  }

  if (pre.deckCount[1] != post->deckCount[1]) {
    printf("OTHER PLAYER DECK DECREASE -- TEST FAILED\n");
  }


  int supplyFail = 0;
  //the supply cards should not have been affected by playing smithy
  int i;
  for (i = 0; i < 28; i++) {
    if (pre.supplyCount[i] != post->supplyCount[i])
    {
      supplyFail = 1;
    }
  }
  if (supplyFail == 1) {
    printf("SUPPLY CARD TEST FAILED\n");
  }
}

int main () {

  int i, n, p;

  struct gameState G;

  printf ("Testing drawCard.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    p = floor(Random() * 2);
    G.playedCardCount = floor(Random() * MAX_DECK);
    G.deckCount[0] = floor(Random() * MAX_DECK);
    G.discardCount[0] = floor(Random() * MAX_DECK);
    G.handCount[0] = floor(Random() * MAX_HAND);
    G.deckCount[1] = floor(Random() * MAX_DECK);
    G.discardCount[1] = floor(Random() * MAX_DECK);
    G.handCount[1] = floor(Random() * MAX_HAND);
    G.numPlayers = 2;
    checkCouncil_RoomCard(0, &G);
  }
  return 0;
}
