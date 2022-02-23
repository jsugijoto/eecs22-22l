/* AI.h File 
 * Name: Jonathan Sugijoto
 * ID: 58535060
*/

#ifndef AI_H
#define AI_H

#include <stdio.h>
#include <time.h>

#include "Player.h" 
#include "Board.h"

void Human_VS_AI(int board[3][3], PLAYER *player1, PLAYER *player2);

void Inky(int board[3][3], PLAYER *player1, PLAYER *player2); /* Human is always player1 and AI is player2 */

void Blinky(int board[3][3], PLAYER *player1, PLAYER *player2);

void Pinky(int board[3][3], PLAYER *player1, PLAYER *player2);


#endif
