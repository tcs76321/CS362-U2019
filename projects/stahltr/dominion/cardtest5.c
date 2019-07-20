#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "drawCard"

int asserttrue(int expr){
	if(expr == 1){printf("\n passed \n\n\n\n");}
	else{printf("\n failed \n\n\n\n");}
	return 0;
}

//drawCard(int player, struct gameState *state)

int main() {
	int remove1, remove2;
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	//init game
	initializeGame(numPlayers, k, seed, &G);
	
	printf("TEST 1:verify that in two player game both players can draw\n");
	//------------- Test 1 ------------------------
	// copy the control game state to the test state
	memcpy(&testG, &G, sizeof(struct gameState));
	int p1d =  testG.deckCount[0];
	int p2d =  testG.deckCount[1];
	int p1h = testG.handCount[0];
	int p2h = testG.handCount[1];
	drawCard(0, &testG);
	drawCard(1, &testG);
	int p1h2 = testG.handCount[0];
	int p2h2 = testG.handCount[1];
	int p1d2 =  testG.deckCount[0];
	int p2d2 =  testG.deckCount[1];
	asserttrue( p1d2 < p1d );
	asserttrue( p2d2 < p2d );
	asserttrue( p1h2 > p1h );
	asserttrue( p2h2 > p2h );
	
	
	
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}