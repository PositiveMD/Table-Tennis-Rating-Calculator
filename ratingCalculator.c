#include "ratingCalculator.h"

void initializeBracketValueTable(){

	bracketValueTable[BRACKET1].expectedResult = 8;
	bracketValueTable[BRACKET1].upsetResult = 8;

	bracketValueTable[BRACKET2].expectedResult = 7;
	bracketValueTable[BRACKET2].upsetResult = 10;

	bracketValueTable[BRACKET3].expectedResult = 6;
	bracketValueTable[BRACKET3].upsetResult = 13;

	bracketValueTable[BRACKET4].expectedResult = 5;
	bracketValueTable[BRACKET4].upsetResult = 16;

	bracketValueTable[BRACKET5].expectedResult = 4;
	bracketValueTable[BRACKET5].upsetResult = 20;

	bracketValueTable[BRACKET6].expectedResult = 3;
	bracketValueTable[BRACKET6].upsetResult = 25;

	bracketValueTable[BRACKET7].expectedResult = 2;
	bracketValueTable[BRACKET7].upsetResult = 30;

	bracketValueTable[BRACKET8].expectedResult = 2;
	bracketValueTable[BRACKET8].upsetResult = 35;

	bracketValueTable[BRACKET9].expectedResult = 1;
	bracketValueTable[BRACKET9].upsetResult = 40;

	bracketValueTable[BRACKET10].expectedResult = 1;
	bracketValueTable[BRACKET10].upsetResult = 45;

	bracketValueTable[BRACKET11].expectedResult = 0;
	bracketValueTable[BRACKET11].upsetResult = 50;

}

int getOpponentELO(int opponentNumber){

	int playerElo = -1;

	while (playerElo <= 0){

		printf("\nPlease enter the rating (greater than 0) for Opponent %d: ", opponentNumber);
		scanf("%d", &playerElo);
	}


	return playerElo;

}

int max (int a, int b){

	return (a > b ? a : b);
}

void determineBracket (int* player1Pool, int higherRatedPlayer, int playerRatingDifference, int winner){

	//Bracket 1
	if (playerRatingDifference >= 0 && playerRatingDifference <= 12)
	{	
		determineNewRating(player1Pool, higherRatedPlayer, winner, BRACKET1);
	}
	//Bracket 2
	else if (playerRatingDifference >= 13 && playerRatingDifference <= 37)
	{
		determineNewRating(player1Pool, higherRatedPlayer, winner, BRACKET2);
	}
	//Bracket 3
	else if (playerRatingDifference >= 38 && playerRatingDifference <= 62)
	{
		determineNewRating(player1Pool, higherRatedPlayer, winner, BRACKET3);
	}
	else if (playerRatingDifference >= 63 && playerRatingDifference <= 87)
	{
		determineNewRating(player1Pool, higherRatedPlayer, winner, BRACKET4);
	}
	else if (playerRatingDifference >= 88 && playerRatingDifference <= 112)
	{
		determineNewRating(player1Pool, higherRatedPlayer, winner, BRACKET5);
	}
	else if (playerRatingDifference >= 113 && playerRatingDifference <= 137)
	{
		determineNewRating(player1Pool, higherRatedPlayer, winner, BRACKET6);
	}
	else if (playerRatingDifference >= 138 && playerRatingDifference <= 162)
	{
		determineNewRating(player1Pool, higherRatedPlayer, winner, BRACKET7);
	}
	else if (playerRatingDifference >= 163 && playerRatingDifference <= 187)
	{
		determineNewRating(player1Pool, higherRatedPlayer, winner, BRACKET8);
	}
	else if (playerRatingDifference >= 188 && playerRatingDifference <= 212)
	{
		determineNewRating(player1Pool, higherRatedPlayer, winner, BRACKET9);
	}
	else if (playerRatingDifference >= 213 && playerRatingDifference <= 237)
	{
		determineNewRating(player1Pool, higherRatedPlayer, winner, BRACKET10);
	}
	else
	{	
		determineNewRating(player1Pool, higherRatedPlayer, winner, BRACKET11);
	}


}

void determineNewRating (int* player1Pool, int higherRatedPlayer, int winner, int bracketNumber){

	if (winner == higherRatedPlayer){

		if (higherRatedPlayer == PLAYER1){

			*player1Pool += bracketValueTable[bracketNumber].expectedResult;
			
		}

		else{

			
			*player1Pool -= bracketValueTable[bracketNumber].expectedResult;

		}
	}

	else{

		if (higherRatedPlayer == PLAYER1){

			*player1Pool -= bracketValueTable[bracketNumber].upsetResult;
			

		}

		else{

			
			*player1Pool += bracketValueTable[bracketNumber].upsetResult;
		}

		
	}


} 

int getPlayerOriginalELO()
{
	int playerElo = -1;

	while(playerElo <= 0){

		printf("What is your rating? (enter a number greater than 0): ");
		scanf("%d", &playerElo);
	}

	return playerElo;

}


int main (int argc, char *argv[]){

	int player1ELO;
	int player2ELO;
	int higherRatedPlayer;
	int playerRatingDifference;
	int winner;
	int gamesPlayed = -1;
	int player1Pool = 0;
	int i;

	initializeBracketValueTable();

	while(gamesPlayed <= 0){

		printf("How games did you play? (enter a number greater than 0): ");
		scanf("%d", &gamesPlayed);
	}

	player1ELO = getPlayerOriginalELO();


	for (i = 1 ; i <= gamesPlayed ; i ++){

		player2ELO = getOpponentELO(i);

		playerRatingDifference = abs(player1ELO - player2ELO);

		if (max(player1ELO, player2ELO) == player1ELO)
			higherRatedPlayer = PLAYER1;
		else
			higherRatedPlayer = PLAYER2;


		winner = -1;

		while (winner != 1 && winner != 2){

			printf("\nWho won the game?\nPlayer 1 or Player 2\n(enter 1 or 2): ");
			scanf("%d", &winner);

		}

		determineBracket(&player1Pool, higherRatedPlayer, playerRatingDifference, winner);
	}
	
	
	printf("\nYour Original ELO was: %d\nYour pool is %d:\n", player1ELO, player1Pool);

	player1ELO += player1Pool;



	printf("\nYour Rating is now %d\n", player1ELO);

	system("PAUSE");	

	return 0;
}