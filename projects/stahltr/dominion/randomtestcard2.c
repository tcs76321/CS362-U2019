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

	int n, i, p, pp, rrr, nB, CC;
	int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	
	for(n = 0; n < 1000000 ;n++){
		seed = floor(Random() * 2000);
		seed = seed + 42;
		numPlayers = floor(Random() * 3);
		numPlayers = numPlayers + 2;
		initializeGame(numPlayers, k, seed, &G);
		p = floor(Random() * numPlayers);//player
		pp = floor(Random() * 2);//choice
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		rrr = G.discardCount[p] + 1;//variable for discard
		G.supplyCount[estate] = 2;
		nB = G.numBuys + 1;
		G.coins = floor(Random() * 5);
		CC = G.coins;

	}
	

	printf("\n\n----- >>>>> SUCCESS: Testing complete %s <<<<< -----\n\n\n\n\n", TESTCARD);
}