/*----------------------------------*/
/* Jonathan Sugijoto EECS 22        */
/* ID: 58535060                     */
/* Tic Tac Whoa Implementation in C */
/*----------------------------------*/

#include <stdio.h>
#include <string.h>

#define colorStart "\x1b["
#define colorReset "\x1b[0m"

/* Default symbols are X and O, with default win condition being 3 */
char symbol1 = 'X';
char symbol2 = 'O';
int winCondition = 3;
char player1color[8] = "\x1b[0m"; 
char player2color[8] = "\x1b[0m";

void clearBoard(int boardSize, char board[boardSize][boardSize]);
void human_v_human(int boardSize, char board[boardSize][boardSize]);
void human_v_ai(int boardSize, char board[boardSize][boardSize]);
char checkBoard(int boardSize, char board[boardSize][boardSize]);
void player1(int boardSize, char board[boardSize][boardSize]);
void player2(int boardSize, char board[boardSize][boardSize]);
void displayBoard_v2(int boardSize, char board[boardSize][boardSize]);
int settings(int boardSize);

int main(void){
	int boardSize = 3; /* Default will be 3 */
	char board[boardSize][boardSize];
	clearBoard(boardSize, board);
	int exit = 0;
	while(exit == 0){ /* Makes sure that the menu loops when game is complete */
		int select;
		printf("\nWelcome to Secure-Tic-Tac-Whoa!");
		printf("\n1. Start New Game (Human v. Human)");
		printf("\n2. Start New Game (Human v. AI)");
		printf("\n3. Game Settings");
		printf("\n4. Exit Game");
		printf("\nChoose Option: ");
		scanf("%d", &select);
		
		switch (select){
			case 1:
				printf("\nHuman v. Human Game Started\n");
				human_v_human(boardSize, board);
				break;

			case 2:
				printf("Human v. AI Game Started\n");
				human_v_ai(boardSize, board);
				break;

			case 3:
				printf("Entering the Settings Menu...\n");
				boardSize = settings(boardSize);
				break;

			default: 
				exit = 1;
				printf("Exiting...\n");
				break;
		}
		
	}
	return 0;

}

int settings(int boardSize){
	int size = boardSize;
	int select;
	int selectColor;
	char red[8] = "\x1b[31m";
	char blue[8] = "\x1b[34m";
	char yellow[8] = "\x1b[33m";
	char white[8] = "\x1b[0m";
	printf("Settings Menu");
	printf("\n1. Change the symbols!");
	printf("\n2. Change the colors of the symbols!");
	printf("\n3. Change the board size! (Up to 10x10): ");
	printf("\n4. Change the win condition!(Change this AFTER changing board size): ");
	printf("\n5. Back");
	printf("\nChoose Option: ");
	scanf("%d", &select);
	switch(select){
		case 1:
			printf("Change the Marker");
			printf("\nWhat would you like Player 1's symbol to be?: ");
			scanf("%s", &symbol1);
			printf("\nWhat would you like Player 2's symbol to be?: ");
			scanf("%s", &symbol2);			
			break;

		case 2:
			printf("What color would you like Player 1 to be?: ");
			printf("\n1.%s31mRed%s", colorStart, colorReset);
			printf("\n2.%s34mBlue%s", colorStart, colorReset);
			printf("\n3.%s33mYellow%s", colorStart, colorReset);
			printf("\n4.%s0mWhite%s", colorStart, colorReset);
			printf("\nChoose option: ");
			scanf("%d", &selectColor);
			switch(selectColor){
				case 1:
					strcpy(player1color, red);
					break; 
				case 2: 
					strcpy(player1color, blue);			
					break;
				case 3:
					strcpy(player1color, yellow);
					break;
				case 4: 
					strcpy(player1color, white);
					break;
			}
			printf("What color would you like Player 2 to be?: ");
			printf("\n1.%s31mRed%s", colorStart, colorReset);
			printf("\n2.%s34mBlue%s", colorStart, colorReset);
			printf("\n3.%s33mYellow%s", colorStart, colorReset);
			printf("\n4.%s0mWhite%s", colorStart, colorReset);
			printf("\nChoose option: ");
			scanf("%d", &selectColor);
			switch(selectColor){
				case 1: 
					strcpy(player2color, red);
					break;
				case 2:
					strcpy(player2color, blue);
					break;
				case 3: 
					strcpy(player2color, yellow);
					break;
				case 4: 
					strcpy(player2color, white);
					break;
			}
			break;

		case 3:
			printf("What would you like the NxN size of the board to be (Resets win condition to N)?: N =  ");
			scanf("%d", &size);
			winCondition = size;
			break;
		
		case 4:
			printf("What would you like the win condition to be? (x in a row): ");
			scanf("%d", &winCondition);
			break;
		
		case 5:
			break;
	}

	return size;
	 
}

void clearBoard(int boardSize, char board[boardSize][boardSize]){
	int i, j;
	for(i = 0; i < boardSize; i++){
		for(j = 0; j < boardSize; j++){
			board[i][j] = ' ';
		}
	}

}


void displayBoard_v2(int boardSize, char board[boardSize][boardSize]){
	char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	int numbers[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for(int i = 0; i < boardSize; i++){ /* Row */
		printf("%c ", alphabet[boardSize - i - 1]); 
		for(int j = 0; j < boardSize; j++){ /* Column */
			if(j == (boardSize - 1))
				if(board[i][j] == symbol1)
					printf(" %s%c%s", player1color, board[i][j], colorReset);
				else
					printf(" %s%c%s", player2color, board[i][j], colorReset);
			else
				if(board[i][j] == symbol1)
					printf(" %s%c%s |", player1color, board[i][j], colorReset);
				else
					printf(" %s%c%s |", player2color, board[i][j], colorReset);
		}
		if(i != (boardSize - 1)){
			printf("\n ");
			for(int i = 0; i < boardSize; i++)
				printf("----");
			printf("\n");
		}
		if(i == (boardSize - 1)){
			printf("\n  ");
			for(int j = 0; j < boardSize; j++){
				if(j < 9)
					if(j == 0)
						printf(" 0%d  ", numbers[j]);
					else
						printf("0%d  ", numbers[j]);
				else
					printf("%d  ", numbers[j]);
			}
			printf("\n");
		}
	}	
}

void human_v_human(int boardSize, char board[boardSize][boardSize]){
	int winner = 0;
	char victor = ' ';
	char select[3];
	int row, col;
	clearBoard(boardSize, board);
	displayBoard_v2(boardSize, board);
	while(winner == 0){
		printf("Player %c, please choose your move: ", symbol1);
		scanf("%s", select);
		printf("Player %c has chosen %s\n", symbol1, select);
		row = (int) boardSize - 1 - (select[0] - 65); /* boardSize - 1 - (value) because need to reverse the direction of ABC */
		if(select[2] == 0)
			col = (int) select[1] - 49;
		else
			col = (int) 9;
		if(board[row][col] > 32){ /* >32 Means that the space is filled by something that we can type*/
			while(board[row][col] > 32){
				printf("Invalid Input, please place your marker on an open slot: ");
				scanf("%s", select);
				printf("Player %c has chosen %s\n", symbol1, select);
				row = (int) boardSize - 1 - (select[0] - 65);
				if(select[2] == 0)
					col = (int) select[1] - 49;
				else
					col = (int) 9;
			}
		}
		if(board[row][col] > 32){ /* >32 Means that the space is filled by something that we can type*/
			while(board[row][col] > 32){
				printf("Invalid Input, please place your marker on an open slot: ");
				scanf("%s", select);
				printf("Player %c has chosen %s\n", symbol1, select);
				row = (int) boardSize - 1 - (select[0] - 65);
				if(select[2] == 0)
					col = (int) select[1] - 49;
				else
					col = (int) 9;
			}
		}
		board[row][col] = symbol1;
		displayBoard_v2(boardSize, board);
		victor = checkBoard(boardSize, board);
		if(victor == symbol1 || victor == symbol2){
			winner = 1;
			printf("Player %c has won!\n", victor);
			break;
		}
		if(victor == 'T'){
			winner = 1;
			printf("It's a tie!");
			break;
		}

		printf("Player %c, please choose your move: ", symbol2);
		scanf("%s", select);
		printf("Player %c has chosen %s\n", symbol2, select);
		row = (int) boardSize - 1 - (select[0] - 65);
		if(select[2] == 0)
			col = (int) select[1] - 49;
		else
			col = (int) 9;
		if(board[row][col] > 32){
			while(board[row][col] > 32){
				printf("Invalid Input, please place your marker on an open slot: ");
				scanf("%s", select);
				printf("Player %c has chosen %s\n", symbol2, select);
				row = (int) boardSize - 1 - (select[0] - 65);
				if(select[2] == 0)
					col = (int) select[1] - 49;
				else
					col = (int) 9;
			}
		}
		board[row][col] = symbol2;
		displayBoard_v2(boardSize, board);
		victor = checkBoard(boardSize, board);
		if(victor == symbol1 || victor == symbol2){
			winner = 1;
			printf("Player %c has won!\n", victor);
			break;
		}
		if(victor == 'T'){
			winner = 1;
			printf("It's a tie!");
			break;
		}
	 		
	}		
}

char checkBoard(int boardSize, char board[boardSize][boardSize]){
	/* Assign X to be 1 and O to be -1, whenever a 3 in a row adds up to 3 or -3 you have your winner. */
	int i = 0;
	int j = 0;
	int sum = 0;
	int winner = 0;
	char isWinner;
	for(j = 0; j < boardSize; j++){ /* Checking columns */
		sum = 0;
		for(i = 0; i < boardSize; i++){
			if(board[i][j] == symbol1)
				sum = 1 + sum;
			if(board[i][j] == symbol2)
				sum =  -1 + sum;
			}
		if(sum == winCondition){
			winner = 1;
			isWinner = symbol1;
			break;
		}
		if(sum == (-1 * winCondition)){
			winner = 1;
			isWinner = symbol2;
			break;
		}
	}
	for(i = 0; i < boardSize; i++){ /* Checking rows */
		sum = 0;
		if(winner == 1)
			break;
		for(j = 0; j < boardSize; j++){
			if(board[i][j] == symbol1)
				sum = 1 + sum;
			if(board[i][j] == symbol2)
				sum =  -1 + sum;
			}
		if(sum == winCondition){
			winner = 1;
			isWinner = symbol1;
			break;
		}
		if(sum == (-1 * winCondition)){
			winner = 1;
			isWinner = symbol2;
			break;
		}
	}
	sum = 0;
	for(i = 0; i < boardSize; i++){ /* Checking primary diagonal */
		if(winner == 1)
			break;
		for(j = 0; j < boardSize; j++){
			if(i == j){
				if(board[i][j] == symbol1)
					sum = 1 + sum;
				if(board[i][j] == symbol2)
					sum =  -1 + sum;
			}
		}
		if(sum == winCondition){
			winner = 1;
			isWinner = symbol1;
			break;
		}
		if(sum == (-1 * winCondition)){
			winner = 1;
			isWinner = symbol2;
			break;
		}
	}
	sum = 0;
	for(i = 0; i < boardSize; i++){ /* Checking secondary diagonal */
		if(winner == 1)
			break;
		for(j = 0; j < boardSize; j++){
			if((i + j) == (boardSize-1)){
				if(board[i][j] == symbol1)
					sum = 1 + sum;
				if(board[i][j] == symbol2)
					sum =  -1 + sum;
			}
		}
		if(sum == (1 * winCondition)){
			winner = 1;
			isWinner = symbol1;
			break;
		}
		if(sum == (-1 * winCondition)){
			winner = 1;
			isWinner = symbol2;
			break;
		}
	}
	
	sum = 0;
	/* This section checks from the bottom left to the top right diagonals */
	int max = (2 * boardSize) - 2;

	for(i = 0; i <= max;  i++){
		for(j = 0; j <= i; j++){
			int l = i - j;
			if(l < boardSize && j < boardSize){
				if(board[l][j] == symbol1)
					sum = sum + 1;
				if(board[l][j] == symbol2)
					sum = sum - 1;
			}
			if(sum == (1 * winCondition)){
				winner = 1;
				isWinner = symbol1;
				break;
			}
			if(sum == (-1 * winCondition)){
				winner = 1;
				isWinner = symbol2;
				break;
			}
		
		}
		sum = 0;
	}

	for(i = 0; i <= max; i++){
		for(j = 0; j <= i; j++){
			int l = i - j;
			int opposite = boardSize - l;
			if(opposite >= 0 && opposite < boardSize && j < boardSize){
				if(board[opposite][j] == symbol1)
					sum = sum + 1;
				if(board[opposite][j] == symbol2)
					sum = sum - 1;
			}	
			if(sum == (1 * winCondition)){
				winner = 1;
				isWinner = symbol1;
				break;
			}
			if(sum == (-1 * winCondition)){
				winner = 1;
				isWinner = symbol2;
				break;
			}
		}
		sum = 0;
	}
	
	int done = 1;
	if(winner != 1){ /* Checking for a completely filled board */
		for(i = 0; i < boardSize; i++){
			for(j = 0; j < boardSize; j++){
				if(board[i][j] == ' ')
					done = 0; 
			}
		}
		if(done == 1)
			isWinner = 'T';
	}
	return isWinner;
}

void human_v_ai(int boardSize, char board[boardSize][boardSize]){
	int player = 1;
	printf("Would you like to be Player 1 or Player 2? (Default is Player 1): ");
	scanf("%d", &player);
	
	switch(player){
		case 1:
			clearBoard(boardSize, board);
			player1(boardSize, board);
			break;
		case 2:
			clearBoard(boardSize, board);
			player2(boardSize, board);
			break;
	}
}

void player1(int boardSize, char board[boardSize][boardSize]){
	int winner = 0;
	char victor = ' ';
	char select[3];
	int row, col;
	int i, j;
	displayBoard_v2(boardSize, board);

	while(winner == 0){
		printf("Player %c, please choose your move: ", symbol1);
		scanf("%s", select);
		printf("Player %c has chosen %s\n", symbol1, select);
		row = (int) boardSize - 1 - (select[0] - 65); /* 2 - (value) because need to reverse the direction of ABC */
		if(select[2] == 0)
			col = (int) select[1] - 49;
		else
			col = (int) 9;

		if(board[row][col] > 32){ /* >32 Means that the space is filled by something that we can type*/
			while(board[row][col] > 32){
				printf("Invalid Input, please place your marker on an open slot: ");
				scanf("%s", select);
				printf("Player %c has chosen %s\n", symbol1, select);
				row = (int) boardSize - 1 - (select[0] - 65);
				if(select[2] == 0)
					col = (int) select[1] -49;
				else
					col = (int) 9;

			}
		}
		board[row][col] = symbol1;
		displayBoard_v2(boardSize, board);
		victor = checkBoard(boardSize, board);
		if(victor == symbol1 || victor == symbol2){
			winner = 1;
			printf("Player %c has won!\n", victor);
			break;
		}
		if(victor == 'T'){
			winner = 1;
			printf("It's a tie!");
			break;
		}
		
		/* From here is the AI picking the first available slot and inputting in O */
		int placed = 0;
		for(i = 0; i < boardSize; i++){
			for(j = 0; j < boardSize; j++){
				if(board[boardSize - 1 -i][j] == ' '){
					board[boardSize - 1 -i][j] = 'O';
					placed = 1;		 /* Extra 'boolean' to quit the loop as soon as AI places a marker */
					break;
				}
			}
			if(placed == 1)
				break;		
		}
		printf("The computer made its move!\n");
		displayBoard_v2(boardSize, board);
		victor = checkBoard(boardSize, board);
		if(victor == symbol1 || victor == symbol2){
			winner = 1;
			printf("Player %c has won!\n", victor);
			break;
		}
		if(victor == 'T'){
			winner = 1;
			printf("It's a tie!");
			break;
		}
	}

}

void player2(int boardSize, char board[boardSize][boardSize]){
	int winner = 0;
	char victor = ' ';
	char select[3];
	int row, col;
	int i, j;

	while(winner == 0){
		int placed = 0;
		for(i = 0; i < boardSize; i++){
			for(j = 0; j < boardSize; j++){
				if(board[boardSize - 1 -i][j] == ' '){
					board[boardSize - 1 -i][j] = symbol1;
					placed = 1; /* Extra 'boolean' to quit the loop as soon as AI places a marker */
					break;
				}
			}
			if(placed == 1)
				break;		
		}
		displayBoard_v2(boardSize, board);
		victor = checkBoard(boardSize, board);
		if(victor == symbol1 || victor == symbol2){
			winner = 1;
			printf("Player %c has won!\n", victor);
			break;
		}
		if(victor == 'T'){
			winner = 1;
			printf("It's a tie!");
			break;
				printf("Invalid Input, please place your marker on an open slot: ");
				scanf("%s", select);
				printf("Player %c has chosen %s\n", symbol2, select);
				row = (int) boardSize - 1 - (select[0] - 65);
				if(select[2] == 0)
					col = (int) select[1] - 49;
				else
					col = (int) 9;

		}
		printf("Player %c, please choose your move: ", symbol2);
		scanf("%s", select);
		printf("Player %c has chosen %s\n", symbol2, select);
		row = (int) boardSize - 1 - (select[0] - 65); /* 2 - (value) because need to reverse the direction of ABC */
		if(select[2] == 0)
			col = (int) select[1] - 49;
		else
			col = (int) 9;

		if(board[row][col] > 32){ /* >32 Means that the space is filled by something that we can type*/
			while(board[row][col] > 32){
				printf("Invalid Input, please place your marker on an open slot: ");
				scanf("%s", select);
				printf("Player %c has chosen %s\n", symbol2, select);
				row = (int) boardSize - 1 - (select[0] - 65);
				if(select[2] == 0)
					col = (int) select[1] -49;
				else
					col = (int) 9;

			}
		}

		board[row][col] = symbol2;
		displayBoard_v2(boardSize, board);
		victor = checkBoard(boardSize, board);
		if(victor == symbol1 || victor == symbol2){
			winner = 1;
			printf("Player %c has won!\n", victor);
			break;
		}
		if(victor == 'T'){
			winner = 1;
			printf("It's a tie!");
			break;
		}

	}

}









