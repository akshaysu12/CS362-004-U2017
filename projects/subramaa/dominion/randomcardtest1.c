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

void checkSmithyCard(int p, struct gameState *post) {
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  int r;
  //  printf ("drawCard PRE: p %d HC %d DeC %d DiC %d\n",
  //	  p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);

  callSmithy(post, p, 0);

  //printf ("drawCard POST: p %d HC %d DeC %d DiC %d\n",
  //      p, post->handCount[p], post->deckCount[p], post->discardCount[p]);

  pre.handCount[p] = pre.handCount[p] + 3;
  pre.deckCount[p] = pre.deckCount[p] - 3;

  if (pre.handCount[p] != post->handCount[p]) {
    printf("HAND INCREASE -- TEST FAILED\n");
  }

  if (pre.deckCount[p] != post->deckCount[p]) {
    printf("DECK DECREASE -- TEST FAILED\n");
  }

  int supplyFail = 0;
  //the supply cards should not have been affected by playing smithy
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

  int i, n, r, p, deckCount, discardCount, handCount;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

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
    G.playedCards[p] = floor(Random() * MAX_DECK);
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    checkSmithyCard(p, &G);
  }

  printf ("ALL TESTS OK\n");
  return 0;
}
