/* AI.c File 
 * Name: Jonathan Sugijoto
 * ID: 5835060
*/
#include "AI.h"

/* Handle a Human v. AI game */
void Human_VS_AI(int board[3][3], PLAYER *player1, PLAYER *player2){
	int level;
	printf("What level of difficulty would you like to play against?\n");
	printf("Enter 'Z' to take back a move you have made\n");
	printf("Select from:\n");
	printf("1. Inky (level 1)\n");
	printf("2. Blinky (level 2)\n");
	printf("3. Pinky (level 3)\n");
	printf("4. Clyde (level 4)\n");
	printf("Choose your AI: ");
	scanf("%d", &level);
	switch(level){
		case 1:
			printf("Playing against Inky...\n");
			Inky(board, player1, player2);
			break;
		case 2:
			printf("Playing against Blinky...\n");
			Blinky(board, player1, player2);
			break;
		case 3:
			printf("Playing against Pinky...\n");
			Pinky(board, player1, player2);
			break;
		case 4:
			printf("Playing against Clyde...\n");
			/* Clyde(board, player1, player2); */
			break;
	}
}



void Inky(int board[3][3], PLAYER *player1, PLAYER *player2) /* Human is always player1 and AI is player2 */
{
	MOVE_LIST *recorded_moves;
	recorded_moves = calloc(11, sizeof(MOVE_LIST));
	for(int x  = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			recorded_moves->board[x][y] = 0;
		}
	}
	printf("Human v. Inky game started\n");
	print_fun(board, player1, player2);
	int tie=1;
	int reprint = 0;
	int reset = 0;
	int reply = 0;
	while((is_there_empty_cell(board)))
	{
		if(reprint == 1){
			print_fun(board, player1, player2);
			reprint = 0;
		}
		if(reply == 1)
			printf("Type 'Z' to take back the AI's winning move");
		printf("Player 1, please choose your move:");
		char *player_move = entered_one_char(board, 1);
		if(*(player_move) == 'Z'){
			struct MOVE_LIST *temp;
			temp = recorded_moves;
			reset = takeBack(recorded_moves);
			reprint = 1;
			if(reset == 0){
				while(temp->next != NULL){
					temp = temp->next;
				}
				for(int x = 0; x < 3; x++){
					for(int y = 0; y < 3; y++){
						board[x][y] = temp->board[x][y];
					}
				}
			}
			else{
				for(int x=0; x<3;x++){
					for(int y=0; y<3;y++){
						board[x][y] = 0;
					}
				}
				reset = 0;
			}
			continue;
		}
		
		append(&recorded_moves, board, player_move);
		free(player_move);
		print_fun(board, player1, player2);
		int win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if (win_flag == 2)
			{
				printf("AI wins! Game Over!\n\n");
			}
			tie=0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;
		printf("AI is choosing its move:\n");
        int foundMove = 0;
		/* Loops through looking for first open spot, then places marker */
		for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				if (board[i][j] == 0)
				{
                    board[i][j] = 2;
                    foundMove = 1;
					if(i == 0)
						*player_move = 'C';
					else if(i == 1)
						*player_move = 'B';
					else if(i == 2)
						*player_move = 'A';
					if(j == 0)
						*(player_move+1) = '1';
					else if(j == 1)
						*(player_move+1) = '2';
					else if(j == 2)
						*(player_move+1) = '3';
					append(&recorded_moves, board, player_move);
					free(player_move);
					break;
				}
			}

            if(foundMove)
            {
                break;
            }
		}
		print_fun(board, player1, player2);
		int reply = 0;
		win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if (win_flag == 2)
			{
				printf("AI wins! Game Over!\n\n");
				printf("Extra chance! Would you like to take back your move?(1 for yes, 0 for no): ");
				scanf("%d", &reply);
				if(reply == 1){
					struct MOVE_LIST *temp;
					temp = recorded_moves;
					reset = takeBack(recorded_moves);
					reprint = 1;
					if(reset == 0){
						while(temp->next != NULL){
							temp = temp->next;
						}
						for(int x = 0; x < 3; x++){
							for(int y = 0; y < 3; y++){
								board[x][y] = temp->board[x][y];
							}
						}	
					}
					else{
						for(int x=0; x<3;x++){
							for(int y=0; y<3;y++){
							board[x][y] = 0;
							}
						}
					reset = 0;
					}
				continue;
				}		
			}
			tie=0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;
	}
	if (tie==1)
	{
		printf("The game is a tie!\n");
	}
	reply = 0;
	if(reply == 1){
			
	}
	printf("\nWould you like to save a replay of this game?(1 for yes, 0 for no): \n");
	scanf("%d", &reply);
	if(reply == 1)
		replay(recorded_moves, player1, player2);	

	freeList(recorded_moves);
}

void Blinky(int board[3][3], PLAYER *player1, PLAYER *player2){
	MOVE_LIST *recorded_moves;
	recorded_moves = calloc(11, sizeof(MOVE_LIST));
	for(int x=0; x<3; x++){
		for(int y=0; y<3; y++){
			recorded_moves->board[x][y] = 0;	
		}
	}
	printf("Human v. Blinky game started\n");
	print_fun(board, player1, player2);
	int tie=1;
	int reprint = 0;
	int reset = 0;
	while((is_there_empty_cell(board)))
	{
		if(reprint == 1){
			print_fun(board, player1, player2);
			reprint = 0;
		}
		printf("Player 1, please choose your move:");
		char *player_move = entered_one_char(board,1);
		if(*player_move == 'Z'){
			struct MOVE_LIST *temp;
			temp = recorded_moves;
			reset = takeBack(recorded_moves);
			reprint = 1;
			if(reset != 1){
				while(temp->next != NULL){
					temp = temp->next;
				}
				for (int x = 0; x < 3; x++){
					for(int y = 0; y < 3; y++){
						board[x][y] = temp->board[x][y];
					}
				}
			}
			else{
				for(int x=0;x<3;x++){
					for(int y=0;y<3;y++){
						board[x][y] = 0;
					}
				}
				reset = 0;
			}
			continue;
		}
		append(&recorded_moves, board, player_move);
		free(player_move);
		print_fun(board, player1, player2);
		int win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if (win_flag == 2)
			{
				printf("AI wins! Game Over!\n\n");
			}
			tie=0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;

		printf("AI is choosing its move:\n");
        int foundMove = 0;
		srand(time(NULL));
		while(foundMove == 0){
			/* finding random spot and initializing it to a marker, then saving that move */
			int xspot = ((double)rand() / RAND_MAX)*3;
			int yspot = ((double)rand()/RAND_MAX)*3;
			if (board[xspot][yspot] == 0)
			{
           		board[xspot][yspot] = 2;
                foundMove = 1;
				if(xspot == 0)
					*player_move = 'C';
				else if(xspot == 1)
					*player_move = 'B';
				else if(xspot == 2)
					*player_move = 'A';
				if(yspot == 0)
					*(player_move+1) = '1';
				else if(yspot == 1)
					*(player_move+1) = '2';
				else if(yspot == 2)
					*(player_move+1) = '3';
				break;
			}

            if(foundMove)
            {
                break;
            }
		}
		append(&recorded_moves, board, player_move);
		print_fun(board, player1, player2);
		int reply = 0;
		win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if (win_flag == 2)
			{
				printf("AI wins! Game Over!\n\n");
				printf("Extra chance! Would you like to take back your move?(1 for yes, 0 for no): ");
				scanf("%d", &reply);
				if(reply == 1){
					struct MOVE_LIST *temp;
					temp = recorded_moves;
					reset = takeBack(recorded_moves);
					reprint = 1;
					if(reset == 0){
						while(temp->next != NULL){
							temp = temp->next;
						}
						for(int x = 0; x < 3; x++){
							for(int y = 0; y < 3; y++){
								board[x][y] = temp->board[x][y];
							}
						}	
					}
					else{
						for(int x=0; x<3;x++){
							for(int y=0; y<3;y++){
							board[x][y] = 0;
							}
						}
					reset = 0;
					}
				continue;
				}
			}
			tie=0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;
	}
	if (tie==1)
	{
		printf("The game is a tie!\n");
	}
	/* Replay file created */
	int reply;
	printf("Would you like to save a replay of this game?(1 for yes, 0 for no): ");
	scanf("%d", &reply);
	if(reply == 1)
		replay(recorded_moves, player1, player2);
	freeList(recorded_moves);
}

void Pinky(int board[3][3], PLAYER *player1, PLAYER *player2){
	MOVE_LIST *recorded_moves;
	recorded_moves = calloc(11, sizeof(MOVE_LIST));
	/* Start with empty board in order to be able to take back until here */
	for(int x=0; x<3; x++){
		for(int y=0; y<3; y++){
			recorded_moves->board[x][y] = 0;	
		}
	}
	printf("Human v. Pinky game started\n");
	print_fun(board, player1, player2);
	int tie=1;
	int reprint = 0;
	int reset = 0;
	while((is_there_empty_cell(board)))
	{
		if(reprint == 1){
			print_fun(board, player1, player2);
			reprint = 0;
		}
		printf("Player 1, please choose your move:");
		char *player_move = entered_one_char(board,1);
		if(*player_move == 'Z'){
			struct MOVE_LIST *temp;
			temp = recorded_moves;
			reset = takeBack(recorded_moves);
			reprint = 1;
			if(reset != 1){
				while(temp->next != NULL){
					temp = temp->next;
				}
				for (int x = 0; x < 3; x++){
					for(int y = 0; y < 3; y++){
						board[x][y] = temp->board[x][y];
					}
				}
			}
			else{
				for(int x=0;x<3;x++){
					for(int y=0;y<3;y++){
						board[x][y] = 0;
					}
				}
				reset = 0;
			}
			continue;
		}
		append(&recorded_moves, board, player_move);
		print_fun(board, player1, player2);
		int reply = 0;
		int win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if(win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if(win_flag == 2)
			{
				printf("AI wins! Game Over!\n\n");
				printf("Extra chance! Would you like to take back your move?(1 for yes, 0 for no): ");
				scanf("%d", &reply);
				if(reply == 1){
					struct MOVE_LIST *temp;
					temp = recorded_moves;
					reset = takeBack(recorded_moves);
					reprint = 1;
					if(reset == 0){
						while(temp->next != NULL){
							temp = temp->next;
						}
						for(int x = 0; x < 3; x++){
							for(int y = 0; y < 3; y++){
								board[x][y] = temp->board[x][y];
							}
						}	
					}
					else{
						for(int x=0; x<3;x++){
							for(int y=0; y<3;y++){
							board[x][y] = 0;
							}
						}
					reset = 0;
					}
				continue;
				}
			}
			tie = 0;
			break;
		}
		else if(is_there_empty_cell(board)==0)
			break;

		printf("AI is choosing its move:\n");
		int foundMove = 0;
		int xplace, yplace;
		int found_place = 0;
		while(foundMove == 0){
			for(int x = 0; x < 3; x++){
				for(int y = 0; y < 3; y++){
					/* Set default marker if nothing can make AI lose yet */
					if(board[x][y] == 0){
						if(found_place == 0){
							xplace = x;
							yplace = y;
							found_place = 1;
						}
						board[x][y] = 1;
						if(IsWin(board)){
							board[x][y] = 2;
							foundMove = 1;
							/* Store the player_move to append to linked list */
							if(x==0)
								*player_move = 'C';
							else if(x==1)
								*player_move = 'B';
							else if(x==2)
								*player_move = 'A';
							if(y==0)
								*(player_move+1) = '1';
							else if(y==1)
								*(player_move+1) = '2';
							else if(y==2)
								*(player_move+1) = '3';
							break;
						}
						else
						board[x][y] = 0;
					}
				}
			if(foundMove == 1)
				break;
			}
			if(foundMove != 1){
				board[xplace][yplace] = 2;
				foundMove=1;
			}
		}
		append(&recorded_moves, board, player_move);
		free(player_move);
		print_fun(board, player1, player2);
		win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if (win_flag == 2)
			{
				printf("AI wins! Game Over!\n\n");
			}
			tie=0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;
	}
	if (tie==1)
	{
		printf("The game is a tie!\n");
	}
	/* Create replay.txt file */
	int reply = 0;
	printf("Would you like to save a replay of this game?(1 for yes, 0 for no): ");
	scanf("%d", &reply);
	if(reply == 1)
		replay(recorded_moves, player1, player2);
	freeList(recorded_moves);
}

