/* AI.h  File v1
 *   * Description: AI.h is a file that holds the declarations for the AI functions and data structures
 *   * Team 18 Members: Jonathan Sugijoto, Devin Reyes, Eesha Jain, Michael Nguyen, Jixin Gong
 *   * Last Updated: 4/14/2021
 *   */

#ifndef AI_H
#define AI_H

#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "game.h"

int AI(int color, MVLIST *lst);

void Append_AI(int row, int col, int rowf, int colf, int player, MVLIST *lst);

#endif
