#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "baron"

int asserttrue(int expr){
	if(expr == 1){printf("\npassed\n");}
	else{printf("\nfailed \n");}
	return 0;
}


int main() {
	printf("\n\n\n\n\n\n----------------- Random Testing Card: %s ----------------\n\n", TESTCARD);
	
	int newCards = 0;
    int discarded = 0;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 76321;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	// ----------- TEST 1: --------------
	printf("TEST 1:\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	
	
	choice1 = 0;
	int currentPlayer = 0;
	int rrr = testG.discardCount[0] + 1;
	testG.supplyCount[estate] = 2;
	int nB = testG.numBuys + 1;
	baronF(choice1, &testG, currentPlayer);
	//veridy that an estate was removed from supply
	asserttrue(testG.supplyCount[estate] == 1);
	//verify that discard count for player is increased
	asserttrue(testG.discardCount[0] == rrr);
	//verify that numBuys increased
	asserttrue(testG.numBuys == nB);
	
	
	printf("\n\n----- >>>>> SUCCESS: Testing complete %s <<<<< -----\n\n\n\n\n", TESTCARD);
}