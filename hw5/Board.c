/* Board.c File
 * Name: Jonathan Sugijoto
 * ID: 58535060
*/

#include "Board.h"
#include "Player.h"

 // Prints the board
void print_fun(int board[3][3], PLAYER *player1, PLAYER *player2){

	/* Initialize the values used for symbols and colors */
	char player1_char = (player1->symbol);
	char player2_char = (player2->symbol);
	char player1_color = (player1->player_color);
	char player2_color = (player2->player_color);

	/* Start with row */
    for(int i=0;i<3;i++)
	{
        /* print out vertical legend */
		if(i==0)
			printf("C ");
		if(i==1)
			printf("B ");
		if(i==2)
			printf("A ");
	
        /* find corresponding column */
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==0) /* empty space */
				printf(" ");
			else if (board[i][j]==1) /* player 1 */
			{
				if (player1_color== 'r')
				{
					printf("\x1b[31m%c\x1b[0m",player1_char); /*Red*/
				}
				else if (player1_color== 'g')
				{
					printf("\x1b[32m%c\x1b[0m",player1_char); /*Green*/
				}
				else if (player1_color== 'y')
				{
					printf("\x1b[33m%c\x1b[0m",player1_char); /* Yellow */
				}
				else if (player1_color== 'b')
				{
					printf("\x1b[34m%c\x1b[0m",player1_char); /* Blue */
				}
				else
				{
					printf("%c\x1b[0m",player1_char); // Default color (theme dependent)
				}
			}
			else if (board[i][j]==2) /* player 2 */
			{
				if (player2_color== 'r')
				{
					printf("\x1b[31m%c\x1b[0m",player2_char); /* Red */
				}
				else if (player2_color== 'g')
				{
					printf("\x1b[32m%c\x1b[0m",player2_char); /* Green */
				}
				else if (player2_color== 'y')
				{
					printf("\x1b[33m%c\x1b[0m",player2_char); /* Yellow */
				}
				else if (player2_color== 'b')
				{
					printf("\x1b[34m%c\x1b[0m",player2_char); /* Blue */
				}
				else
				{
					printf("%c\x1b[0m",player2_char); /* Default color (theme dependent) */
				}
			}
				
			/* print out lines in between columns */ 
            if(j!=2)
				printf("|");
		}
		if(i!=2) /* print out lines between rows */
			printf("\n  -----\n");
		else if(i==2) /* prints out horizontal legend */
			printf("\n  1 2 3\n");
	}

}

// Checks if there is an empty cell for tie condition
int is_there_empty_cell(int board[3][3]){
	int count=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
				if(board[i][j]==0)
					count++;	
		}
	}
	if (count!=0)
		return 1; /* we have empty cell */
	else
		return 0; /* we do not have empty cell */

}

// Checks for a winner
int IsWin(int board[3][3]){
	int win_flag=0;
	if(((board[0][0]==1)&&(board[1][0]==1)&&(board[2][0]==1))||
		((board[0][1]==1)&&(board[1][1]==1)&&(board[2][1]==1))||
		((board[0][2]==1)&&(board[1][2]==1)&&(board[2][2]==1))||
		((board[0][0]==1)&&(board[0][1]==1)&&(board[0][2]==1))||
		((board[1][0]==1)&&(board[1][1]==1)&&(board[1][2]==1))||
		((board[2][0]==1)&&(board[2][1]==1)&&(board[2][2]==1))||
		((board[0][0]==1)&&(board[1][1]==1)&&(board[2][2]==1))||
		((board[0][2]==1)&&(board[1][1]==1)&&(board[2][0]==1)))
		{
			win_flag =1;
		}
	
	else if(((board[0][0]==2)&&(board[1][0]==2)&&(board[2][0]==2))||
				((board[0][1]==2)&&(board[1][1]==2)&&(board[2][1]==2))||
				((board[0][2]==2)&&(board[1][2]==2)&&(board[2][2]==2))||
				((board[0][0]==2)&&(board[0][1]==2)&&(board[0][2]==2))||
				((board[1][0]==2)&&(board[1][1]==2)&&(board[1][2]==2))||
				((board[2][0]==2)&&(board[2][1]==2)&&(board[2][2]==2))||
				((board[0][0]==2)&&(board[1][1]==2)&&(board[2][2]==2))||
				((board[0][2]==2)&&(board[1][1]==2)&&(board[2][0]==2)))
				{
					win_flag =2;
				}

	return win_flag;		

}

char *entered_one_char(int board[3][3], int player_num){
	int valid_entered = 0;
	int c;
	int r;
	char *letters_num;
	letters_num = calloc(4, sizeof(char));
	while(valid_entered == 0){
		c=0;
		r=0;
		scanf("%2s", (letters_num));
		
		if (*letters_num=='A')
		{
			r=2;
		}
		else if(*letters_num=='B')
		{
			r=1;
		}
		else if(*letters_num=='C')
		{
			r=0;
		}
		
		if (*(letters_num+1)=='1')
		{
			c=0;
		}
		else if(*(letters_num+1)=='2')
		{
			c=1;
		}
		else if(*(letters_num+1)=='3')
		{
			c=2;
		}
		else if(*(letters_num)=='Z'){
			return letters_num;
		}

		if (board[r][c] == 0)
		{
			valid_entered = 1;
		}
		else
		{
			printf("The entered position is not available! Please try again...\n");
		}
	}
	board [r][c]=player_num;
	return letters_num;
}

void HumanVsHuman(int board[3][3], PLAYER *player1, PLAYER *player2){
	MOVE_LIST *recorded_moves;
	recorded_moves = calloc(11, sizeof(MOVE_LIST));
	/* Start with empty board */
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			recorded_moves->board[x][y] = 0;
		}
	}
	printf("Human v. Human game started\n");
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
		if(*(player_move) == 'Z'){
			struct MOVE_LIST *temp;
			temp = recorded_moves;
			reset = takeBack(recorded_moves);
			if(reset == 1){
				recorded_moves = NULL;
			}
			reprint = 1;
			if(reset != 1){
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
				for(int x = 0; x < 3; x++){
					for(int y = 0; y < 3; y++){
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
				printf("Player 2 wins! Game Over!\n\n");
			}
			tie=0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;
		printf("Player 2, please choose your move:");
		player_move = entered_one_char(board,2);
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
				printf("Player 2 wins! Game Over!\n\n");
			}
			tie=0;
			break;
		}

	}
	if (tie==1)
		printf("The game is a tie!\n");
	freeList(recorded_moves);
}

void printMoveList(MOVE_LIST *moves){
	struct MOVE_LIST *last;
	while (moves != NULL){
		printf(" %c%c", moves->move[0], moves->move[1]);
		last = moves;
		moves = moves->next;
	}
}

int takeBack(MOVE_LIST *moves){
	printf("Player has taken their move back!\n");
	int reset = 0;
	struct MOVE_LIST *last = moves;
	while (last->next != NULL){
		last = last->next;
	}
	if(last->prev == NULL){
		for(int x=0; x<3; x++){
				for(int y=0; y<3; y++){
					last->board[x][y] = 0;	
				}
		}
		printf("Can't take back any more moves!\n");
		reset = 1;
		return reset;
	}

	if(moves != NULL){
		last = last->prev;
		last->next = NULL;
		last = last->prev;
		last->next = NULL;
	}
	else{	
		for(int x=0; x<3; x++){
			for(int y=0; y<3; y++){
					last->board[x][y] = 0;	
					reset = 1;
			}
		}
	}
	return reset;
}	

void append(MOVE_LIST **head_ref, int track_board[3][3], char *record_move){
	struct MOVE_LIST *new_node = calloc(11, sizeof(struct MOVE_LIST));
	struct MOVE_LIST *last;
	last = *head_ref;
	/* Insert Board and Player Move here */
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			new_node->board[x][y] = track_board[x][y];
		}
	}
	new_node->move[0] = *(record_move);
	new_node->move[1] = *(record_move+1);

	if(*head_ref == NULL){
		new_node->prev = NULL;
		*head_ref = new_node;	
	}
	else{
		while(last->next != NULL){
			last = last->next;
		}
		last->next = new_node;
		new_node->prev = last;
	}
}

void freeList(MOVE_LIST *head){
	struct MOVE_LIST *current = head;
	struct MOVE_LIST *next;
	while(current!= NULL){
		next = current->next;
		free(current);
		current = next;
	}
	head = NULL;
}

void replay(MOVE_LIST *recorded_moves, PLAYER *player1, PLAYER *player2){
	FILE *fp = NULL;
	time_t t;
	time(&t);
	fp = fopen("replay.txt", "w");
	fprintf(fp, "#TicTacWowWeeWow\n");
	fprintf(fp, "Version: v1\n");
	fprintf(fp, "Date: %s\n", ctime(&t));
	fprintf(fp, "#Settings\n");
	char color1[8];
	char color2[8];
	if(player2->player_color == 'd'){
		strcpy(color2, "default");
	}
	else if(player2->player_color == 'r'){
		strcpy(color2, "red");
	}
	else if(player2->player_color == 'y'){
		strcpy(color2, "yellow");
	}
	else if(player2->player_color == 'g'){
		strcpy(color2, "green");
	}
	else if(player2->player_color == 'b'){
		strcpy(color2, "blue");
	}
	if(player1->player_color == 'd'){
		strcpy(color1, "default");
	}
	else if(player1->player_color == 'r'){
		strcpy(color1, "red");
	}
	else if(player1->player_color == 'y'){
		strcpy(color1, "yellow");
	}
	else if(player1->player_color == 'g'){
		strcpy(color1, "green");
	}
	else if(player1->player_color == 'b'){
		strcpy(color1, "blue");
	}
	fprintf(fp, "Player 1 (Human): '%c', '%s'\n", player1->symbol, color1);
	fprintf(fp, "Player 2 (AI): '%c', '%s'\n", player2->symbol, color2);
	fprintf(fp, "\n#Winner\n");

	/* Determine the winner */
	struct MOVE_LIST *temp;
	temp = recorded_moves;
	temp->next = recorded_moves->next;
	while(temp->next != NULL){
		temp = temp->next;
	}
	int board[3][3];
	for(int x=0; x<3; x++){
		for(int y=0; y<3; y++){
			board[x][y] = temp->board[x][y];
		}
	}
	int winFlag = 0;
	winFlag = IsWin(board);
	
	if(winFlag == 1)
		fprintf(fp, "Player1\n");
	else if(winFlag == 2)
		fprintf(fp, "Player2\n");	
	else
		fprintf(fp, "Tie Game\n");

	fprintf(fp, "\n#Replay\n");
	temp = recorded_moves;
	temp->next = recorded_moves->next;
	int p1 = 1;
	while(temp->next != NULL){
		temp = temp->next;
		if(p1 == 1){
			fprintf(fp, "Player 1: %s\n", temp->move);
			p1 = 2;
		}
		else{
			fprintf(fp, "Player 2: %s\n", temp->move);
			p1 = 1;
		}
	}
	
	fprintf(fp, "\n#MovesList\n");
	p1 = 1;
	int firstprint = 1;
	temp = recorded_moves;
	while(temp != NULL){
		for(int x = 0; x < 3; x++){
			for(int y = 0; y < 3; y++){
				board[x][y] = temp->board[x][y];
			}
		}
		char player1_char = (player1->symbol);
		char player2_char = (player2->symbol);
		char player1_color = (player1->player_color);
		char player2_color = (player2->player_color);
		if(p1 == 1 && firstprint != 1){
			fprintf(fp, "Player 1 chooses %s\n", temp->move);
			p1 = 2;
		}
		else if(p1 == 2 && firstprint != 1){
			fprintf(fp, "Player 2 chooses %s\n", temp->move);
			p1 = 1;
		}
		/* Start with row */
   		for(int i=0;i<3;i++)
		{
        /* print out vertical legend */
			if(i==0)
				fprintf(fp, "C ");
			if(i==1)
				fprintf(fp, "B ");
			if(i==2)
				fprintf(fp, "A ");
	
        /* find corresponding column */
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==0) /* empty space */
				fprintf(fp, " ");
			else if (board[i][j]==1) /* player 1 */
			{
				if (player1_color== 'r')
				{
					fprintf(fp, "%c",player1_char); /*Red*/
				}
				else if (player1_color== 'g')
				{
					fprintf(fp, "%c",player1_char); /*Green*/
				}
				else if (player1_color== 'y')
				{
					fprintf(fp, "%c",player1_char); /* Yellow */
				}
				else if (player1_color== 'b')
				{
					fprintf(fp, "%c",player1_char); /* Blue */
				}
				else
				{
					fprintf(fp, "%c",player1_char); // Default color (theme dependent)
				}
			}
			else if (board[i][j]==2) /* player 2 */
			{
				if (player2_color== 'r')
				{
					fprintf(fp, "%c",player2_char); /* Red */
				}
				else if (player2_color== 'g')
				{
					fprintf(fp, "%c",player2_char); /* Green */
				}
				else if (player2_color== 'y')
				{
					fprintf(fp, "%c",player2_char); /* Yellow */
				}
				else if (player2_color== 'b')
				{
					fprintf(fp, "%c",player2_char); /* Blue */
				}
				else
				{
					fprintf(fp, "%c",player2_char); /* Default color (theme dependent) */
				}
			}
				
			/* print out lines in between columns */ 
            if(j!=2)
				fprintf(fp, "|");
		}
		if(i!=2) /* print out lines between rows */
			fprintf(fp, "\n  -----\n");
		else if(i==2) /* prints out horizontal legend */
			fprintf(fp, "\n  1 2 3\n\n");
	}
		firstprint = 0;
		temp = temp->next;
	}
	free(temp);
	winFlag = 0;
	winFlag = IsWin(board);
	
	if(winFlag == 1)
		fprintf(fp, "Player 1 Wins!\n");
	else if(winFlag == 2)
		fprintf(fp, "Player 2 Wins!\n");	
	else
		fprintf(fp, "Tie Game!\n");
	
	fprintf(fp, "\n#EOF");
 
	fclose(fp);
	printf("\nReplay Saved to 'replay.txt'");
}
