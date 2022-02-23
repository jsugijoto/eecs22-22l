/* Player.h Header File 
 * Name: Jonathan Sugijoto
 * ID: 58535060
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define colorStart "\x1b["
#define colorReset "\x1b[0m"

typedef struct{
	char symbol; /* Player Symbol from A-Z */
	int player_num; /* Player number to see who goes first */
	char player_color;
		
} PLAYER;

void choose_char(PLAYER *player1, PLAYER *player2);

void choose_color(PLAYER *player1, PLAYER *player2);

void settings(PLAYER *player1, PLAYER *player2);

PLAYER *createPlayer(char sym, int num);

void deletePlayer(PLAYER *player);


#endif
