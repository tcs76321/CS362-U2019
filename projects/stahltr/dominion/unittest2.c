#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "minion"

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
	printf("TEST 1: When choose to take 2 coins\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	choice2 = 0;
	i = 0;
	j = 0;
	handPos = 0;
	testG.coins = 0;
	int currentPlayer = 0;
	int numActs = testG.numActions + 1;
	minionF(&testG, handPos, currentPlayer, i, j, choice1, choice2);
	asserttrue(testG.coins == 2);
	asserttrue(currentPlayer == 0);
	asserttrue(i == 0);
	asserttrue(j == 0);
	asserttrue(testG.numActions == numActs);
	
	
	// ----------- TEST 2: --------------
	printf("TEST 2: When choice is to discard and draw 4 cards\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 0;
	choice2 = 1;
	currentPlayer = 0;
	testG.coins = 0;
	numActs = testG.numActions + 1;
	minionF(&testG, handPos, currentPlayer, i, j, choice1, choice2)
	asserttrue(testG.coins == 0);
	asserttrue(currentPlayer == 0);
	asserttrue(testG.numActions == numActs);
	
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	
	return 0;
}