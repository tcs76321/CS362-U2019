#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "ambassador"

int asserttrue(int expr){
	if(expr == 1){printf("\n passed \n");}
	else{printf("\n failed \n");}
	return 0;
}


int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: --------------
	printf("TEST 1: \n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	choice2 = 0;
	i = 0;
	j = 0;
	handpos = 0;
	int currentPlayer = 0;
	int mmm = testG.numActions;
	ambassadorF(&testG, choice1, choice2, handPos, currentPlayer, i, j);
	// verify that the current player didn't change
	asserttrue(currentPlayer == 0);
	//verify that numActions was unchanged
	asserttrue(testG.numActions == mmm);
	
	// ----------- TEST 2: --------------
	printf("TEST 2: When choice is to discard and draw 4 cards\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 0;
	choice2 = 1;
	currentPlayer = 0;
	testG.coins = 0;
	numActs = testG.numActions;
	ambassadorF(&testG, choice1, choice2, handPos, currentPlayer, i, j);	
	// verify that the coins are still 0
	asserttrue(testG.coins == 0);
	// verify that the current player didn't change
	asserttrue(currentPlayer == 0);
	// verify that numActions was NOT increased
	asserttrue(testG.numActions == numActs);

	
	return 0;
}