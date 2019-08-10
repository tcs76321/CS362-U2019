#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "tribute"

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
	
	int completion = 1;
	int dc1, ds1, hc1, dc2, ds2, hc2;
	int currentPlayer = 0;
	int	nextPlayer = 1;
	
	int shtuff[7] = {curse, tribute, baron, copper, silver, estate, duchy};
	
	int npR1, npR2;
	int coinRec, cardRecCP, cardRecNP, actRec;
	
	for(n = 0; n < 100000 ;n++){
		//randomize seed
		seed = floor(Random() * 2000);
		seed = seed + 42;
		
		initializeGame(numPlayers, k, seed, &G);
		
		//randomize things
		G.deckCount[1] = floor(Random() * MAX_DECK);
		G.discardCount[1] = floor(Random() * MAX_DECK);
		G.handCount[1] = floor(Random() * MAX_HAND);
		G.deckCount[0] = floor(Random() * MAX_DECK);
		G.discardCount[0] = floor(Random() * MAX_DECK);
		G.handCount[0] = floor(Random() * MAX_HAND);
		
		G.whoseTurn = currentPlayer;
		
		//record things
		/*dc1 = G.deckCount[1];
		ds1 = G.discardCount[1];
		hc1 = G.handCount[1];
		dc0 = G.deckCount[0];
		ds0 = G.discardCount[0];
		hc0 = G.handCount[0];*/
		
		coinRec = G.coins;
		cardRecCP = G.handCount[currentPlayer];
		cardRecNP = G.deckCount[nextPlayer];
		actRec = G.numActions;
		
		//randomly assign and then record the contents of nextPlayer hand
		G.deck[nextPlayer][0] = shtuff[(int)(floor(Random() * 4))];
		G.deck[nextPlayer][1] = shtuff[(int)(floor(Random() * 4))];
		npR1 = G.deck[nextPlayer][0];
		npR2 = G.deck[nextPlayer][1];
		
		//run and record return
		//completion = tributeF(&G, currentPlayer, nextPlayer, i);
		completion = playTribute(&G, nextPlayer, currentPlayer);
		
		//oracle area with asserts
		//assure that recorded random assigned cards indicate that what happened is correct
		if((npR1 == copper) || npR2 == copper){
			asserttrue(coinRec + 1 < G.coins);
			coinRec = coinRec + 2;
			if((npR1 == silver) || npR2 == silver){
				asserttrue(coinRec + 1 < G.coins);
			}
		}
		else if((npR1 == silver) || npR2 == silver){
			asserttrue(coinRec + 1 < G.coins);
		}
		
		if((npR1 == tribute)||(npR2 == tribute)){
			asserttrue(actRec+1 < G.numActions);
			actRec = actRec + 2;
			if((npR2 == baron)||(npR1 == baron)){
				asserttrue(actRec+1 < G.numActions);
			}
		}
		else if((npR2 == baron)||(npR1 == baron)){
			asserttrue(actRec+1 < G.numActions);
		}
		
		if((npR1 == estate)||(npR2 == estate)){
			asserttrue(cardRecCP+1 < G.handCount[currentPlayer]);
			cardRecCP = cardRecCP + 2;
			if((npR1 == duchy)||(npR2 == duchy)){
				asserttrue(cardRecCP+1 < G.handCount[currentPlayer]);
			}
		}
		else if((npR1 == duchy)||(npR2 == duchy)){
			asserttrue(cardRecCP+1 < G.handCount[currentPlayer]);
		}
		
		asserttrue((G.deckCount[nextPlayer] == cardRecNP-2) || (cardRecNP<2));
		asserttrue(completion == 0);
		
		//alternate player values
		if(currentPlayer == 0){
			currentPlayer = 1;
			nextPlayer = 0;
		}
		else{
			currentPlayer = 0;
			nextPlayer = 1;
		}
	}
	

	printf("\n\n----- >>>>> SUCCESS: Testing complete %s <<<<< -----\n\n\n\n\n", TESTCARD);
}