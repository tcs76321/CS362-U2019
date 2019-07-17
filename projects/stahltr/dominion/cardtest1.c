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
	numPlayers = 5;
	int okToRun = 
	
	
	//------------- Test 2 ------------------------
	// copy the control game state to the test state
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("TEST 2:\n");
	
	
	//------------- Test 3 ------------------------
	// copy the control game state to the test state
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("TEST 3:\n");
	
	
	return 0;
}