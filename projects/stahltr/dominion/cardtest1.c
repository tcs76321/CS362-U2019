#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "initializeGame"

int asserttrue(int expr){
	if(expr == 1){printf("\n passed \n");}
	else{printf("\n failed \n");}
	return 0;
}

//Citation: I tried to stay unique but this is very much inspired by the hint my teacher Wendy Roberts gave me
int main() {
	int remove1, remove2;
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	//init game
	initializeGame(numPlayers, k, seed, &G);
	
	
	//------------- Test 1 ------------------------
	// copy the control game state to the test state
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("TEST 1: Verify there cannot be no players, or 0 players that is\n");
	numPlayers = 0;
	int okToRun = initializeGame(numPlayers, k, seed, &testG);
	asserttrue(okToRun == -1);
	
	
	//------------- Test 2 ------------------------
	// copy the control game state to the test state
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("TEST 2: Verify that if 9 kingdom cards, something other than 10 that is, not okay to run\n");
	int kDup[9] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, smithy, council_room};
	okToRun = initializeGame(numPlayers, kDup, seed, &testG);
	asserttrue(okToRun == -1);
	
	//------------- Test 3 ------------------------
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("TEST 2: Verify that if 11 kingdom cards, something other than 10 that is, not okay to run\n");
	int kDup2[11] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, smithy, council_room, ambassador};
	okToRun = initializeGame(numPlayers, kDup2, seed, &testG);
	asserttrue(okToRun == -1);
	
	
	return 0;
}