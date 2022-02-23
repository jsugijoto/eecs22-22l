 /* board.h File v1
 *  *  * Description: board.h is a file that holds declarations for any function regarding the board/pieces
 *   *   * Team 18 Members: Jonathan Sugijoto, Devin Reyes, Eesha Jain, Michael Nguyen, Jixin Gong
 *    *   * Last Updated: 4/14/2021
 *     *   */

#ifndef board_h
#define board_h

typedef struct
{
	char board[8][8];
	int row;
        int col;
}CHESS_BOARD;

typedef struct
{
	int pos[8][2];
	char color;
	char piece;
	char name[3];
	//strcpy(name, strcat(color,piece));

}PAWN;

typedef struct
{
	int pos[2][2];
	char color;
	char piece;
        char name[3];
        //strcpy(name, strcat(color,piece));

}ROOK;

typedef struct
{
	int pos[2][2];
	char color;
        char piece;
        char name[3];
        //strcpy(name, strcat(color,piece));

}BISHOP;

typedef struct
{
	int pos[2][2];
        char color;
        char piece;
        char name[3];
        //strcpy(name, strcat(color,piece));

}KNIGHT;

typedef struct
{
	int x;
        int y;
	char color;
	char piece;
        char name[3];
        //strcpy(name, strcat(color,piece));
}QUEEN;

typedef struct
{
	int x;
        int y;
	char color;
        char piece;
	char name[3];
        //strcpy(name, strcat(color,piece));
}KING;

/* figure out what the piece is using the piece name, then based on that
 *  * call the changePosition function for that piece
 *   * and iterate through the positions array of that piece
 *    * and then change the position the the users desired choice if valid
 *     * */



PAWN *CreatePawn(char color, char *name);
int changePositionPawn(PAWN *pawn, int xo, int yo, int xf, int yf);
int changePositionPawnAI(PAWN *pawn, int xo, int yo, int xf, int yf);
void deletePawn(PAWN *pawn);
int validmove_Pawn(int xo, int yo, int xf, int yf);

ROOK *CreateRook(char color, char *name);
int changePositionRook(ROOK *rook, int xo, int yo, int xf, int yf);
int  changePositionRookAI(ROOK *rook, int xo, int yo, int xf, int yf);
void deleteRook(ROOK *rook);
int validmove_Rook(int xo, int yo, int xf, int yf);


BISHOP *CreateBishop(char color, char *name);
int changePositionBishop(BISHOP *bishop, int xo, int yo, int xf, int yf);
int changePositionBishopAI(BISHOP *bishop, int xo, int yo, int xf, int yf);
void deleteBishop(BISHOP *bishop);
int validmove_Bishop(int xo, int yo, int xf, int yf);

KNIGHT *CreateKnight(char color, char *name);
int changePositionKnight(KNIGHT *knight, int xo, int yo, int xf, int yf);
int changePositionKnightAI(KNIGHT *knight, int xo, int yo, int xf, int yf);
void deleteKnight(KNIGHT *knights);
int validmove_Knight(int so, int yo, int xf, int yf);

QUEEN *CreateQueen(char color, char *name);
int changePositionQueen(QUEEN *queen, int xo, int yo, int xf, int yf);
int changePositionQueenAI(QUEEN *queen, int xo, int yo, int xf, int yf);
void deleteQueen(QUEEN *queen);
int validmove_Queen(int xo, int yo, int xf, int yf);

KING *CreateKing(char color, char *name);
int changePositionKing(KING *king, int xo, int yo, int xf, int yf);
int changePositionKingAI(KING *king, int xo, int yo, int xf, int yf);
void deleteKing(KING *king);
int validmove_King(int xo, int yo, int xf, int yf);

int Castling_White(int a);
int Castling_Black(int a);

int hold[8][8];
int color[8][8];
int piece[8][8];
int board[8][8];
char symbol_board[8][8];

extern int castling_move;

//checkmate
int validmove_King2(int xo, int yo, int xf, int yf);
 
int checkWKing(int xf, int yf);

int checkBKing(int xf, int yf);

int check();

PAWN *blackPawns;
PAWN *whitePawns; 
ROOK *blackRooks;
ROOK *whiteRooks;
KNIGHT *blackKnights;
KNIGHT *whiteKnights;
BISHOP *blackBishops;
BISHOP *whiteBishops;
QUEEN *blackQueen;
QUEEN *whiteQueen;
KING *blackKing;
KING *whiteKing;

void innitBoard();
void CreateBoard();
void getBoard(PAWN *blackPawns, PAWN *whitePawns, ROOK *blackRooks, ROOK *whiteRooks, KNIGHT *blackKnights, KNIGHT *whiteKnights,
BISHOP *blackBishops, BISHOP *whiteBishops, QUEEN *blackQueen, QUEEN *whiteQueen, KING *blackKing, KING *whiteKing);
int capture(int xo, int yo, int xf, int yf);
#endif
