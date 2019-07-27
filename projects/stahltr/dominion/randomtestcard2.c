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
	
	i = 0;
	j = 0;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	
	int numActs = 0;
	
	int counterI = 0;
	
	int completion;
	
	for(n = 0; n < 1000000 ;n++){
		
		seed = floor(Random() * 2000);
		seed = seed + 42;
		numPlayers = floor(Random() * 3);
		numPlayers = numPlayers + 2;
		initializeGame(numPlayers, k, seed, &G);
		p = floor(Random() * numPlayers);//player
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		
		//i = 0;
		//j = 0;
		//handpos = 0;
		//choice2 = 0;
		//choice1 = 0;
		
		if(counterI == 1){
			choice1 = 1;
			choice2 = 0;
			counterI = 0;
		}
		else{
			choice1 = 0;
			choice2 = 1;
			counterI = 1;
		}
		i = 0;
		j = 0;
		handpos = 0;
		G.coins = floor(Random() * 3);
		numActs = G.numActions + 1;
		
		completion = minionF(G, handpos, p, i, j, choice1, choice2);
		
		if(){
			// verify coins is now 2
			asserttrue(G.coins == 2);
		}
		
		// verify that the current player didn't change
		//asserttrue();
		
		// verify that numActions was increased
		asserttrue(G.numActions == numActs);
		

		if(){
			
		}
		else{
			
		}

		//verify that at least returned 0 properly
		asserttrue(completion == 0);

	}
	

	printf("\n\n----- >>>>> SUCCESS: Testing complete %s <<<<< -----\n\n\n\n\n", TESTCARD);
}