#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "shuffle"

int asserttrue(int expr){
	if(expr == 1){printf("\n passed \n\n\n\n");}
	else{printf("\n failed \n\n\n\n");}
	return 0;
}


int main() {
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	//init game
	initializeGame(numPlayers, k, seed, &G);
	
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	
	//------------- Test 1 ------------------------
	// copy the control game state to the test state
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("TEST 1: Verify the first five cards in hand are not at all the same\n");
	int currentPlayer = 0;
	shuffle(currentPlayer, &testG);
	int counterII = 0;
	int numTestss = 5;
	int ii;
	for(ii = 0; ii < numTestss ;ii++){
		if(testG.hand[currentPlayer][ii] == G.hand[currentPlayer][ii]){
			printf("Same - uh oh\n");
			counterII++;
		}
	}
	asserttrue(counterII < numTestss);
	
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	
	return 0;
}