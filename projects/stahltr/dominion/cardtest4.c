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

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	
	printf("TEST 1:verify one player can win in two player game\n");
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
	testG.discard[0][1] = curse;
	
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
	
	printf("TEST 2:verify two players can win in three player game\n");
	//------------- Test 2 ------------------------	
	initializeGame(numPlayers+1, k, seed, &testG2);
	
	testG2.hand[0][0] = curse;
	testG2.hand[0][1] = curse;
	testG2.hand[0][2] = curse;
	
	testG2.discard[0][0] = curse;
	testG2.discard[0][1] = curse;
	testG2.discard[0][2] = curse;
	
	testG2.deck[0][0] = curse;
	testG2.deck[0][1] = curse;
	testG2.deck[0][2] = curse;
	
	testG2.hand[1][0] = province;
	testG2.hand[1][1] = province;
	testG2.hand[1][2] = province;
	
	testG2.discard[1][0] = province;
	testG2.discard[1][1] = province;
	testG2.discard[1][2] = province;
	
	testG2.deck[1][0] = province;
	testG2.deck[1][1] = province;
	testG2.deck[1][2] = province;
	
	testG2.hand[2][0] = province;
	testG2.hand[2][1] = province;
	testG2.hand[2][2] = province;
	
	testG2.discard[2][0] = province;
	testG2.discard[2][1] = province;
	testG2.discard[2][2] = province;
	
	testG2.deck[2][0] = province;
	testG2.deck[2][1] = province;
	testG2.deck[2][2] = province;
	
	int ap2[] = {0, 0, 0};
	getWinners(ap2, &testG2);
	int player_12 = ap2[0];
	int player_22 = ap2[1];
	int player_32 = ap2[2];
	asserttrue(player_22 == 1);
	asserttrue(player_12 == 0);
	asserttrue(player_32 == 1);

	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}