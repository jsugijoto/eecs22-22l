/* Player.c File
 * Name: Jonathan Sugijoto
 * ID: 58535060
*/

#include "Player.h"

PLAYER *createPlayer(char sym, int num){
	PLAYER *player;
	player = malloc(sizeof(PLAYER));
	player->symbol = sym;
	player->player_num = num;
	player->player_color = 'd'; /* Default color of 'd' which is white */
	
	return player;
}

void deletePlayer(PLAYER *player){
	assert(player);
	free(player);
	player = NULL;
}

// Players can choose their characters
void choose_char(PLAYER *player1, PLAYER *player2){
	char player1_char, player2_char;
	printf("Player 1, choose your char between A to Z: ");
	scanf(" %c", &player1_char);
	printf("Player 2, choose your char between A to Z: ");
	scanf(" %c", &player2_char);

	(player1->symbol) = player1_char;
	(player2->symbol) = player2_char;
}	

// Players can choose their color
void choose_color(PLAYER *player1, PLAYER *player2){
	int valid_entered = 0;
	printf("Player 1, choose from the following list for your color please...\n");
	printf("'r' for red, 'g' for green, 'y' for yellow, 'b' for blue, 'd' for default: ");
	while(valid_entered == 0){
		char col;
		scanf(" %c", &col);
		if(col == 'r' || col == 'g' || col == 'y' || col == 'b' || col == 'd'){
			valid_entered = 1;
			player1->player_color = col;
		}
		else{
			printf("\nInvalid input, please try again: ");
		}
	}
	valid_entered = 0;
	printf("Player 2, choose from the following list for your color please...\n");
	printf("'r' for red, 'g' for green, 'y' for yellow, 'b' for blue, 'd' for default: ");
	while(valid_entered == 0){
		char col;
		scanf(" %c", &col);
		if(col == 'r' || col == 'g' || col == 'y' || col == 'b' || col == 'd'){
			valid_entered = 1;
			player2->player_color = col;
		}
		else{
			printf("\nInvalid input, please try again: ");
		}
	}
}

void settings(PLAYER *player1, PLAYER *player2){
	int valid_entered = 0;
	while(valid_entered == 0){
		int select = 0;
		printf("Entering Settings...\n");
		printf("1. Changing the players' character\n");
		printf("2. Changing the players' character color\n");
		printf("3. Exiting settings\n");
		printf("Please make a selection: "); 
		scanf("%d", &select);

		if(select == 1){
			choose_char(player1, player2);
		}
		else if(select == 2){
			choose_color(player1, player2);
		}
		else if(select == 3){
			printf("Exiting settings...");
			break;
		}
	}
}

