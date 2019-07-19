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
	struct gameState testG2, testG3, testG4;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	
	
	//------------- Test 1 ------------------------
	initializeGame(numPlayers, k, seed, &testG2);
	printf("TEST 1:verify the player changes in 2 player game\n");
	int ccPP = whoseTurn(&testG2);
	endTurn(&testG2);
	int ccPPafter = whoseTurn(&testG2);
	asserttrue(ccPPafter != ccPP);
	
	//------------- Test 2 ------------------------
	initializeGame(numPlayers+1, k, seed, &testG3);
	printf("TEST 2:verify the player changes in 3 player game\n");
	ccPP = whoseTurn(&testG3);
	endTurn(&testG3);
	ccPPafter = whoseTurn(&testG3);
	asserttrue(ccPPafter != ccPP);
	
	//------------- Test 3 ------------------------
	initializeGame(numPlayers+2, k, seed, &testG4);
	printf("TEST 3:verify the player changes in 4 player game\n");
	ccPP = whoseTurn(&testG4);
	endTurn(&testG4);
	ccPPafter = whoseTurn(&testG4);
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