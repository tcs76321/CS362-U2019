#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "endTurn"

int asserttrue(int expr){
	if(expr == 1){printf("\n passed \n\n\n\n");}
	else{printf("\n failed \n\n\n\n");}
	return 0;
}


int main() {
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G, testG, testG3, testG4;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	//init game
	initializeGame(numPlayers, k, seed, &G);
	
	
	//------------- Test 1 ------------------------
	// copy the control game state to the test state
	initializeGame(numPlayers, k, seed, &testG4);
	printf("TEST 3:verify the player changes in 4 player game\n");
	int ccPP = whoseTurn(&G);
	endTurn(&testG);
	int ccPPafter = whoseTurn(&testG);
	asserttrue(ccPPafter != ccPP);
	
	
	//------------- Test 2 ------------------------

	initializeGame(numPlayers, (k+1), seed, &testG3);
	printf("TEST 2:verify the player changes in 3 player game\n");
	ccPP = whoseTurn(&G);
	endTurn(&testG);
	ccPPafter = whoseTurn(&testG);
	asserttrue(ccPPafter != ccPP);
	
	
	//------------- Test 3 ------------------------

	initializeGame(numPlayers, (k+2), seed, &testG4);
	printf("TEST 3:verify the player changes in 4 player game\n");
	ccPP = whoseTurn(&G);
	endTurn(&testG);
	ccPPafter = whoseTurn(&testG);
	asserttrue(ccPPafter != ccPP);
	
	
	
	
	return 0;
}

/*

unittestresults: unitTest1 unitTest3 unitTest4 unitTest5 dominion.o
    echo "unittest1 BEGIN:" >> unittestresults.out
	unitTest1 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out


*/