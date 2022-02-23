/* Board.h File */
/* Will be taking care of everything from managing the board, checking the board, and keeping track of the board */
/* Name: Jonathan Sugijoto */
/* ID: 58535060 */

#ifndef BOARD_H
#define BOARD_H

#include <time.h>
#include <stdio.h>
#include <string.h>
#include "Player.h"


typedef struct MOVE_LIST {
	int board[3][3];
	char move[2];
	struct MOVE_LIST *next;
	struct MOVE_LIST *prev;
}MOVE_LIST;

void append(MOVE_LIST **move_ref, int board[3][3], char *move);

void printMoveList(MOVE_LIST *moves);

void freeList(MOVE_LIST *moves);

int takeBack(MOVE_LIST *moves);

/* Prints the board */
void print_fun(int board[3][3], PLAYER *player1, PLAYER *player2);

/* Checks if there is an empty cell for tie condition */
int is_there_empty_cell(int board[3][3]);

/* Checks for a winner */
int IsWin(int board[3][3]);

char *entered_one_char(int board[3][3], int player_num);

void HumanVsHuman(int board[3][3], PLAYER *player1, PLAYER *player2);

void replay(MOVE_LIST *recorded_moves, PLAYER *player1, PLAYER *player2);

#endif



