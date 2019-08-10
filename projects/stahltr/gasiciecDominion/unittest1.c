#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "baron"

int asserttrue(int expr){
	if(expr == 1){printf("\n passed \n\n\n\n");}
	else{printf("\n failed \n\n\n\n");}
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
	printf("TEST 1:If no estate in hand and enough estates left\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 0;
	int currentPlayer = 0;
	int rrr = testG.discardCount[0] + 1;
	testG.supplyCount[estate] = 2;
	int nB = testG.numBuys + 1;
	playBaron(choice1, currentPlayer, &testG);
	//veridy that an estate was removed from supply
	asserttrue(testG.supplyCount[estate] == 1);
	//verify that discard count for player is increased
	asserttrue(testG.discardCount[0] == rrr);
	//verify that numBuys increased
	asserttrue(testG.numBuys == nB);
	
	
	
	// ----------- TEST 2: --------------
	printf("TEST 2:If estate in hand and choose to discard it\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	currentPlayer = 0;
	testG.coins = 1;
	testG.hand[currentPlayer][0] = estate;
	nB = testG.numBuys + 1;
	playBaron(choice1, currentPlayer, &testG);
	printf("\n coins are:%d\n", testG.coins);
	//verify that coins were increased by 4
	asserttrue(testG.coins == 5);
	//verify thatplayer no longer has estate in same place
	asserttrue(testG.hand[currentPlayer][0] != estate);
	//verify that numBuys increased
	asserttrue(testG.numBuys == nB);
	
	// ----------- TEST 3: --------------
	printf("TEST 3:If estate in hand and choose not to discard it\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 0;
	currentPlayer = 0;
	testG.supplyCount[estate] = 2;
	testG.hand[currentPlayer][0] = estate;
	nB = testG.numBuys + 1;
	playBaron(choice1, currentPlayer, &testG);
	//verify there is the right amount of estates
	asserttrue(testG.supplyCount[estate] == 2);
	//verify player still has same introduced estate
	asserttrue(testG.hand[currentPlayer][0] == estate);
	//verify that numBuys increased
	asserttrue(testG.numBuys == nB);
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	
	return 0;
}
	