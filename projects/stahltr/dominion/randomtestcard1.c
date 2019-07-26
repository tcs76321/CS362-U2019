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
	int n, i, p, pp, rrr, nB, CC;
	struct gameState G, testG;
	for(n = 0; n < 10000 ;n++){
		for(i = 0; i < sizeof(struct gameState) ;i++){
			((char*)&G)[i] = floor(Random() * 256);
		}
		p = floor(Random() * 1);
		pp = floor(Random() * 1);
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		rrr = G.discardCount[0] + 1;
		G.supplyCount[estate] = 2;
		nB = G.numBuys + 1;
		G.coins = floor(Random() * 5);
		CC = G.coins;
		baronF(pp, &testG, p);
		//verify that numBuys increased
		asserttrue(G.numBuys == nB);
		if(pp == 0){
			//if not going to discard in first place
			
		}
		else{
			//if discarding
			
		}
	}
	
	printf("\n\n----- >>>>> SUCCESS: Testing complete %s <<<<< -----\n\n\n\n\n", TESTCARD);
}