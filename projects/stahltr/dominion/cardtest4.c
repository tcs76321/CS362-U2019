#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "getWinners"

int asserttrue(int expr){
	if(expr == 1){printf("\n passed \n\n\n\n");}
	else{printf("\n failed \n\n\n\n");}
	return 0;
}


int main() {
	int remove1, remove2;
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G, testG, testG2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	//init game
	initializeGame(numPlayers, k, seed, &G);

	
	
	//------------- Test 1 ------------------------
	// copy the control game state to the test state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	//manipulate control for expectance of 
	testG.hand[0][0] = curse;
	testG.hand[0][1] = curse;
	testG.hand[0][2] = curse;
	
	testG.discard[0][0] = curse;
	testG.discard[0][1] = curse;
	testG.discard[0][2] = curse;
	
	testG.deck[0][0] = curse;
	testG.deck[0][1] = curse;
	testG.deck[0][2] = curse;
	
	testG.hand[1][0] = province;
	testG.hand[1][1] = province;
	testG.hand[1][2] = province;
	
	testG.discard[1][0] = province;
	testG.discard[1][1] = province;
	testG.discard[1][2] = province;
	
	testG.deck[1][0] = province;
	testG.deck[1][1] = province;
	testG.deck[1][2] = province;
	
	int ap[] = {0, 0};
	getWinners(ap, &testG);
	int player_1 = ap[0];
	int player_2 = ap[1];
	asserttrue(player_2 == 1);
	asserttrue(player_1 == 0);
	
	//------------- Test 2 ------------------------	
	initializeGame(numPlayers+1, k, seed, &testG2);

	
	return 0;
}