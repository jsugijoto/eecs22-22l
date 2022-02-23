/*********************************************************************/
/* Reference solution for Assignment 1 for EECS 22 @ UCI Winter 2021 */
/*                                                                   */
/* This is an "A" level representation of the Tic-Tac-Whoa game.     */
/* There are improvements that can be made, but this is considered   */
/* very good.                                                        */
/*                                                                   */
/* This solution is for your reference for this course and           */
/* copyright belongs to the authors below. Reproduction or sharing   */
/* of this code outside of this class is prohibited except with the  */
/* express written consent of the authors.                           */
/*                                                                   */
/* Authors: Mozhgan Moradiganjeh, QV Dang, Jonathan Sugijoto         */
/* Modifications:                                                    */
/* 03/11/21 JS  Assignment 5 Requirements                            */
/* 01/18/21 QV  AI, function, and comment updates                    */
/* 01/13/21 MM  Initial version                                      */
/*********************************************************************/
#include <stdio.h>

#include "Board.h"
#include "Player.h"
#include "AI.h"

/* Handle Menu Options */
int print_menu()
{
	int select=0;
	printf("\n1. Start New Game (Human v. Human)\n");
	printf("2. Start New Game (Human v. AI)\n");
	printf("3. Game Settings\n");
	printf("4. Exit Game\n");
	printf("Choose Option: ");
	scanf("%d",&select);
	getchar(); /* one solution for clearing the "\n" char from the input */
	return select;
}


/* Main Program for Tic-Tac-Whoa */
int main()
{
    /* initialize game */
	PLAYER *player1;
	PLAYER *player2;
	player1 = createPlayer('X', 1);
	player2 = createPlayer('O', 2);

	printf("Welcome to Secure-Tic-Tac-Whoa!\n");
	int done=0;
	while(done==0)
	{
		int board[3][3]={{0,0,0},{0,0,0},{0,0,0}};
		int option = print_menu();
		switch(option)
		{
			case 1:
				HumanVsHuman(board, player1, player2);
				break;
			case 2:
				Human_VS_AI(board, player1, player2);
				break;
			case 3:
				settings(player1, player2);
				break;
			case 4:
				printf("Thanks for playing. Exiting game...\n");
				done=1;
				break;
		}
		
	}
	deletePlayer(player1);
	deletePlayer(player2);
	return 0;
}

/* EOF */
