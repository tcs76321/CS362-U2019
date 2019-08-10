#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "tribute"

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
	printf("TEST 1:\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 0;
	int currentPlayer = 0;
	int rrr = testG.discardCount[0];
	testG.supplyCount[estate] = 2;
	int nextPlayer = 1;
	playTribute(&testG, nextPlayer, currentPlayer);
	//tributeF(&testG, currentPlayer, nextPlayer, i);
	//verify that an estate was not removed from supply
	asserttrue(testG.supplyCount[estate] == 2);
	//verify that discard count was not increased
	asserttrue(testG.discardCount[0] == rrr);
	
	
	
	// ----------- TEST 2: --------------
	printf("TEST 2:\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	currentPlayer = 0;
	testG.coins = 1;
	playTribute(&testG, nextPlayer, currentPlayer);
	//tributeF(&testG, currentPlayer, nextPlayer, i);
	printf("\n coins are:%d\n", testG.coins);
	//verify that coins were not increased by 4
	asserttrue(testG.coins == 3);
	
	// ----------- TEST 3: --------------
	printf("TEST 3:\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 0;
	currentPlayer = 0;
	testG.supplyCount[estate] = 2;
	testG.hand[currentPlayer][0] = estate;
	nextPlayer = 1;
	playTribute(&testG, nextPlayer, currentPlayer);
	//tributeF(&testG, currentPlayer, nextPlayer, i);
	//verify there is the right amount of estates
	asserttrue(testG.supplyCount[estate] == 2);
	//verify player still has same introduced estate
	asserttrue(testG.hand[currentPlayer][0] == estate);
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);




	
	return 0;
}