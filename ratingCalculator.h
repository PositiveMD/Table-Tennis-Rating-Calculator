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
int getOpponentELO(int opponentNumber);
int max (int a, int b);
void determineBracket (int* player1Pool, int higherRatedPlayer, int playerRatingDifference, int winner);
void determineNewRating (int* player1Pool, int higherRatedPlayer, int winner, int bracketNumber);
int getPlayerOriginalELO();