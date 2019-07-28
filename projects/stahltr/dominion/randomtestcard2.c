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
	printf("\nstop1\n");
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
			
	//printf("\nstop2\n");
	
	i = 0;
	j = 0;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	
	int numActsP = 0;
	int dC = 0;
	int counterI = 1;
	int handC = 0;
	int completion;
	int cC = 0;
	int errorC = 0;
	
	//printf("\nstop3\n");
	
	for(n = 0; n < 100000 ;n++){
		//printf("\nstop4\n");
		//randomization
		seed = floor(Random() * 2000);
		seed = seed + 42;

		initializeGame(numPlayers, k, seed, &G);
		//printf("\nstop5\n");
		
		p = floor(Random() * numPlayers);//player
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		if(G.handCount[p] == 4){
			G.handCount[p] = 3;
		}
		
		//record some stuff
		dC = G.discardCount[p];
		handC = G.handCount[p];
		
		//check state
		//choice is not randomized but switched back and forth to divide half of tests to each branch
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
		
		//slight randomization and control of variables
		i = 0;
		j = 0;
		handpos = 0;
		G.coins = floor(Random() * 3);
		cC = G.coins;
		numActsP = G.numActions + 1;
		//printf("\nstop6\n");
		//run function and save return value
		completion = minionF(&G, handpos, p, i, j, choice1, choice2);//minionF(struct gameState *state, int handPos, int currentPlayer, int i, int j, int choice1, int choice2)
		//printf("\nstop7\n");
	//asserts / 'oracle area'
		//
		if(choice1 == 1){//coins + 2
			asserttrue(cC+2 == G.coins);
			asserttrue(handC == G.handCount[p]);
			asserttrue(dC == G.discardCount[p]);
		}
		else if(choice2 == 1){//choice2 crazy stuff
			asserttrue(G.handCount[p] == 4);//this line ensures that the right number of cards are in hand AND that hand is discarded because I set the players handCount to always be NOT 4
			//asserttrue();
		}
		else{
			printf("\nError\n");
			errorC++;
		}
		//printf("\nstop8\n");
		//verify that actions increased by 1
		asserttrue(numActsP == G.numActions);

		//verify that at least returned 0 properly
		asserttrue(completion == 0);
		
		//printf("\nstop9\n");
	}
	
	printf("\ntotal errors:%d", errorC);
	printf("\n\n----- >>>>> SUCCESS: Testing complete %s <<<<< -----\n\n\n\n\n", TESTCARD);
}