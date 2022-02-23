/* chess.c File v1 
 * Description: chess header file for the main executable
 * Team 18 Members: Jonathan Sugijoto, Devin Reyes, Eesha Jain, Michael Nguyen, Jixin Gong
 * Last Updated: 4/14/2021
*/

#include "chess.h"
int start_menu()
{
	/* Initialize Players */
	MVLIST *lst = NULL;
	lst = NewMvList();

	#ifndef DEBUG	
	/* Opening Menu */
	printf("Welcome to Queen's Gambit Chess\n");
	int done = 0;
	int settings = 0;
	while(done == 0)
	{ 
		int option = print_menu();
		switch(option)
		{
			case 1: /* Player v AI */
				innitBoard();
				HumanVsAI(lst, settings);
				deletePawn(blackPawns);
 		        deletePawn(whitePawns);
             	deleteRook(blackRooks);
                deleteRook(whiteRooks);
                deleteKnight(blackKnights);
               	deleteKnight(whiteKnights);
                deleteBishop(blackBishops);
                deleteBishop(whiteBishops);
                deleteKing(blackKing);
                deleteKing(whiteKing);
               	deleteQueen(blackQueen);
                deleteQueen(whiteQueen);
				break;
			case 2: /* Player v Player */
				innitBoard();
				HumanVsHuman(lst);
				deletePawn(blackPawns);
 		        deletePawn(whitePawns);
             	deleteRook(blackRooks);
                deleteRook(whiteRooks);
                deleteKnight(blackKnights);
                deleteKnight(whiteKnights);
                deleteBishop(blackBishops);
                deleteBishop(whiteBishops);
                deleteKing(blackKing);
                deleteKing(whiteKing);
                deleteQueen(blackQueen);
                deleteQueen(whiteQueen);
				break;
			case 3:
				innitBoard();
				createChallenge(lst);
				HumanVsHuman(lst);
				deletePawn(blackPawns);
 		        deletePawn(whitePawns);
             	deleteRook(blackRooks);
                deleteRook(whiteRooks);
                deleteKnight(blackKnights);
                deleteKnight(whiteKnights);
                deleteBishop(blackBishops);
                deleteBishop(whiteBishops);
                deleteKing(blackKing);
                deleteKing(whiteKing);
                deleteQueen(blackQueen);
                deleteQueen(whiteQueen);
				break;
			case 4: /* Settings */
				settings = print_settings();
				break;
			case 5: /* Exit the game */
				done = 1;
				printf("Exiting the game...\n");
				break;
			default: 
				done = 1;
				printf("Exiting the game...\n");
				break;
		}
	}
	#endif
	#ifdef DEBUG
	/* Testing Only */
	innitBoard();
	testAll(lst);
	deletePawn(blackPawns);
	deletePawn(whitePawns);
	deleteRook(blackRooks);
	deleteRook(whiteRooks);
	deleteKnight(blackKnights);
	deleteKnight(whiteKnights);
	deleteBishop(blackBishops);
	deleteBishop(whiteBishops);
	deleteKing(blackKing);
	deleteKing(whiteKing);
	deleteQueen(blackQueen);
	deleteQueen(whiteQueen);
	replay(lst);
	DeleteMvList(lst);
	lst = NULL;
	#endif
	#ifndef DEBUG
    replay(lst);
    DeleteMvList(lst);
    lst = NULL;
	#endif
	return 0;
}

