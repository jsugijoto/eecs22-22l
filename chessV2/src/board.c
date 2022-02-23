/* board.c  File v1
 * Description: all the board structures
 * Team 18 Members: Jonathan Sugijoto, Devin Reyes, Eesha Jain, Michael Nguyen, Jixin Gong
 * Last Updated: 14 April 2021
 * */
#include "board.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "board.h"


int castling_move = 0;

void innitBoard() /*initilizes the board and the pieces*/
{  
	for(int i = 0; i < 8; i++) /*sets board and symbol board = to null. If board is 1, white piece.If board is -1, black piece. Symbol board is a char board w the piece eg 'K' 'Q' etc*/
	{
		for(int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
			symbol_board[i][j] = '\0'; /*set all equal to 0*/
		}
	}

    /*there are 12 structures for each kind and color of piece*/
    blackPawns = CreatePawn('b', "bP");
    whitePawns = CreatePawn('w', "wP");   
    blackRooks = CreateRook('b', "bR");
    whiteRooks = CreateRook('w', "wR");
    whiteBishops = CreateBishop('w', "wB");
    blackBishops = CreateBishop('b', "bB");
    whiteKnights = CreateKnight('w', "wN");
    blackKnights = CreateKnight('b', "bN");
    whiteKing = CreateKing('w', "wK");
    blackKing = CreateKing('b', "bK");
    whiteQueen = CreateQueen('w', "wQ");
    blackQueen = CreateQueen('b', "bQ");
}


/*Connect the pieces to the positions on the board */
void CreateBoard()  
{
	int xb; /*black x position*/
	int yb; /*black y position*/
	int xw; /*white x position*/
	int yw; /*white y position*/
	
	for ( int i = 0; i < 8; i++) /*for number of pawn positions in the pawn structure*/
	{
		xb = blackPawns -> pos[i][0]; /*x black coordinate for 1 pawn is stored in pos[i][0]*/
		yb = blackPawns -> pos[i][1]; /*same for white coordinate*/
		if(xb != -5) /*if it = -5, that means it has been removed from the board*/
		{       
			board[xb][yb] = -1;
			symbol_board[xb][yb] = blackPawns -> piece;
		}
		
		xw = whitePawns -> pos[i][0]; /*x white coordinate for white pawns*/
		yw = whitePawns -> pos[i][1]; /*y white coordinate for white pawns*/
		if(xw != -5)
		{	
			board[xw][yw] = 1;
			symbol_board[xw][yw] = whitePawns -> piece;
		}
	}

	for (int i = 0; i < 2; i++) /*number of positions in other structures is 2*/
	{	
		/*Rooks*/
		xb = blackRooks -> pos[i][0];
		yb = blackRooks -> pos[i][1];
		if(xb != -5)
		{
			board[xb][yb] = -1;
			symbol_board[xb][yb] = blackRooks -> piece;
		}

		xw = whiteRooks -> pos[i][0];
		yw = whiteRooks -> pos[i][1];
		if(xw != -5)
		{
			board[xw][yw] = 1;	
			symbol_board[xw][yw] = whiteRooks -> piece;
		}
		/*Knights*/
		xb = blackKnights -> pos[i][0];
		yb = blackKnights -> pos[i][1];
		if(xb != -5)
		{
			board[xb][yb] = -1;
			symbol_board[xb][yb] = blackKnights -> piece;
		}
		xw = whiteKnights -> pos[i][0];
		yw = whiteKnights -> pos[i][1];
		if(xw != -5)
		{
			board[xw][yw] = 1;
			symbol_board[xw][yw] = whiteKnights -> piece;
		}
		/*Bishops*/
		xb = blackBishops -> pos[i][0];
		yb = blackBishops -> pos[i][1];
		if(xb != -5)
		{
			board[xb][yb] = -1;
			symbol_board[xb][yb] = blackBishops -> piece;
		}
		xw = whiteBishops -> pos[i][0];
		yw = whiteBishops -> pos[i][1];
		if(xw != -5)
		{
			board[xw][yw] = 1;
			symbol_board[xw][yw] = whiteBishops -> piece;
		}
		/*King*/
		xb = blackKing -> x;
		yb = blackKing -> y;
		if(xb != -5)
		{
			board[xb][yb] = -1;
			symbol_board[xb][yb] = blackKing -> piece;
		}
		xw = whiteKing -> x;
		yw = whiteKing -> y;
		if(xw != -5)
		{
			board[xw][yw] = 1;
			symbol_board[xw][yw] = whiteKing -> piece;
		}
		/*Queen*/
		xb = blackQueen -> x;
		yb = blackQueen -> y;
		if(xb != -5)
		{
			board[xb][yb] = -1;
			symbol_board[xb][yb] = blackQueen -> piece;
		}
		xw = whiteQueen -> x;
		yw = whiteQueen -> y;
		if(xw != -5)
		{
			board[xw][yw] = 1;
			symbol_board[xw][yw] = whiteQueen -> piece;
		}		
	}

}

/* print the board and the pieces */
void getBoard(PAWN *blackPawns, PAWN *whitePawns, ROOK *blackRooks, ROOK *whiteRooks, KNIGHT *blackKnights, KNIGHT *whiteKnights,
BISHOP *blackBishops, BISHOP *whiteBishops, QUEEN *blackQueen, QUEEN *whiteQueen, KING *blackKing, KING *whiteKing)
{
	int xb;
	int yb;
	int xw;
	int yw;
	for ( int i = 0; i < 8; i++)
	{
		xb = blackPawns -> pos[i][0];
		yb = blackPawns -> pos[i][1];
		if(xb != -5) /*if position is equal to -5, that means its off the board, so we dont want to read it otherwise things will segfault*/
		{       
			board[xb][yb] = -1;
			symbol_board[xb][yb] = blackPawns -> piece;
		}
		
		xw = whitePawns -> pos[i][0];
		yw = whitePawns -> pos[i][1];
		if(xw != -5)
		{	
			board[xw][yw] = 1;
			symbol_board[xw][yw] = whitePawns -> piece;
		}
	}

	for (int i = 0; i < 2; i++)
	{	
		/*Rooks*/
		xb = blackRooks -> pos[i][0];
		yb = blackRooks -> pos[i][1];
		if(xb != -5)
		{
			board[xb][yb] = -1;
			symbol_board[xb][yb] = blackRooks -> piece;
		}

		xw = whiteRooks -> pos[i][0];
		yw = whiteRooks -> pos[i][1];
		if(xw != -5)
		{
			board[xw][yw] = 1;	
			symbol_board[xw][yw] = whiteRooks -> piece;
		}
		/*Knights*/
		xb = blackKnights -> pos[i][0];
		yb = blackKnights -> pos[i][1];
		if(xb != -5)
		{
			board[xb][yb] = -1;
			symbol_board[xb][yb] = blackKnights -> piece;
		}
		xw = whiteKnights -> pos[i][0];
		yw = whiteKnights -> pos[i][1];
		if(xw != -5)
		{
			board[xw][yw] = 1;
			symbol_board[xw][yw] = whiteKnights -> piece;
		}
		/*Bishops*/
		xb = blackBishops -> pos[i][0];
		yb = blackBishops -> pos[i][1];
		if(xb != -5)
		{
			board[xb][yb] = -1;
			symbol_board[xb][yb] = blackBishops -> piece;
		}
		xw = whiteBishops -> pos[i][0];
		yw = whiteBishops -> pos[i][1];
		if(xw != -5)
		{
			board[xw][yw] = 1;
			symbol_board[xw][yw] = whiteBishops -> piece;
		}
		/*King*/
		xb = blackKing -> x;
		yb = blackKing -> y;
		if(xb != -5)
		{
			board[xb][yb] = -1;
			symbol_board[xb][yb] = blackKing -> piece;
		}
		xw = whiteKing -> x;
		yw = whiteKing -> y;
		if(xw != -5)
		{
			board[xw][yw] = 1;
			symbol_board[xw][yw] = whiteKing -> piece;
		}
		/*Queen*/
		xb = blackQueen -> x;
		yb = blackQueen -> y;
		if(xb != -5)
		{
			board[xb][yb] = -1;
			symbol_board[xb][yb] = blackQueen -> piece;
		}
		xw = whiteQueen -> x;
		yw = whiteQueen -> y;
		if(xw != -5)
		{
			board[xw][yw] = 1;
			symbol_board[xw][yw] = whiteQueen -> piece;
		}		
	}
	char color;
	int r, c, a;
	int rowletter = 97;
	for (r = 7; r > -1; r--)
 	{
        if (r == 7)
        {
            printf("\n  +----");
            for (a = 0; a < 7; a++)
                printf("+----");
            printf("+\n");
        }
        printf("%d ", r+1);

        for (c = 0; c < 8; c++)
        {
            if (c != 0)
            {       
		 if (board[r][c] == 1)
		 {
			color = 'w';
			printf(" %c%c |", color, symbol_board[r][c]);
		}
		else if (board[r][c] == -1)
		{
			color = 'b';
			printf(" %c%c |", color, symbol_board[r][c]);
		}
		else
			printf("    |");
            }
		
            else
           	{	
			if (board[r][c] == 1)
			{		
				color = 'w';
				printf("| %c%c |", color, symbol_board[r][c]);
			}
			else if (board[r][c] == -1)
			{
				color = 'b';
				printf("| %c%c |", color, symbol_board[r][c]);
			}
			else
				printf("|    |");
            }
        }

        if (r != 0)
        {
            printf("\n  +----");
            for (a = 0; a < 7; a++)
                printf("+----");
            printf("+\n");
        }
        else
        {
            printf("\n  +----");
            for (a = 0; a < 7; a++)
                printf("+----");
            printf("+\n");

            printf("    ");
            for (a = 0; a < 8; a++)
            {
                printf(" %c   ", rowletter);
                rowletter++;
            }
            printf("\n");
        }
    }
	

}
/*Bting the piece that is captures out of the board */
int capture(int xo, int yo, int xf, int yf)
{
	int valid;
	((board[xf][yf] != 0) && (board[xf][yf] == (board[xo][yo]*-1)))?(valid = 1):(valid = 0);
	if(valid == 0)
		return 0;

	if(symbol_board[xo][yo] == 'K' && symbol_board[xf][yf] == 'K')/*if a king tries to capture another king*/
	{
		printf("You cannot capture the King in this manner!");
		return 6;

	}
	if(symbol_board[xf][yf] == 'P' && board[xf][yf] == -1) /* if black pawn is captured*/
	{
    	for(int i = 0; i < 8; i++)
    	{
			if( blackPawns -> pos[i][0] == xf && blackPawns  -> pos[i][1] == yf) //finds  position in positions array(which is linked to the pawn structure) and then changes it 
			{	
				{	
					blackPawns -> pos[i][0] = -5; /* sets positions to -5, -5 if it is capture*/
					blackPawns -> pos[i][1] = -5;
				}
    		}
		}
	}
	
	if(symbol_board[xf][yf] == 'P' && board[xf][yf] == 1) /* if white  pawn is captured*/
	{
		
    	for(int i = 0; i < 8; i++)
    	{
			if( whitePawns -> pos[i][0] == xf && whitePawns  -> pos[i][1] == yf) //finds  position in positions array(which is linked to the pawn structure) and then changes it 
			{	
				{	
					whitePawns -> pos[i][0] = -5; /*take captured white pawn off the board*/
					whitePawns -> pos[i][1] = -5;
				}
    		}
		}
	}


	for(int i = 0; i < 2; i++)
	{
		if(symbol_board[xf][yf] == 'R' && board[xf][yf] == -1)/*if black rook is captured*/
		{
			if(blackRooks -> pos[i][0] == xf && blackRooks -> pos[i][1] == yf) /*finds initial position in positions array and then changes it */
			{
				blackRooks  -> pos[i][0] = -5; /*sets positions to negative values if captured*/
				blackRooks -> pos[i][1] = -5;
			}
		}
		
		if(symbol_board[xf][yf] == 'R' && board[xf][yf] == 1)/*if white rook is captured*/
		{
			if(whiteRooks -> pos[i][0] == xf && whiteRooks -> pos[i][1] == yf) /*finds initial position in positions array and then changes it */
			{
				whiteRooks  -> pos[i][0] = -5;
				whiteRooks -> pos[i][1] = -5;
			}
		}
		
		if(symbol_board[xf][yf] == 'B' && board[xf][yf] == -1)/*if black bishop is captured*/
		{
			if(blackBishops -> pos[i][0] == xf && blackBishops -> pos[i][1] == yf) /*finds initial position in positions array and then changes it */
			{       
				blackBishops  -> pos[i][0] = -5;
				blackBishops -> pos[i][1] = -5;
			}
		}
		
		if(symbol_board[xf][yf] == 'B' && board[xf][yf] == 1)/*if white bishop is captured*/
		{
			if(whiteBishops -> pos[i][0] == xf && whiteBishops -> pos[i][1] == yf) /*finds initial position in positions array and then changes it */
			{
				whiteBishops  -> pos[i][0] = -5;
				whiteBishops -> pos[i][1] = -5;
			}
		}
		
		if(symbol_board[xf][yf] == 'N' && board[xf][yf] == -1)/*if black Knight is captured*/
		{
			if(blackKnights -> pos[i][0] == xf && blackKnights -> pos[i][1] == yf) /*finds initial position in positions array and then changes it */
			{
				blackKnights  -> pos[i][0] = -5;
				blackKnights -> pos[i][1] = -5;
			}
		}
		
		if(symbol_board[xf][yf] == 'N' && board[xf][yf] == 1)/*if white Knight is captured*/
		{
			if(whiteKnights -> pos[i][0] == xf && whiteKnights -> pos[i][1] == yf) /*finds initial position in positions array and then changes it */
			{
				whiteKnights  -> pos[i][0] = -5;
				whiteKnights -> pos[i][1] = -5;
			}
		}

	}
	if(symbol_board[xf][yf] == 'Q' && board[xf][yf] == -1) /* if black queen is captured*/
	{	
		blackQueen -> x = -5;
		blackQueen -> y = -5;
	}
	if(symbol_board[xf][yf] == 'Q' && board[xf][yf] == 1) /*if white queen is captured*/
	{
		whiteQueen -> x = -5;
		whiteQueen -> y = -5;
	}
		
	if(symbol_board[xf][yf] == 'K') /*If someone tries to capture the king*/
	{
		return 5;
		
	}
	
	return 1;


}

PAWN *CreatePawn(char color, char *name) /*e.g: color = w, b name = wP*/ {
    PAWN *pawn;
    
    pawn = malloc(sizeof(PAWN));
    if(!pawn)
    {
	perror("Out of Memory!");
    }
	
    if(color == 'w')
    {
		for(int i = 0; i < 8; i++) /*creates the initial values of where the pieces should be*/
    	{
   			pawn -> pos[i][0]  = 1; /*put the value of x white pawn here*/
        	pawn -> pos[i][1] = i; /*put the value of y white pawn here*/
       	
		}
    }

    if(color == 'b')
    {
	 	for(int i = 0; i < 8; i++) /*creates the initial values of where the pieces should be*/
    	{
   			pawn -> pos[i][0]  = 6; /*put the value of x black pawn here*/
        	pawn -> pos[i][1] = i; /*put the value of y black pawn here*/
       	
 		}
    }


	pawn -> piece = 'P'; /*symbol name*/
	pawn -> color = color; /*color of player*/
	strncpy(pawn->name, name, 2); /*copies color and piece togehter e.g w + P = wP*/ 
	pawn -> name[2] = '\0';
	return pawn;

}

int changePositionPawn(PAWN *pawn, int xo, int yo, int xf, int yf)
{

	int VMP = validmove_Pawn(xo,yo,xf,yf);
	if(validmove_Pawn(xo,yo,xf,yf)==0)
	{   
		if(validmove_Pawn(xo, yo, xf, yf) == 0)
			printf("Invalid move!");
   
		return 0;
	}
	for(int i = 0; i < 8; i++)
	{
		if(pawn -> pos[i][0] == xo && pawn -> pos[i][1] == yo) /*finds initial position in positions array(which is linked to the pawn structure) and then changes it */
		{
			int store = board[xo][yo]; /*saves the color for resetting*/
			int storepiece = board[xf][yf]; /*saves color for resetting*/
			pawn->pos[i][0] = xf; /*lets move the pawn*/
			pawn->pos[i][1] = yf; /*lets move the pawn*/
			board[xo][yo] = 0; /*lets set the initial position to 0*/
			CreateBoard(); /*creates the board so we can check first if a piece is putting their own king in check*/

			if(check() ==  store) /* Checking that the pieces do not let their King be put in check */
			{
				printf("Please don't endanger your King.");
				pawn->pos[i][0] = xo; /*if the piece has been put in check we want to reset everything*/
				pawn->pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard();
				return 0;
			}
			pawn->pos[i][0] = xo; /*even if the board has not been put in check, we want to reset anyway to check other possible error conditions before permanently moving the piece*/
			pawn->pos[i][1] = yo;
			board[xf][yf] = storepiece;
			CreateBoard();
			if(check() == 0) /* if the the king is initially not in check, you can put him into check*/
			{
				capture(xo,yo,xf,yf);
				pawn -> pos[i][0] = xf;
				pawn -> pos[i][1] = yf;
			}
			else if(check() != 0) /*Once the board is in check, you should not be able to leave it unless it is out of check*/
			{	
				pawn -> pos[i][0] = xf; /*we will keep creating the board to the persons desire if the board is already in check at the time of the player's turn*/
				pawn -> pos[i][1] = yf;
				CreateBoard();
				if(check() != 0) /*however we must be careful. If despite the players move, the board is still in check, we wish to reset again as these moves are illegal*/
				{
					pawn -> pos[i][0] = xo;
					pawn -> pos[i][1] = yo;
					board[xf][yf] = storepiece;
					CreateBoard();
					return 0; /*we return 0, returning the initial board, with an error message for the same player to try again*/
				}
				pawn->pos[i][0] = xo;/*Even if eveyrthingis valid up until this point, we still want to reset to check for capture, our last possible error condition*/
				pawn->pos[i][1] = yo; /*We do not want to capture ANYTHING until we are sure that everything else is valid. Calling capture prematurely confuses the function*/
				board[xf][yf] = storepiece;
				CreateBoard();
				capture(xo,yo,xf,yf); /*If it has reached this point, everything is valid so we cancapture the piece that is captured, and then move the piece that needs to be moved*/
				pawn -> pos[i][0] = xf;
				pawn -> pos[i][1] = yf;

				
			}

		}	
	}
    if(VMP  == 7) /*white en Passant to the right*/
    {     
		board[xo][yo+1] = 0;
		board[xo][yo] = 0;
        return 1;

    }

    else if(VMP == 8) /*white en Passant to the left*/
    {
		board[xo][yo-1] = 0;
        board[xo][yo] = 0;
        return 1;

    }

    else if(VMP == 9) /*black en Passant to the right*/
    {
		board[xo][yo+1] = 0;
        board[xo][yo] = 0;
        return 1;
    }

    else if(VMP == 10) /*black en Passant to the left*/
    {
		board[xo][yo-1] = 0;
        board[xo][yo] = 0;
        return 1;
    }
    board[xo][yo] = 0;
    return 1;

   
}

int validmove_Pawn(int xo, int yo, int xf, int yf)
{

	int valid = 0;
	int count = 0;
	if(board[xo][yo] == board[xf][yf]) //if final move is same as initial move
	{
		return 0;
	}
	
	if(board[xo][yo] == 1) //if the piece wanting to be moved is white
	{

		(  (xo == 1) && (yo == yf) && (xf == (xo + 2)) && (board[xo+1][yo] == 0) && (board[xf][yf] == 0))?(valid = 1):(count+=1); /* if first move and move 2 and there is nothing blocking it*/
		
		(  (xf == (xo + 1)) && (yf == yo) && (board[xf][yf] == 0) )?(valid = 1):(count+=1); /* if moving 1, check that where it is moving is empty*/
	
		(  (xf == (xo + 1)) && (yf == (yo + 1)) && (board[xf][yf] == -1) )?(valid = 1):(count+=1); /* if moving to kill to the right, check that black piece exists there*/

		(  (xf == (xo + 1)) && (yf == (yo - 1)) && (board[xf][yf] == -1) )?(valid = 1):(count+=1); /* if moving to kill to the left, check that black piece exists there*/
		
		if(  (xf == (xo+1)) && (yf == (yo+1)) && (board[xo][yo+1] == -1) && (symbol_board[xo][yo+1] == 'P') ) /*En passant to the right*/
		{      
			valid = 7;
			capture(xo,yo,xo,(yo+1));
		}
		
		if(  (xf == (xo+1)) && (yf == (yo-1)) && (board[xo][yo-1] == -1) && (symbol_board[xo][yo-1] == 'P') ) /*En passant to the left*/
		{
			valid = 8;
			capture(xo,yo,xo,(yo-1));
		}	
		
		
	}
	if(board[xo][yo] == -1) //if the piece wanting to be moved is white
	{

		(  (xo == 6) && (yo == yf) && (xf == (xo - 2)) && (board[xo-1][yo] == 0) && (board[xf][yf] == 0))?(valid = 1):(count+=1); /* if first move and move 2 and there is nothing blocking it*/
		
		(  (xf == (xo - 1)) && (yf == yo) && (board[xf][yf] == 0) )?(valid = 1):(count+=1); /* if moving 1, check that where it is moving is empty*/
	
		(  (xf == (xo - 1)) && (yf == (yo - 1)) && (board[xf][yf] == 1) )?(valid = 1):(count+=1); /* if moving to kill to the left, check that black piece exists there*/

		(  (xf == (xo - 1)) && (yf == (yo + 1)) && (board[xf][yf] == 1) )?(valid = 1):(count+=1); /* if moving to kill to the right, check that black piece exists there*/

		if(  (xf == (xo-1)) && (yf == (yo+1)) && (board[xo][yo+1] == 1) && (symbol_board[xo][yo+1] == 'P') ) /*En passant to the right*/
		{      
			valid = 9;
			capture(xo,yo,xo,(yo+1));
		}
		
		if(  (xf == (xo-1)) && (yf == (yo-1)) && (board[xo][yo-1] == 1) && (symbol_board[xo][yo-1] == 'P') ) /*En passant to the left*/
		{
			valid = 10;
			capture(xo,yo,xo,(yo-1));
		}		

	}
	if(valid == 0)
	{
		return 0;
	}
	
	if(symbol_board[xf][yf] == 'K') /*for check condition after we know move is valid*/
	{
		return 5;
	}

	//capture(xo,yo,xf,yf);
	return valid;



}
void deletePawn(PAWN *pawn)
{
    assert(pawn);
    free(pawn);
    pawn = NULL;

}


/*start of function*/
ROOK *CreateRook(char color, char *name) /*e.g: color = w, b name = wP*/
{
    ROOK *rook;
    
    rook  = malloc(sizeof(ROOK));
    if(!rook)
    {
	perror("Out of Memory!");
    }
	
    if(color == 'w')
    {
       rook -> pos[0][0] = 0; /*xvalue of first white rook*/
	   rook -> pos[0][1] = 0; /*yvalue of first white rook*/
	   rook -> pos[1][0] = 0; /*xvalue of first second rook*/
	   rook -> pos[1][1] = 7; /* yvalie of first second rook*/
	 
    }

    if(color == 'b')
    {	
       rook -> pos[0][0] = 7; /*xvalue of first black rook*/
	   rook -> pos[0][1] = 0; /*yvalue of first black rook*/
	   rook -> pos[1][0] = 7; /*xvalue of second black rook*/
	   rook -> pos[1][1] = 7; /*y valie of second black rook*/
    }


    rook -> piece = 'R';
    rook -> color = color;
    strncpy(rook->name, name, 2);
    rook -> name[2] = '\0';
    return rook;

}
/* end of function*/





/*start of function*/
/*To understand how ChangePositionRook works, please look at the comments of ChangePositionPawn. All change position functions follow the same structure*/
int  changePositionRook(ROOK *rook, int xo, int yo, int xf, int yf)
{       

	/*checks valid move*/
	if (castling_move == 0)
	{
		if(validmove_Rook(xo, yo, xf, yf) == 0)
		{
			if(validmove_Rook(xo, yo, xf, yf) == 0)
				printf("Invalid move!");
			return 0;
	
		}
	}


	/*moves piece if everything is valid*/
	for(int i = 0; i < 2; i++)
	{
		if(rook -> pos[i][0] == xo && rook -> pos[i][1] == yo) /*finds initial position in positions array(which is linked to the pawn structure) and then changes iit */
        {
			int store = board[xo][yo]; /* Storing initial player for future reference */
			int storepiece = board[xf][yf]; /* Storing initial piece for future reference */
			rook->pos[i][0] = xf; /* Preemptively moves piece to final position and resets the player board, using this time to check if it will endanger the King */
			rook->pos[i][1] = yf;
			board[xo][yo] = 0;
			CreateBoard();
			if(check() == store)
			{
				printf("Please don't endanger your King.");
				rook->pos[i][0] = xo;
				rook->pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard();
				return 0;
			}
			rook->pos[i][0] = xo;
			rook->pos[i][1] = yo;
			board[xf][yf] = storepiece;
			CreateBoard();
			if(check() == 0) /* if the the king is initially not in check, you can put him into check*/
			{
				capture(xo,yo,xf,yf);
				rook -> pos[i][0] = xf;
	   			rook -> pos[i][1] = yf;

			}
			else if(check() != 0) /*Once the board is in check, you should not be able to leave it unless it is out of check*/
			{
	   			rook -> pos[i][0] = xf;
	   			rook -> pos[i][1] = yf;
				CreateBoard();
				if(check() != 0)
				{
					rook -> pos[i][0] = xo;
					rook -> pos[i][1] = yo;
					board[xf][yf] = storepiece;
					return 0;
				}
				rook->pos[i][0] = xo; /*resets board in case of capture*/
				rook->pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard();
			
				capture(xo,yo,xf,yf); /*capture if need be*/
				rook -> pos[i][0] = xf;
	   			rook -> pos[i][1] = yf;


				
			}
		}
	}
	
        board[xo][yo] = 0;
		return 1;
}
/*end of function*/


/*start of function*/
int validmove_Rook(int xo, int yo, int xf, int yf)
{

	int valid;
	int min, max;
	
	if (board[xf][yf] == board[xo][yo])
	{

		return 0;
	}

	if(xf == xo)
	{
		valid = 1; /*moving horizontally*/
	}
	else if(yf == yo)
	{
		valid = 2; /*moving vertically*/
	}
    	else
   	{
		return 0;
	}

	/*First, lets check if there are blocking pieces if  move is horizontal*/

    if(valid == 1)
	{	
		if(yf > yo)
		{
			min = yo;
			max = yf;
		}
		else
		{
			min = yf;
			max = yo;
		}	
		for(int i = yo+1; i < yf; i++) /*this for loop checks if there are pieces in between for horizontal move*/
		{
			if(board[xo][i] != 0)
			{
				valid = 0;
				return 0;
			}
		}
	}
	

	/*Now, we will check if there are blocking pieces if  move is vertical*/
    else if(valid == 2)
	{       
		
		if(xf > xo)
		{
			 min = xo;
			 max = xf;
		}
		else
		{
			min = xf;
			max = xo;
		}
		
		for(int i = min+1; i < max; i++) /*this for loop checks if there are pieces in between for vertical move*/
		{
			if(board[i][yo] != 0)
			{
				valid = 0;
				return 0;
			}
		}
	
	}
	
	if(symbol_board[xf][yf] == 'K') /*for check condition after we know move is valid*/
	{
		return 5;
	}

	//capture(xo,yo,xf,yf);
	return 1;

}

/*end of function*/



void deleteRook(ROOK *rook)
{
    assert(rook);
    free(rook);
    rook = NULL;

}



BISHOP *CreateBishop(char color, char *name) /*e.g: color = w, b name = wP*/
{
    BISHOP *bishop;
    
    bishop  = malloc(sizeof(BISHOP));

    if(!bishop)
    {
		perror("Out of Memory!");
    }
	
    if(color == 'w')
    {
       bishop -> pos[0][0] = 0; /*xvalue of first white bishop*/
	   bishop -> pos[0][1] = 2; /*yvalue of first white bishop*/
	   bishop -> pos[1][0] = 0; /*xvalue of second white bishop*/
	   bishop -> pos[1][1] = 5; /*yvalue of second white bishop*/
	 
    }

    if(color == 'b')
    {	
       bishop -> pos[0][0] = 7; /*xvalue of first black bishop*/
	   bishop -> pos[0][1] = 2; /*yvalue of first black bishop*/
	   bishop -> pos[1][0] = 7; /*xvalue of second black bishop*/
	   bishop -> pos[1][1] = 5; /*yvalue of second black bishop*/
    }



		bishop -> piece = 'B';
		bishop -> color = color;
        strncpy(bishop->name, name, 2);
        bishop -> name[2] = '\0';
		return bishop;

}

/*To understand how ChangePositionBishop works, please look at the comments of ChangePositionPawn. All change position functions follow the same structure*/

int changePositionBishop(BISHOP *bishop, int xo, int yo, int xf, int yf)
{
    if( validmove_Bishop(xo,yo,xf,yf) == 0)
    {
		if(validmove_Bishop(xo, yo, xf, yf) == 0)
			printf("Invalid move!");

		return 0;
    }

    for(int i = 0; i < 2; i++)
    {
		if(bishop -> pos[i][0] == xo && bishop -> pos[i][1] == yo) /*finds initial position in positions array(which is linked to the pawn structure) and then changes it */
		{
			int store = board[xo][yo];
			int storepiece = board[xf][yf];
			bishop->pos[i][0] = xf;
			bishop->pos[i][1] = yf;
			board[xo][yo] = 0;
			CreateBoard();
			if(check() == store)
			{
				printf("Please don't endanger your King.");
				bishop->pos[i][0] = xo;
				bishop->pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard();
				return 0;
			}
			bishop -> pos[i][0] = xo;
			bishop -> pos[i][1] = yo;
			board[xf][yf] = storepiece;
			CreateBoard(); /*resets everything so we can check other possible error conditions*/
			if(check() == 0) /* if the the king is initially not in check, you can put him into check*/
			{      

				capture(xo,yo,xf,yf);
				bishop -> pos[i][0] = xf;
	   			bishop -> pos[i][1] = yf;			

			}
			else if(check() != 0) /*Once the board is in check, you should not be able to leave it unless it is out of check*/
			{       
			
	    			bishop -> pos[i][0] = xf;
	   			bishop -> pos[i][1] = yf;
				CreateBoard();
				if(check() != 0)
				{       
					bishop -> pos[i][0] = xo;
					bishop -> pos[i][1] = yo;
					board[xf][yf] = storepiece;
					return 0;
				}

			        bishop -> pos[i][0] = xo;
				bishop -> pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard(); /*resets everything so we can check for a capture*/

				capture(xo,yo,xf,yf);
				bishop -> pos[i][0] = xf;
	   			bishop -> pos[i][1] = yf;	

			}
		}
    } 
    board[xo][yo] = 0;

    return 1;
}

void deleteBishop(BISHOP *bishop)
{
	assert(bishop);
	free(bishop);
	bishop = NULL;

}


int validmove_Bishop(int xo, int yo, int xf, int yf)
{
	int diff_x, diff_y;
	int i;
	/* check if the piece would move diagonally */
	diff_x = abs(xf - xo);
	diff_y = abs(yf - yo);
	
	if (board[xf][yf] == board[xo][yo])
	{
		return 0;
	}

	if (diff_x != diff_y)
	{
		return 0;
	}
	/* check if there is a piece between the initial and final position */
	/* check the top right situation*/ 
	if (xf>xo && yf>yo)
	{
		for (i = 1; i < xf-xo; i++)
		{
			if(board[xo+i][yo+i] != 0)
			{
				return 0;
			}
		}
	}
	
	/* check the top left situation*/ 
	if (xf>xo && yf<yo)
	{
		for (i = 1; i < xf-xo; i++)
		{
			if(board[xo+i][yo-i] != 0)
			{
				return 0;
			}
		}
	}
	
	/* check the bottom right situation*/ 
	if (xf<xo && yf>yo)
	{
		for (i = 1; i < xo-xf; i++)
		{
			if(board[xo-i][yo+i] != 0)
			{
				return 0;
			}
		}
	}
	
	/* check the bottom left situation*/ 
	if (xf<xo && yf<yo)
	{
		for (i = 1; i < xo-xf; i++)
		{
			if(board[xo-i][yo-i] != 0)
			{
				return 0;
			}
		}
	}
	
	
	
	if(symbol_board[xf][yf] == 'K') /*for check condition after we know move is valid*/
	{
		return 5;
	}
	return 1;
}

KNIGHT *CreateKnight(char color, char *name) /*e.g: color = w, b name = wP*/
{
    KNIGHT *knight;
    
    knight  = malloc(sizeof(KNIGHT));
    if(!knight)
    {
	perror("Out of Memory!");
    }
	
    if(color == 'w')
    {
       knight -> pos[0][0] = 0; /*xvalue of first white knight*/
	   knight -> pos[0][1] = 1; /*yvalue of first white knight*/
	   knight -> pos[1][0] = 0; /*xvalue of second white knight*/
	   knight -> pos[1][1] = 6; /*yvalue of second white knight*/
	 
    }


    if(color == 'b')
    {	
       knight -> pos[0][0] = 7; /*xvalue of first black knight*/
	   knight -> pos[0][1] = 1; /*yvalue of first black knight*/
	   knight -> pos[1][0] = 7; /*xvalue of second black knight*/
	   knight -> pos[1][1] = 6; /*yvalue of second black knight*/
    }




    knight -> piece = 'N';
    knight -> color = color;
    strncpy(knight->name, name, 2);
    knight -> name[2] = '\0';
    return knight;

}

/*To understand how ChangePositionKnight works, please look at the comments of ChangePositionPawn. All change position functions follow the same structure*/

int changePositionKnight(KNIGHT *knight, int xo, int yo, int xf, int yf)
{
	if(validmove_Knight(xo,yo,xf,yf) == 0)
	{
		if(validmove_Knight(xo, yo, xf, yf) == 0)
			printf("Invalid move!");
 
		return 0;
	}
	for(int i = 0; i < 2; i++)
	{
		if(knight -> pos[i][0] == xo && knight -> pos[i][1] == yo) /*finds initial position in positions array(which is linked to the pawn structure) and then changes it */
        {
			int store = board[xo][yo];
			int storepiece = board[xf][yf];
			knight->pos[i][0] = xf;
			knight->pos[i][1] = yf;
			board[xo][yo] = 0;
			CreateBoard();
			if(check() == store)
			{
				printf("Please don't endanger your King.");
				knight->pos[i][0] = xo;
				knight->pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard();
				return 0;
			}
			knight -> pos[i][0] = xo;
			knight -> pos[i][1] = yo;
			board[xf][yf] = storepiece;
			CreateBoard();
			if(check() == 0) /* if the the king is initially not in check, you can put him into check*/
			{
				capture(xo,yo,xf,yf);
				knight -> pos[i][0] = xf;
	   			knight -> pos[i][1] = yf;


			}
			else if(check() != 0) /*Once the board is in check, you should not be able to leave it unless it is out of check*/
			{
		    		knight -> pos[i][0] = xf;
	   			knight -> pos[i][1] = yf;
				CreateBoard();
				if(check() != 0)
				{
					knight -> pos[i][0] = xo;
					knight -> pos[i][1] = yo;
					board[xf][yf] = 0;
					return 0;
				}

				knight -> pos[i][0] = xo; /*check for capture*/
				knight -> pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard();

				capture(xo,yo,xf,yf); /*if capture valid*/
				knight -> pos[i][0] = xf;
	   			knight -> pos[i][1] = yf;

			}

		}
	}
	board[xo][yo] = 0;
        return 1;
}
int validmove_Knight(int xo, int yo, int xf, int yf)
{
	int valid = 0;
	int count = 0;
	
	if (board[xf][yf] == board[xo][yo])
	{
		return 0;
	}
	((xf == (xo+1)) && (yf == (yo - 2)))?(valid=1):(count+=1);
	
	(xf == (xo+2) && yf == (yo-1))?(valid=1):(count+=1);

	(xf == (xo+2) && yf == (yo+1))?(valid=1):(count+=1);

	(xf == (xo+1) && yf == (yo+2))?(valid=1):(count+=1);

	(xf == (xo-1) && yf == (yo+2))?(valid=1):(count+=1);

	(xf == (xo-2) && yf == (yo+1))?(valid=1):(count+=1);

	(xf == (xo-2) && yf == (yo-1))?(valid=1):(count+=1);

	(xf == (xo-1) && yf == (yo-2))?(valid=1):(count+=1);
   
	if(valid == 1)
	{  
	
		if(symbol_board[xf][yf] == 'K') /*for check condition after we know move is valid*/
		{
			return 5;
		}

		//capture(xo,yo,xf,yf);
		return 1;
	}
	else
	{
		return 0;
	}

}
void deleteKnight(KNIGHT *knight)
{
	assert(knight);
	free(knight);

}



KING *CreateKing(char color, char *name) /*e.g: color = w, b name = wP*/
{
    KING *king;
    
    king  = malloc(sizeof(KING));
    if(!king)
    {
	perror("Out of Memory!");
    }


    if(color == 'w') /*white king*/
    {
	 king -> x = 0;
	 king -> y = 4;
    }

    if(color == 'b') /*black king*/
    {
         king -> x = 7;
	 king -> y = 4;	
    }


    king -> piece = 'K';
    king -> color = color;
    strncpy(king->name, name, 2);
    king -> name[2] = '\0';
    return king;


}

/*To understand how ChangePositionKing works, please look at the comments of ChangePositionPawn. All change position functions follow the same structure*/
/*The reason there is no for loop in the king and queen functions is because there is only one king and one queen per color, so we dont need to search a positions array*/
int changePositionKing(KING *king, int xo, int yo, int xf, int yf)
{
	if (castling_move == 0)
	{
		if(validmove_King(xo, yo, xf, yf) == 0)
		{
			if(validmove_King(xo, yo, xf, yf) == 0)/*Check the valid move */
				printf("Invalid move!");
		    return 0;
		}
	}
	if(king -> x == xo && king -> y == yo)
	{  	
		int store = board[xo][yo];
		int storepiece = board[xf][yf];	
		king->x = xf;
		king->y = yf;
		board[xo][yo] = 0;
		CreateBoard();
		if(check() == store)
		{
			printf("Please do not endanger your King.");
			king->x = xo;
			king->y = yo;
			board[xf][yf] = storepiece;
			CreateBoard();
			return 0;
		} 
		king->x = xo;
		king->y = yo;
		board[xf][yf] = storepiece;
		CreateBoard(); /*resets the board*/
		if(check() == 0)
		{
			if(capture(xo,yo,xf,yf) == 6)
				{return 0;}
			king -> x = xf;
			king -> y = yf;
		}
		else if(check() != 0) /*If the board is in check*/
		{
			king  -> x = xf; /*Set the pieces and create the board*/
			king  -> y = yf;
			CreateBoard();
			if(check() != 0) /*If the player moves, and check is still not equal to 0, just move pieces back to inital place and return 0*/
			{
				king -> x = xo;
				king -> y = yo;
				board[xf][yf] = storepiece;
				return 0;
			}
			king->x = xo; /*If the move got player out of check, lets reset the board so we can properly capture a piece*/
			king->y = yo;
			board[xf][yf] = storepiece;
			CreateBoard(); /*resets the board in case there is a capture*/

			if(capture(xo,yo,xf,yf)==6) /*capture the piece first and then change*/
				{return 0;}
			king->x = xf;
			king->y = yf;
		}

	}
	board[xo][yo] = 0;
	return 1;




}

void deleteKing(KING *king)
{
	assert(king);
	free(king);

}

int validmove_King(int xo, int yo, int xf, int yf)
{
	/* Check the difference between initial and final position values */ 
	int diff_x, diff_y;
	diff_x = abs(xf - xo);
	diff_y = abs(yf - yo);
	
	if (diff_x > 1|| diff_y > 1)
	{
		return 0;
	}
	else if (board[xf][yf] == board[xo][yo])
	{
		return 0;
	}
	if(symbol_board[xf][yf] == 'K') /*for check condition after we know move is valid*/
    	{   
        	return 5;
    	}
	
	return 1;
}

// valid move without printf's for checkmate
int validmove_King2(int xo, int yo, int xf, int yf)
{   
    int i, j;
    /* Check the difference between initial and final position values */
    int diff_x, diff_y;
    diff_x = abs(xf - xo);
    diff_y = abs(yf - yo);
    
    if (diff_x > 1|| diff_y > 1)
    {   
        return 0;
    }
    else if (board[xf][yf] == board[xo][yo])
    {
        
        return 0;
    }
    
    for (i = -1; i < 2; i++)
	{
		for (j = -1; j < 2; j++)
		{
			if(symbol_board[xf+i][yf+j] == 'K' && board[xf+i][yf+j] != board[xo][yo])
			{
				return 0;
			}
		}
	}
    if(symbol_board[xf][yf] == 'K') /*for check condition after we know move is valid*/
    {   
        return 5;
    }
    return 1;
}


QUEEN *CreateQueen(char color, char *name) /*e.g: color = w, b name = wP*/
{
    QUEEN *queen;
    
    queen = malloc(sizeof(QUEEN));
    if(!queen)
    {
	perror("Out of Memory!");
    }
	
    if(color == 'w') /*white queen*/
    {
	 queen -> x = 0;
	 queen -> y = 3;
    }


    if(color == 'b') /*black queen*/
    {
	queen -> x = 7;
	queen -> y = 3;	
    }


    queen -> piece = 'Q';
    queen -> color = color;
    strncpy(queen->name, name, 1);
    queen -> name[1] = '\0';
    return queen;


}

/*To understand how ChangePositionQueen works, please look at the comments of ChangePositionPawn. All change position functions follow the same structure*/

int changePositionQueen(QUEEN *queen, int xo, int yo, int xf, int yf)
{
	if(validmove_Queen(xo, yo, xf, yf) == 0)
	{
		if(validmove_Queen(xo, yo, xf, yf) == 0)
			printf("Invalid move!");
	    return 0;
	}
	if(queen -> x == xo && queen -> y == yo)
	{  	 
		int store = board[xo][yo];
		int storepiece = board[xf][yf];
		queen->x = xf;
		queen->y = yf;
		board[xo][yo] = 0;
		CreateBoard();
		if(check() == store)
		{
			printf("Please do not endanger your King.");
			queen->x = xo;
			queen->y = yo;
			board[xf][yf] = storepiece;
			CreateBoard();
			return 0;
		}
		queen->x = xo;
		queen->y = yo;
		board[xf][yf] = storepiece;
		CreateBoard(); /*resets the board*/

		if(check() == 0)
		{
			capture(xo,yo,xf,yf);
			queen -> x = xf;
			queen -> y = yf;
		}
		else if(check() != 0)
		{
			queen  -> x = xf;
			queen  -> y = yf;
			CreateBoard();
			if(check() != 0)
			{
				queen -> x = xo;
				queen -> y = yo;
				board[xf][yf] = storepiece;
				return 0;
			}
			queen->x = xo;
			queen->y = yo;
			board[xf][yf] = storepiece;
			CreateBoard(); /*resets the board in case of capture*/

			capture(xo,yo,xf,yf);
			queen -> x = xf;
			queen -> y = yf;



		}

	}
	board[xo][yo] = 0;
	return 1;
}

void deleteQueen(QUEEN *queen)
{
	assert(queen);
	free(queen);

}

int validmove_Queen(int xo, int yo, int xf, int yf)
{
	int diff_x, diff_y;
	int i;
	/* check if the piece would move diagonally or horizontal or vertical */
	diff_x = abs(xf - xo);
	diff_y = abs(yf - yo);
	
	if (board[xf][yf] == board[xo][yo])
	{
		return 0;
	}
	
	if (diff_x != diff_y && xo != xf && yo != yf)
	{
		return 0;
	}
	
	if (xo == xf)
	{
		/* Check the move to right situation*/
		if (yf > yo)
		{
			for (i = yo+1; i < yf; i++)
			{
				if(board[xo][i] != 0)
               			 {
                		    return 0;
                		 }
			}
		}
		
		/* Check the move to left situation */
		if (yf < yo)
		{
			for (i = yo-1; i > yf; i--)
			{
				if(board[xo][i] != 0)
                {
                    return 0;
                }
			}
		}
	}
	
	if (yo == yf)
	{
		/* Check the move to top situation*/
		if (xf > xo)
		{
			for (i = xo+1; i < xf; i++)
			{
				if(board[i][yo] != 0)
                {
                    return 0;
                }
			}
		}
		
		/* Check the move to bottom situation */
		if (xf < xo)
		{
			for (i = xo-1; i > xf; i--)
			{
				if(board[i][yo] != 0)
                {
                    return 0;
                }
			}
		}
	}
	
	if (diff_x == diff_y)
	{
		/* check the move to top right situation*/
		if (xf>xo && yf>yo)
		{
			for (i = 1; i < xf-xo; i++)
			{
				if(board[xo+i][yo+i] != 0)
				{
					return 0;
				}
			}
		}
	
		/* check the move to top left situation*/ 
		if (xf>xo && yf<yo)
		{
			for (i = 1; i < xf-xo; i++)
			{
				if(board[xo+i][yo-i] != 0)
				{
					return 0;
				}
			}
		}
	
		/* check the move to bottom right situation*/ 
		if (xf<xo && yf>yo)
		{
			for (i = 1; i < xo-xf; i++)
			{
				if(board[xo-i][yo+i] != 0)
				{
					return 0;
				}
			}
		}
	
		/* check the move to bottom left situation*/ 
		if (xf<xo && yf<yo)
		{
			for (i = 1; i < xo-xf; i++)
			{
				if(board[xo-i][yo-i] != 0)
				{
					return 0;
				}
			}
		}
	}
	
	if(symbol_board[xf][yf] == 'K') /*for check condition after we know move is valid*/
	{
		return 5;
	}
	//capture(xo,yo,xf,yf);
	return 1;
}

int check()
{
	int row = whiteKing->x;
	int col = whiteKing->y;
	
	/* Will be checking the white king first then the black king second */
 	/* Looping through all pieces and running the valid move check to the coordinates that the king is at */
	/* Returning 1 for if white is in check, and -1 for if black is in check */
	/*if the valid move for a piece returns 5, that means it is trying to capture the king. the valid move function will return5*/
    /*we cross check all pieces initial conditions w the kings positions for each color and see if calling valid move returns 5. If so, it is in check*/
	if(validmove_Queen(blackQueen->x, blackQueen->y, row, col) == 5)
	{  
		return 1; 
	}
	for(int i = 0; i < 2; i++)
	{ 
		if(validmove_Rook(blackRooks->pos[i][0], blackRooks->pos[i][1], row, col) == 5)
		{
			return 1;
		}
		if(validmove_Bishop(blackBishops->pos[i][0], blackBishops->pos[i][1], row, col) == 5)
		{
			return 1;

		}
		if(validmove_Knight(blackKnights->pos[i][0], blackKnights->pos[i][1], row, col) == 5)
		{
			return 1;
		}
	}

	/* blackKing for pieces other than pawns */
	row = blackKing->x;
	col = blackKing->y;

	if(validmove_Queen(whiteQueen->x, whiteQueen->y, row, col) == 5)
	{
		return -1;

	}

	for(int i = 0; i < 2; i++)
	{ 
		if(validmove_Rook(whiteRooks->pos[i][0], whiteRooks->pos[i][1], row, col) == 5)
		{   
			return -1;
		}
		if(validmove_Bishop(whiteBishops->pos[i][0], whiteBishops->pos[i][1], row, col) == 5)
		{
			return -1;
		}
		if(validmove_Knight(whiteKnights->pos[i][0], whiteKnights->pos[i][1], row, col) == 5)
		{
			return -1;
		}
	}

	/* Pawns now */
	row = whiteKing->x;
	col = whiteKing->y;

	for(int i = 0; i < 8; i++)
	{
		if(validmove_Pawn(blackPawns->pos[i][0], blackPawns->pos[i][1], row, col) == 5)
		{
			return 1;
		}
	}
	if(validmove_King(blackKing -> x, blackKing -> y, row, col) == 5)
	{
		return 1;
	}
	row = blackKing->x;
	col = blackKing->y;
	
	for(int i = 0; i < 8; i++)
	{
		if(validmove_Pawn(whitePawns->pos[i][0], whitePawns->pos[i][1], row, col) == 5)
		{
			return -1;
		}
	}
	if(validmove_King(whiteKing -> x, whiteKing -> y, row, col) == 5)
	{
		return -1;
	}

	/* Return 0 if all if statements checking for checks fails */
	return 0;	
}

int Castling_White(int a)/* a=1 involves the left rook, and a =2 involves the right rook*/
{
	if (symbol_board[0][4] != 'K')
	{
		printf("Invalid move! King is not in correct position.");
		return 0;
	}
	
	if (a == 1)
	{
		if (symbol_board[0][0] != 'R')
		{
			printf("Invalid move! Rook is not in correct position.");
			return 0;
		}

		if (board[0][1] != 0 || board[0][2] != 0 || board[0][3] != 0)
		{
			printf("Invalid move! The path between the rook and the king is blocked.");
			return 0;
		}

		 castling_move = 1;

		changePositionKing(whiteKing, 0, 4, 0, 2);
		changePositionRook(whiteRooks, 0, 0, 0, 3);
		 castling_move = 0;
		
	}
	
	if (a == 2)
	{
		if (symbol_board[0][7] != 'R')
		{
			printf("Invalid move! Rook is not in correct position.");
			return 0;
		}

		if (board[0][5] != 0 || board[0][6] != 0)
		{
			printf("Invalid move! The path between the rook and the king is blocked.");
			return 0;
		}

		 castling_move = 1;
		changePositionKing(whiteKing, 0, 4, 0, 6);
		changePositionRook(whiteRooks, 0, 7, 0, 5);
		 castling_move = 0;

		
	}
	
	return 1;
}

int Castling_Black(int a)/* a=1 involves the left rook, and a =2 involves the right rook*/
{
	if (symbol_board[7][4] != 'K')
	{
		printf("Invalid move! King is not in correct position.");
		return 0;
	}
	
	if (a == 1)
	{
		if (symbol_board[7][0] != 'R')
		{
			printf("Invalid move! Rook is not in correct position.");
			return 0;
		}
		
		if (board[7][1] != 0 || board[7][2] != 0 || board[7][3] != 0)
		{
			printf("Invalid move! The path between the rook and the king is blocked.");
			return 0;
		}

		castling_move = 1;
		changePositionKing(blackKing, 7, 4, 7, 2);
		changePositionRook(blackRooks, 7, 0, 7, 3);
	        castling_move = 0;

		
	}
	
	if (a == 2)
	{
		if (symbol_board[7][7] != 'R')
		{
			printf("Invalid move! Rook is not in correct position.");
			return 0;
		}

		if (board[7][5] != 0 || board[7][6] != 0)
		{
			printf("Invalid move! The path between the rook and the king is blocked.");
			return 0;
		}

		 castling_move = 1;
		
		changePositionKing(blackKing, 7, 4, 7, 6);
		changePositionRook(blackRooks, 7, 7, 7, 5);
		 castling_move = 0;
		
	}
	
	return 1;
}

// Checkmate functions
int checkWKing(int xf, int yf)
{
    int xo = whiteKing->x;
    int yo = whiteKing->y;
    whiteKing->x = xf;
    whiteKing->y = yf;
    board[xo][yo] = 0;
    CreateBoard();
    board[xf][yf] = 1;
    symbol_board[xf][yf] = 'K';

    /* Looping through all pieces and running the valid move check to the coordinates that the king is at */
    /* blackKing for stuff other than pawns */

    if(validmove_Queen(blackQueen->x, blackQueen->y, xf, yf) == 5)
    {
        whiteKing->x = xo;
        whiteKing->y = yo;
        board[xf][yf] = 0;
        symbol_board[xf][yf] = '0';
        CreateBoard();
        return 1;
    }

    for(int i = 0; i < 2; i++)
    {
        if(validmove_Rook(blackRooks->pos[i][0], blackRooks->pos[i][1], xf, yf) == 5)
        {
            whiteKing->x = xo;
            whiteKing->y = yo;
            board[xf][yf] = 0;
            symbol_board[xf][yf] = '0';
            CreateBoard();
            return 1;
        }
        if(validmove_Bishop(blackBishops->pos[i][0], blackBishops->pos[i][1], xf, yf) == 5)
        {
           whiteKing->x = xo;
           whiteKing->y = yo;
           board[xf][yf] = 0;
           symbol_board[xf][yf] = '0';
           CreateBoard();
           return 1;
        }
        if(validmove_Knight(blackKnights->pos[i][0], blackKnights->pos[i][1], xf, yf) == 5)
        {
           whiteKing->x = xo;
           whiteKing->y = yo;
           board[xf][yf] = 0;
           symbol_board[xf][yf] = '0';
           CreateBoard();
           return 1;
        }
    }

	/* Pawns now */
    for(int i = 0; i < 8; i++)
    {
        if(validmove_Pawn(blackPawns->pos[i][0], blackPawns->pos[i][1], xf, yf) == 5)
        {
           whiteKing->x = xo;
           whiteKing->y = yo;
           board[xf][yf] = 0;
           symbol_board[xf][yf] = '0';
           CreateBoard();
           return 1;
        }
    }

    /* Return 0 if all if statements checking for checks fails */
    whiteKing->x = xo;
    whiteKing->y = yo;
    symbol_board[xf][yf] = '0';
    board[xf][yf] = 0;
    CreateBoard();
    return 0;
}


int checkBKing(int xf, int yf)
{
    int xo = blackKing->x;
    int yo = blackKing->y;
    blackKing->x = xf;
    blackKing->y = yf;
    board[xo][yo] = 0;
    //symbol_board[xf][yf] = 'K';
    CreateBoard();
    board[xf][yf] = -1;
    symbol_board[xf][yf] = 'K';

    /* Looping through all pieces and running the valid move check to the coordinates that the king is at */
    /* blackKing for stuff other than pawns */


    if(validmove_Queen(whiteQueen->x, whiteQueen->y, xf, yf) == 5)
    {
       blackKing->x = xo;
       blackKing->y = yo;
       board[xf][yf] = 0;
       symbol_board[xf][yf] = '0';
       CreateBoard();
       return 1;
    }
    for(int i = 0; i < 2; i++)
    {
        if(validmove_Rook(whiteRooks->pos[i][0], whiteRooks->pos[i][1], xf, yf) == 5)
        {
           blackKing->x = xo;
           blackKing->y = yo;
           board[xf][yf] = 0;
           symbol_board[xf][yf] = '0';
           CreateBoard();
           return 1;
        }
        if(validmove_Bishop(whiteBishops->pos[i][0], whiteBishops->pos[i][1], xf, yf) == 5)
        {
           blackKing->x = xo;
           blackKing->y = yo;
           board[xf][yf] = 0;
           symbol_board[xf][yf] = '0';
           CreateBoard();
           return 1;
        }
        if(validmove_Knight(whiteKnights->pos[i][0], whiteKnights->pos[i][1], xf, yf) == 5)
        {
           blackKing->x = xo;
           blackKing->y = yo;
           board[xf][yf] = 0;
           symbol_board[xf][yf] = '0';
           CreateBoard();
           return 1;
        }
	}
	
	/* Pawns now */
    for(int i = 0; i < 8; i++)
    {
        if(validmove_Pawn(whitePawns->pos[i][0], blackPawns->pos[i][1], xf, yf) == 5)
        {
           blackKing->x = xo;
           blackKing->y = yo;
           board[xf][yf] = 0;
           symbol_board[xf][yf] = '0';
           CreateBoard();
           return 1;
        }
    }

    /* Return 0 if all if statements checking for checks fails */
    blackKing->x = xo;
    blackKing->y = yo;
    symbol_board[xf][yf] = '0';
    board[xf][yf] = 0;
    CreateBoard();
    return 0;
}













/*AI MOVE FUNCTIONS HERE*/
int changePositionPawnAI(PAWN *pawn, int xo, int yo, int xf, int yf)
{

	int VMP = validmove_Pawn(xo,yo,xf,yf);
	if(validmove_Pawn(xo,yo,xf,yf)==0)
	{   
		if(validmove_Pawn(xo, yo, xf, yf) == 0)
			printf("Invalid move!");
   
		return 0;
	}
	for(int i = 0; i < 8; i++)
	{
		if(pawn -> pos[i][0] == xo && pawn -> pos[i][1] == yo) /*finds initial position in positions array(which is linked to the pawn structure) and then changes it */
		{
			int store = board[xo][yo];
			int storepiece = board[xf][yf];
			pawn->pos[i][0] = xf;
			pawn->pos[i][1] = yf;
			board[xo][yo] = 0;
			CreateBoard();
			if(check() ==  store)  /* Checking that the white pieces do not let their King be put in check */
			{ 
				pawn->pos[i][0] = xo;
				pawn->pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard();
				return 0;
			}
			pawn->pos[i][0] = xo;
			pawn->pos[i][1] = yo;
			board[xf][yf] = storepiece;
			CreateBoard();
			if(check() == 0) /* if the the king is initially not in check, you can put him into check*/
			{
				capture(xo,yo,xf,yf);
				pawn -> pos[i][0] = xf;
				pawn -> pos[i][1] = yf;
			}
			else if(check() != 0) /*Once the board is in check, you should not be able to leave it unless it is out of check*/
			{	
				pawn -> pos[i][0] = xf;
				pawn -> pos[i][1] = yf;
				CreateBoard();
				if(check() != 0)
				{
					pawn -> pos[i][0] = xo;
					pawn -> pos[i][1] = yo;
					board[xf][yf] = storepiece;
					CreateBoard();
					return 0;
				}
				pawn->pos[i][0] = xo;/*reset things in case of a capture*/
				pawn->pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard();
				capture(xo,yo,xf,yf); /*Capture the piece if need be*/
				pawn -> pos[i][0] = xf;
				pawn -> pos[i][1] = yf;

				
			}

		}	
	}
    if(VMP  == 7) /*white en Passant to the right*/
    {     
		board[xo][yo+1] = 0;
		board[xo][yo] = 0;
        return 1;

    }

    else if(VMP == 8) /*white en Passant to the left*/
    {
		board[xo][yo-1] = 0;
        board[xo][yo] = 0;
        return 1;

    }

    else if(VMP == 9) /*black en Passant to the right*/
    {
		board[xo][yo+1] = 0;
        board[xo][yo] = 0;
        return 1;
    }

    else if(VMP == 10) /*black en Passant to the left*/
    {
		board[xo][yo-1] = 0;
        board[xo][yo] = 0;
        return 1;
    }
    board[xo][yo] = 0;
    return 1;

   
}



/*start of function*/
int  changePositionRookAI(ROOK *rook, int xo, int yo, int xf, int yf)
{       

	/*checks valid move*/
	if (castling_move == 0)
	{
		if(validmove_Rook(xo, yo, xf, yf) == 0)
		{
			if(validmove_Rook(xo, yo, xf, yf) == 0)
				printf("Invalid move!");
			return 0;
	
		}
	}


	/*moves piece if everything is valid*/
	for(int i = 0; i < 2; i++)
	{
		if(rook -> pos[i][0] == xo && rook -> pos[i][1] == yo) /*finds initial position in positions array(which is linked to the pawn structure) and then changes iit */
        {
			int store = board[xo][yo];
			int storepiece = board[xf][yf];
			rook->pos[i][0] = xf;
			rook->pos[i][1] = yf;
			board[xo][yo] = 0;
			CreateBoard();
			if(check() == store)
			{
				rook->pos[i][0] = xo;
				rook->pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard();
				return 0;
			}
			rook->pos[i][0] = xo;
			rook->pos[i][1] = yo;
			board[xf][yf] = storepiece;
			CreateBoard();
			if(check() == 0) /* if the the king is initially not in check, you can put him into check*/
			{
				capture(xo,yo,xf,yf);
				rook -> pos[i][0] = xf;
	   			rook -> pos[i][1] = yf;

			}
			else if(check() != 0) /*Once the board is in check, you should not be able to leave it unless it is out of check*/
			{
	   			rook -> pos[i][0] = xf;
	   			rook -> pos[i][1] = yf;
				CreateBoard();
				if(check() != 0)
				{
					rook -> pos[i][0] = xo;
					rook -> pos[i][1] = yo;
					board[xf][yf] = storepiece;
					return 0;
				}
				rook->pos[i][0] = xo; /*resets board in case of capture*/
				rook->pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard();
			
				capture(xo,yo,xf,yf); /*capture if need be*/
				rook -> pos[i][0] = xf;
	   			rook -> pos[i][1] = yf;


				
			}
		}
	}
	
        board[xo][yo] = 0;
		return 1;
}
/*end of function*/


int changePositionBishopAI(BISHOP *bishop, int xo, int yo, int xf, int yf)
{
    if( validmove_Bishop(xo,yo,xf,yf) == 0)
    {
		if(validmove_Bishop(xo, yo, xf, yf) == 0)
			printf("Invalid move!");

		return 0;
    }

    for(int i = 0; i < 2; i++)
    {
		if(bishop -> pos[i][0] == xo && bishop -> pos[i][1] == yo) /*finds initial position in positions array(which is linked to the pawn structure) and then changes it */
		{
			int store = board[xo][yo];
			int storepiece = board[xf][yf];
			bishop->pos[i][0] = xf;
			bishop->pos[i][1] = yf;
			board[xo][yo] = 0;
			CreateBoard();
			if(check() == store)
			{
				bishop->pos[i][0] = xo;
				bishop->pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard();
				return 0;
			}
			bishop -> pos[i][0] = xo;
			bishop -> pos[i][1] = yo;
			board[xf][yf] = storepiece;
			CreateBoard(); /*resets everything so we can check other possible error conditions*/
			if(check() == 0) /* if the the king is initially not in check, you can put him into check*/
			{      

				capture(xo,yo,xf,yf);
				bishop -> pos[i][0] = xf;
	   			bishop -> pos[i][1] = yf;			

			}
			else if(check() != 0) /*Once the board is in check, you should not be able to leave it unless it is out of check*/
			{       
			
	    			bishop -> pos[i][0] = xf;
	   			bishop -> pos[i][1] = yf;
				CreateBoard();
				if(check() != 0)
				{       
					bishop -> pos[i][0] = xo;
					bishop -> pos[i][1] = yo;
					board[xf][yf] = storepiece;
					return 0;
				}

			        bishop -> pos[i][0] = xo;
				bishop -> pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard(); /*resets everything so we can check for a capture*/

				capture(xo,yo,xf,yf);
				bishop -> pos[i][0] = xf;
	   			bishop -> pos[i][1] = yf;	

			}
		}
    } 
    board[xo][yo] = 0;

    return 1;
}



int changePositionKnightAI(KNIGHT *knight, int xo, int yo, int xf, int yf)
{
	if(validmove_Knight(xo,yo,xf,yf) == 0)
	{
		if(validmove_Knight(xo, yo, xf, yf) == 0)
			printf("Invalid move!");
 
		return 0;
	}
	for(int i = 0; i < 2; i++)
	{
		if(knight -> pos[i][0] == xo && knight -> pos[i][1] == yo) /*finds initial position in positions array(which is linked to the pawn structure) and then changes it */
        {
			int store = board[xo][yo];
			int storepiece = board[xf][yf];
			knight->pos[i][0] = xf;
			knight->pos[i][1] = yf;
			board[xo][yo] = 0;
			CreateBoard();
			if(check() == store)
			{
				knight->pos[i][0] = xo;
				knight->pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard();
				return 0;
			}
			knight -> pos[i][0] = xo;
			knight -> pos[i][1] = yo;
			board[xf][yf] = storepiece;
			CreateBoard();
			if(check() == 0) /* if the the king is initially not in check, you can put him into check*/
			{
				capture(xo,yo,xf,yf);
				knight -> pos[i][0] = xf;
	   			knight -> pos[i][1] = yf;


			}
			else if(check() != 0) /*Once the board is in check, you should not be able to leave it unless it is out of check*/
			{
		    		knight -> pos[i][0] = xf;
	   			knight -> pos[i][1] = yf;
				CreateBoard();
				if(check() != 0)
				{
					knight -> pos[i][0] = xo;
					knight -> pos[i][1] = yo;
					board[xf][yf] = 0;
					return 0;
				}

				knight -> pos[i][0] = xo; /*check for capture*/
				knight -> pos[i][1] = yo;
				board[xf][yf] = storepiece;
				CreateBoard();

				capture(xo,yo,xf,yf); /*if capture valid*/
				knight -> pos[i][0] = xf;
	   			knight -> pos[i][1] = yf;

			}

		}
	}
	board[xo][yo] = 0;
        return 1;
}


int changePositionKingAI(KING *king, int xo, int yo, int xf, int yf)
{
	if (castling_move == 0)
	{
		if(validmove_King(xo, yo, xf, yf) == 0)
		{
			if(validmove_King(xo, yo, xf, yf) == 0)
				printf("Invalid move!");
		    return 0;
		}
	}
	if(king -> x == xo && king -> y == yo)
	{  	
		int store = board[xo][yo];
		int storepiece = board[xf][yf];	
		king->x = xf;
		king->y = yf;
		board[xo][yo] = 0;
		CreateBoard();
		if(check() == store)
		{
			king->x = xo;
			king->y = yo;
			board[xf][yf] = storepiece;
			CreateBoard();
			return 0;
		} 
		king->x = xo;
		king->y = yo;
		board[xf][yf] = storepiece;
		CreateBoard(); /*resets the board*/
		if(check() == 0)
		{
			if(capture(xo,yo,xf,yf) == 6)
				{return 0;}
			king -> x = xf;
			king -> y = yf;
		}
		else if(check() != 0) /*If the board is in check*/
		{
			king  -> x = xf; /*Set the pieces and create the board*/
			king  -> y = yf;
			CreateBoard();
			if(check() != 0) /*If the player moves, and check is still not equal to 0, just move pieces back to inital place and return 0*/
			{
				king -> x = xo;
				king -> y = yo;
				board[xf][yf] = storepiece;
				return 0;
			}
			king->x = xo; /*If the move got player out of check, lets reset the board so we can properly capture a piece*/
			king->y = yo;
			board[xf][yf] = storepiece;
			CreateBoard(); /*resets the board in case there is a capture*/

			if(capture(xo,yo,xf,yf)==6) /*capture the piece first and then change*/
				{return 0;}
			king->x = xf;
			king->y = yf;
		}

	}
	board[xo][yo] = 0;
	return 1;




}



int changePositionQueenAI(QUEEN *queen, int xo, int yo, int xf, int yf)
{
	if(validmove_Queen(xo, yo, xf, yf) == 0)
	{
		if(validmove_Queen(xo, yo, xf, yf) == 0)
			printf("Invalid move!");
	    return 0;
	}
	if(queen -> x == xo && queen -> y == yo)
	{  	 
		int store = board[xo][yo];
		int storepiece = board[xf][yf];
		queen->x = xf;
		queen->y = yf;
		board[xo][yo] = 0;
		CreateBoard();
		if(check() == store)
		{
			queen->x = xo;
			queen->y = yo;
			board[xf][yf] = storepiece;
			CreateBoard();
			return 0;
		}
		queen->x = xo;
		queen->y = yo;
		board[xf][yf] = storepiece;
		CreateBoard(); /*resets the board*/

		if(check() == 0)
		{
			capture(xo,yo,xf,yf);
			queen -> x = xf;
			queen -> y = yf;
		}
		else if(check() != 0)
		{
			queen  -> x = xf;
			queen  -> y = yf;
			CreateBoard();
			if(check() != 0)
			{
				queen -> x = xo;
				queen -> y = yo;
				board[xf][yf] = storepiece;
				return 0;
			}
			queen->x = xo;
			queen->y = yo;
			board[xf][yf] = storepiece;
			CreateBoard(); /*resets the board in case of capture*/

			capture(xo,yo,xf,yf);
			queen -> x = xf;
			queen -> y = yf;



		}

	}
	board[xo][yo] = 0;
	return 1;
}
