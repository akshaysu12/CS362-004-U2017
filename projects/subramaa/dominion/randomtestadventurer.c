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

void checkAdventurerCard(int p, struct gameState *post) {
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));
  int temphand[MAX_HAND];
  callAdventurer(post, p, temphand);

  pre.handCount[p] = pre.handCount[p] + 2;

  if (pre.handCount[p] != post->handCount[p]) {
    printf("HAND INCREASE TEST FAILED\n");
  }

  int supplyFail = 0;
  //the supply cards should not have been affected by playing adventurer
  for (int i = 0; i < 28; i++) {
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

  int i, n, p, m;

  struct gameState G;

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    p = floor(Random() * 2);
    G.playedCardCount = floor(Random() * MAX_DECK);
    G.deckCount[p] = floor(Random() * MAX_DECK + 5);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);

    for (m = 0; m < 5; m++) {
      G.deck[p][m] = floor(Random() * 3 + 4);
    }
    checkAdventurerCard(p, &G);
  }

  printf ("ALL TESTS OK\n");
  return 0;
}
