#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_BRACKETS 11

typedef enum {
	PLAYER1 = 1, PLAYER2
} players;

typedef enum{
	BRACKET1 = 1, BRACKET2, BRACKET3, BRACKET4, BRACKET5, BRACKET6, BRACKET7, 
	BRACKET8, BRACKET9, BRACKET10, BRACKET11
} bracketType;

typedef struct bracketValues
{
	int expectedResult;
	int upsetResult;
}bracketValues;

static bracketValues bracketValueTable[NUMBER_OF_BRACKETS + 1];

void initializeBracketValueTable();
int getPlayerELO(int playerNumber);
int max (int a, int b);
void determineBracket (int* player1ELO, int* player2ELO, int higherRatedPlayer, int playerRatingDifference, int winner);
void determineNewRating (int* player1ELO, int* player2ELO, int higherRatedPlayer, int winner, int bracketNumber);

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

int getPlayerELO(int playerNumber){

	int playerElo = -1;

	while (playerElo < 0){

		printf("Please enter the rating (greater than 0) for player %d: ", playerNumber);
		scanf("%d", &playerElo);
	}


	return playerElo;

}

int max (int a, int b){

	return (a > b ? a : b);
}

void determineBracket (int* player1ELO, int* player2ELO, int higherRatedPlayer, int playerRatingDifference, int winner){

	//Bracket 1
	if (playerRatingDifference >= 0 && playerRatingDifference <= 12)
	{	
		determineNewRating(player1ELO, player2ELO, higherRatedPlayer, winner, BRACKET1);
	}
	//Bracket 2
	else if (playerRatingDifference >= 13 && playerRatingDifference <= 37)
	{
		determineNewRating(player1ELO, player2ELO, higherRatedPlayer, winner, BRACKET2);
	}
	//Bracket 3
	else if (playerRatingDifference >= 38 && playerRatingDifference <= 62)
	{
		determineNewRating(player1ELO, player2ELO, higherRatedPlayer, winner, BRACKET3);
	}
	else if (playerRatingDifference >= 63 && playerRatingDifference <= 87)
	{
		determineNewRating(player1ELO, player2ELO, higherRatedPlayer, winner, BRACKET4);
	}
	else if (playerRatingDifference >= 88 && playerRatingDifference <= 112)
	{
		determineNewRating(player1ELO, player2ELO, higherRatedPlayer, winner, BRACKET5);
	}
	else if (playerRatingDifference >= 113 && playerRatingDifference <= 137)
	{
		determineNewRating(player1ELO, player2ELO, higherRatedPlayer, winner, BRACKET6);
	}
	else if (playerRatingDifference >= 138 && playerRatingDifference <= 162)
	{
		determineNewRating(player1ELO, player2ELO, higherRatedPlayer, winner, BRACKET7);
	}
	else if (playerRatingDifference >= 163 && playerRatingDifference <= 187)
	{
		determineNewRating(player1ELO, player2ELO, higherRatedPlayer, winner, BRACKET8);
	}
	else if (playerRatingDifference >= 188 && playerRatingDifference <= 212)
	{
		determineNewRating(player1ELO, player2ELO, higherRatedPlayer, winner, BRACKET9);
	}
	else if (playerRatingDifference >= 213 && playerRatingDifference <= 237)
	{
		determineNewRating(player1ELO, player2ELO, higherRatedPlayer, winner, BRACKET10);
	}
	else
	{	
		determineNewRating(player1ELO, player2ELO, higherRatedPlayer, winner, BRACKET11);
	}


}

void determineNewRating (int* player1ELO, int* player2ELO, int higherRatedPlayer, int winner, int bracketNumber){

	if (winner == higherRatedPlayer){

		if (higherRatedPlayer == PLAYER1){

			*player1ELO += bracketValueTable[bracketNumber].expectedResult;
			*player2ELO -= bracketValueTable[bracketNumber].expectedResult;
		}

		else{

			*player2ELO += bracketValueTable[bracketNumber].expectedResult;
			*player1ELO -= bracketValueTable[bracketNumber].expectedResult;

		}
	}

	else{

		if (higherRatedPlayer == PLAYER1){

			*player1ELO -= bracketValueTable[bracketNumber].upsetResult;
			*player2ELO += bracketValueTable[bracketNumber].upsetResult;

		}

		else{

			*player2ELO -= bracketValueTable[bracketNumber].upsetResult;
			*player1ELO += bracketValueTable[bracketNumber].upsetResult;
		}

		
	}


} 


int main (int argc, char *argv[]){

	int player1ELO;
	int player2ELO;
	int higherRatedPlayer;
	int playerRatingDifference;
	int winner;
	int gamesPlayed;
	int i;

	initializeBracketValueTable();

	printf("How games did you play?: ");
	scanf("%d", &gamesPlayed);

	player1ELO = getPlayerELO(1);

	for (i = 0 ; i < gamesPlayed ; i ++){

		player2ELO = getPlayerELO(2);

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
	}
	

	


	

	determineBracket(&player1ELO,&player2ELO, higherRatedPlayer, playerRatingDifference, winner);


	printf("\nPlayer 1 rating is now %d\n", player1ELO);
	printf("\nPlayer 2 rating is now %d\n", player2ELO);

	system("PAUSE");	

	return 0;
}