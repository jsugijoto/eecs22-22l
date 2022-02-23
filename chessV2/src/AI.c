/* AI.c File v1
 * Description: AI file to house all the functions involving AI playing the game.
 * Team 18 Members: Jonathan Sugijoto, Devin Reyes, Eesha Jain, Michael Nguyen, Jixin Gong
 * Last Updated: 4/14/2021
*/

#include "AI.h"
#include "game.h"
#include "board.h"



int AI(int color, MVLIST *lst)
{
    int player;
    if (color == 1)
    {
        player = 1;
    }
    else if (color == -1)
    {
        player = 2;
    }

    int xo = rand() % 8; /*generates random ints from 0-7 for initial and final positions*/
    int yo = rand() % 8;
    int xf = rand() % 8;
    int yf = rand() % 8;
    if(board[xo][yo] == color)
    {
    //  printf("xo = %d, yo = %d, xf = %d, yf = %d\n", xo,yo,xf,yf);
    //  printf("Valid move pawn = %d \n", validmove_Pawn(xo,yo,xf,yf));

        /*if pawn move happens to be valid, please move the pawns*/
                 if(validmove_Pawn(xo,yo,xf,yf) == 1 && symbol_board[xo][yo] == 'P')
        {
            if(color == 1 && symbol_board[xo][yo] == 'P')
            {
                changePositionPawnAI(whitePawns,xo,yo,xf,yf);
                Append_AI(xo, yo, xf, yf, player, lst);
                return 1;
            }
            if(color == -1 && symbol_board[xo][yo] == 'P')
            {
                changePositionPawnAI(blackPawns,xo,yo,xf,yf);
                Append_AI(xo, yo, xf, yf, player, lst);
                return 1;
            }

        }
        /*if rook move happens to be valid, AI moves the rooks*/
        else if(validmove_Rook(xo,yo,xf,yf) == 1 && symbol_board[xo][yo] == 'R')
        {
            if(color == 1 && symbol_board[xo][yo] == 'R')
            {
                changePositionRookAI(whiteRooks,xo,yo,xf,yf);
                Append_AI(xo, yo, xf, yf, player, lst);
                return 1;
            }
            if(color == -1 && symbol_board[xo][yo] == 'R')
            {
                changePositionRookAI(blackRooks,xo,yo,xf,yf);
                Append_AI(xo, yo, xf, yf, player, lst);
                return 1;
            }


        }
		/*if Bishop move happens to be valid, AI moves the bihsops*/
        else if(validmove_Bishop(xo,yo,xf,yf) == 1 && symbol_board[xo][yo] == 'B')
        {
            if(color == 1 && symbol_board[xo][yo] == 'B')
            {
                changePositionBishopAI(whiteBishops,xo,yo,xf,yf);
                Append_AI(xo, yo, xf, yf, player, lst);
                return 1;
            }
            if(color == -1 && symbol_board[xo][yo] == 'B')
            {
                changePositionBishopAI(blackBishops,xo,yo,xf,yf);
                Append_AI(xo, yo, xf, yf, player, lst);
                return 1;
            }


        }
        /*if knight move happens to be valid*/
        else if(validmove_Knight(xo,yo,xf,yf) == 1 && symbol_board[xo][yo] == 'N')
        {
            if(color == 1 && symbol_board[xo][yo] == 'N')
            {
                changePositionKnightAI(whiteKnights,xo,yo,xf,yf);
                Append_AI(xo, yo, xf, yf, player, lst);
                return 1;
            }
            if(color == -1 && symbol_board[xo][yo] == 'N')
            {
                changePositionKnightAI(blackKnights,xo,yo,xf,yf);
                Append_AI(xo, yo, xf, yf, player, lst);
                return 1;
            }


        }
        /*if king move happens to be valid*/
        else if(validmove_King(xo,yo,xf,yf) == 1 && symbol_board[xo][yo] == 'K')
        {
            if(color == 1 && symbol_board[xo][yo] == 'K')
            {
                changePositionKingAI(whiteKing,xo,yo,xf,yf);
                Append_AI(xo, yo, xf, yf, player, lst);
                return 1;
            }
            if(color == -1 && symbol_board[xo][yo] == 'K')
            {
                changePositionKingAI(blackKing,xo,yo,xf,yf);
                Append_AI(xo, yo, xf, yf, player, lst);
                return 1;
            }


        }
		 /*if queen move happens to be valid*/
        else if(validmove_Queen(xo,yo,xf,yf) == 1 && symbol_board[xo][yo] == 'Q')
        {
            if(color == 1 && symbol_board[xo][yo] == 'Q')
            {
                changePositionQueenAI(whiteQueen,xo,yo,xf,yf);
                Append_AI(xo, yo, xf, yf, player, lst);
                return 1;
            }
            if(color == -1 && symbol_board[xo][yo] == 'Q')
            {
                changePositionQueenAI(blackQueen,xo,yo,xf,yf);
                Append_AI(xo, yo, xf, yf, player, lst);
                return 1;
            }


        }

    }
       return 0;
}

void Append_AI(int row, int col, int rowf, int colf, int player, MVLIST *lst)
{

    char move_ent[2];
    char final_ent[2];
	MOVES *moves = NULL;

    if (row == 0)
    {
        move_ent[1] ='1';
    }
    else if(row == 1)
    {
        move_ent[1] ='2';
    }
    else if(row == 2)
    {
        move_ent[1] ='3';
    }
    else if(row == 3)
    {
        move_ent[1] ='4';
    }
    else if(row == 4)
    {
        move_ent[1] ='5';
    }
    else if(row == 5)
    {
        move_ent[1] ='6';;
    }
    else if(row == 6)
    {
        move_ent[1] ='7';
    }
    else if(row == 7)
    {
        move_ent[1] ='8';
    }

    // column conversion

    if (col == 0)
    {
        move_ent[0] ='a';
    }
    else if(col == 1)
    {
        move_ent[0] ='b';
    }
    else if(col == 2)
    {
        move_ent[0] ='c';
    }
    else if(col == 3)
    {
        move_ent[0] ='d';
    }
	else if(col == 4)
    {
        move_ent[0] ='e';
    }
    else if(col == 5)
    {
        move_ent[0] ='f';
    }
    else if(col == 6)
    {
        move_ent[0] ='g';
    }
    else if(col == 7)
    {
        move_ent[0] ='h';
    }

    // final move conversion

    if (rowf == 0)
    {
        final_ent[1] ='1';
    }
    else if(rowf == 1)
    {
        final_ent[1] ='2';
    }
    else if(rowf== 2)
    {
        final_ent[1] ='3';
    }
    else if(rowf == 3)
    {
        final_ent[1] ='4';
    }
    else if(rowf == 4)
    {
        final_ent[1] ='5';
    }
    else if(rowf == 5)
    {
        final_ent[1] ='6';;
    }
    else if(rowf == 6)
    {
        final_ent[1] ='7';
    }
    else if(rowf == 7)
    {
      final_ent[1] ='8';
    }
	// column conversion

    if (colf == 0)
    {
        final_ent[0] ='a';
    }
    else if(colf == 1)
    {
        final_ent[0] ='b';
    }
    else if(colf == 2)
    {
        final_ent[0] ='c';
    }
    else if(colf == 3)
    {
        final_ent[0] ='d';
    }
    else if(colf == 4)
    {
        final_ent[0] ='e';
    }
    else if(colf == 5)
    {
        final_ent[0] ='f';
    }
    else if(colf == 6)
    {
        final_ent[0] ='g';
    }
    else if(colf == 7)
    {
      final_ent[0] ='h';
    }

    moves = NewMove(move_ent, player);
    AppendMove(lst, moves);

    moves = NewMove(final_ent, player);
    AppendMove(lst, moves);
}
