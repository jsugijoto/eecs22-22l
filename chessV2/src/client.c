/* client.c: Interactive client for chess game, playing vs server host
 * Author: Jonathan Sugijoto, Eesha Jain, Devin Reyes, Jixin Gong
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>

#include "chess.h"

const char *Program	/* program name for descriptive diagnostics */
	= NULL;
int clientplayer;

void FatalError(		/* print error diagnostics and abort */
	const char *ErrorMsg)
{
    fputs(Program, stderr);
    fputs(": ", stderr);
    perror(ErrorMsg);
    fputs(Program, stderr);
    fputs(": Exiting!\n", stderr);
    exit(20);
} /* end of FatalError */

void ClientHH(int Socket)
{
    MVLIST *lst = NewMvList();
	innitBoard();
	getBoard(blackPawns, whitePawns, blackRooks, whiteRooks, blackKnights, whiteKnights, blackBishops, whiteBishops, blackQueen, whiteQueen, blackKing, whiteKing);
    int seq; 
    int player;


	while (checkmate() != 1 || checkmate() != 2 || checkmate() != 3) // This will be a while loop at the end 
	{
		player = 1;
		if(check() == 1){
			while(check() == 1)
			{
				printf("Player %d's King is in check!\n", player);
				if (clientplayer==1)
                	seq = getonline_move(player, lst, Socket);
            	else if (clientplayer==2)
                	seq = getonline_move2(player, lst, Socket);
				if(seq == 0)
					break;
				getBoard(blackPawns, whitePawns, blackRooks, whiteRooks, blackKnights, whiteKnights, blackBishops, whiteBishops, blackQueen, whiteQueen, blackKing, whiteKing);
				if (checkmate() == 1 || checkmate() == 2 || checkmate() == 3)
            		break;
			}
			if(seq == 0)
				break;
		}
		else{
			if (clientplayer==1)
				seq = getonline_move(player, lst, Socket);
			else if (clientplayer==2)
				seq = getonline_move2(player, lst, Socket);
			if(seq == 0)
				break;
			getBoard(blackPawns, whitePawns, blackRooks, whiteRooks, blackKnights, whiteKnights, blackBishops, whiteBishops, blackQueen, whiteQueen, blackKing, whiteKing);
			if (checkmate() == 1 || checkmate() == 2 || checkmate() == 3)
            	break;
		}
		player = 2;
		if(check() == 1){
			while(check() == 1)
			{
				printf("Player %d's King is in check!\n", player);
				if (clientplayer==1)
                    seq = getonline_move(player, lst, Socket);
                else if (clientplayer==2)
                    seq = getonline_move2(player, lst, Socket);
				if(seq == 0)
					break;
				getBoard(blackPawns, whitePawns, blackRooks, whiteRooks, blackKnights, whiteKnights, blackBishops, whiteBishops, blackQueen, whiteQueen, blackKing, whiteKing);
				if (checkmate() == 1 || checkmate() == 2 || checkmate() == 3)
            				break;
			}
			if(seq == 0)
				break;
		}
		else{
			if (clientplayer==1)
				seq = getonline_move(player, lst, Socket);
			else if (clientplayer==2)
				seq = getonline_move2(player, lst, Socket);
			if(seq == 0)
				break;
			getBoard(blackPawns, whitePawns, blackRooks, whiteRooks, blackKnights, whiteKnights, blackBishops, whiteBishops, blackQueen, whiteQueen, blackKing, whiteKing);
			if (checkmate() == 1 || checkmate() == 2 || checkmate() == 3)
         		break;
		}
		if(seq == 0)
			break;
	}
	if (checkmate() == 1)
		printf("PLAYER 1 HAS WON, THANKS FOR PLAYING!\n");
	else if (checkmate() == 2)
		printf("PLAYER 2 HAS WON, THANKS FOR PLAYING!\n");
	else if (checkmate() == 3)
        printf("STALEMENT \n");

}

int print_menu_online()
{
	
	printf("Welcome to Queens Gambit Online");
	printf("\n=================");
	printf("\n    Main Menu    ");
	printf("\n=================");
	int selection = 0;
	printf("\n1. Player vs Host");
	printf("\n2. Exit Game");
	printf("\nChoose option: ");
	scanf("%d", &selection);
	return selection;
}

int start_menu_online(int SocketFD)
{
	MVLIST *lst = NULL;
	lst = NewMvList();
	char p[3];
	int done = 0;
	while(done == 0)
	{
		int option = print_menu_online();
		switch(option)
		{
			case 1: /* Player vs Host */
				printf("Which player do you want to be? \n");
				printf("1. Player1(White) \n");
				printf("2. Player2(Black) \n");
				scanf("%d", &clientplayer);
				if(clientplayer == 1)
					p[0] = '1';
				else if(clientplayer == 2)
					p[0] = '2';
				write(SocketFD, p, 2);
				ClientHH(SocketFD);
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
			case 2: /* Exit */
				done = 1;
				printf("Exiting the game, thanks for playing!");
				break;
			default:
				done = 1;
				printf("Exiting the game, thanks for playing!");
				break;
		}
	}
	return 1;	
}

void createLogin()
{
	FILE *f;
	char username[20];
	char password[20];
	f = fopen("logins.txt", "a");
	printf("Please enter in your desired username: ");
	scanf("%s", username);
	printf("Please enter in your desired password: ");
	scanf("%s", password);
	fprintf(f, "%s\n", username);
	fprintf(f, "%s\n", password);
	fclose(f);

}

int account(int SocketFD)
{
    char username[20];
    char password[20];
    char usernameDB[20];
    char passwordDB[20];
    char line[20];
    int option;
    int login = 0;
    while(login == 0)
    {    
        printf("=============");
        printf("\n    LOGIN    ");
        printf("\n=============");
        
        printf("\n1. Login");
        printf("\n2. Signup");
        printf("\nChoose an option: ");
        scanf("%d", &option);
        if(option == 2)
        {
             createLogin();
        }
        else
        {
            FILE *fptr = fopen("logins.txt", "r");
            printf("\nEnter in your username: ");
            scanf("%s", username);
            printf("Enter in your password: ");
            scanf("%s", password);
            while(fgets(line, sizeof(line), fptr))
            {  
                
                strcpy(usernameDB,line);
                usernameDB[strcspn(usernameDB, "\n")] = 0;

                fgets(line, sizeof(line), fptr);

                strcpy(passwordDB,line);
                passwordDB[strcspn(passwordDB, "\n")] = 0;

                if(strcmp(username, usernameDB) == 0  && strcmp(password, passwordDB) == 0)
                {
                    login = 0;
                    return start_menu_online(SocketFD);
                }
            }
            printf("\nWrong Username/Password!\n");    
            fclose(fptr); 
        }
    }
    return 0;
}



int main(int argc, char *argv[])
{
    int l, n;
    int SocketFD, PortNo;		
    struct sockaddr_in ServerAddress;	
    struct hostent *Server;	/* server host */
    char SendBuf[256];	/* message buffer for sending a message */
    char RecvBuf[256];	/* message buffer for receiving a response */

    Program = argv[0];	/* publish program name (for diagnostics) */
#ifdef DEBUG
    printf("%s: Starting...\n", argv[0]);
#endif
    if (argc < 3)
    {   
		fprintf(stderr, "Usage: %s hostname port\n", Program);
		exit(10);
    }
    Server = gethostbyname(argv[1]);
    if (Server == NULL)
    {   
		fprintf(stderr, "%s: no such host named '%s'\n", Program, argv[1]);
        exit(10);
    }
    PortNo = atoi(argv[2]);
    if (PortNo <= 2000)
    {   
		fprintf(stderr, "%s: invalid port number %d, should be >2000\n",
		Program, PortNo);
        exit(10);
    }
    ServerAddress.sin_family = AF_INET;
    ServerAddress.sin_port = htons(PortNo);
    ServerAddress.sin_addr = *(struct in_addr*)Server->h_addr_list[0];
    do
    {	
		l = strlen(SendBuf);
		if (SendBuf[l-1] == '\n')
			SendBuf[--l] = 0;
		if (l)
		{   
			SocketFD = socket(AF_INET, SOCK_STREAM, 0);
			if (SocketFD < 0)
			{
				FatalError("socket creation failed");
			}
			printf("%s: Connecting to the server at port %d...\n", Program, PortNo);
			if (connect(SocketFD, (struct sockaddr*)&ServerAddress, sizeof(ServerAddress)) < 0)
			{   
				FatalError("connecting to server failed");
			}
			if (n < 0)
			{   
				FatalError("writing to socket failed");
			}
			printf(" SOCKET IS %d \n ", SocketFD);
			if(account(SocketFD) == 1)
				break;
			
#ifdef DEBUG
			printf("%s: Waiting for response...\n", Program);
#endif
			n = read(SocketFD, RecvBuf, sizeof(RecvBuf)-1);
			if (n < 0) 
			{
				FatalError("reading from socket failed");
			}
			RecvBuf[n] = 0;
#ifdef DEBUG
			printf("%s: Closing the connection...\n", Program);
#endif
			close(SocketFD);
		}
	} while(0 != strcmp("SHUTDOWN", SendBuf));

	/* Write back to server that client is gone */
	printf("\n%s: Exiting...\n", Program);
	close(SocketFD);
	return 0;
}

