#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "minion"

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
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 76321;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	
	printf("TEST 1:\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	choice2 = 0;
	i = 0;
	j = 0;
	handpos = 0;
	testG.coins = 0;
	int currentPlayer = 0;
	int numActs = testG.numActions + 1;
	minionF(&testG, handpos, currentPlayer, i, j, choice1, choice2);
	// verify coins is now 2
	asserttrue(testG.coins == 2);
	// verify that the current player didn't change
	asserttrue(currentPlayer == 0);
	//verify i and j were not used
	asserttrue(i == 0);
	asserttrue(j == 0);
	// verify that numActions was increased
	asserttrue(testG.numActions == numActs);

	
	
	printf("\n\n----- >>>>> SUCCESS: Testing complete %s <<<<< -----\n\n\n\n\n", TESTCARD);
}