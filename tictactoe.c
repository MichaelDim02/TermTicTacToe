/* TermTicTacToe
 * 
 * This is the (arguably superior
 * C version of the program. It's updated
 * and cleaner.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER 128

char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
char over = 0;

static void ask_for_names();
static void game(char player1[], char player2[]);
static void interface(char player1[], char player2[]);
static void check();

void menu()
{
	printf("TermTicTacToe for linux!\n");
	printf("TicTacToe for the linux terminal & Unix!\n\n");
	ask_for_names();
}

static void
interface(char player1[BUFFER], char player2[BUFFER])
{
        system("clear");
	printf("  %c | %c | %c \n", square[1], square[2], square[3]);
	printf(" ---+---+---\n");
	printf("  %c | %c | %c \n", square[4], square[5], square[6]);
	printf(" ---+---+---\n");
	printf("  %c | %c | %c \n\n", square[7], square[8], square[9]);
	printf("%s - X\n%s -O\n\n", player1, player2);
}

static void
game(char player1[BUFFER], char player2[BUFFER])
{
	int running = 1;
	while (running == 1) {

		/* Player1 turn */
		interface(player1, player2);
		printf("\n%s's turn\nChoost a number> ", player1);
		int n;
		scanf("%d", &n);
		square[n] = 'X';
		check();
		if (over == 1) {
			interface(player1, player2);
			printf("%s won!\n", player1);
			exit(0);}

		/* Player2 turn */
		interface(player1, player2);
		printf("\n%s's turn\nChoost a number> ", player2);
		scanf("%d", &n);
		square[n] = 'O';
		check();
		if (over == 1) {
			interface(player1, player2);
			printf("%s won!\n", player2);
			exit(0);
		}
	}
}

static void
ask_for_names()
{
	char player1[BUFFER];
	char player2[BUFFER];
	printf("Player one, please type a username: ");
	scanf("%s", &player1);
	printf("Player two, please type a username: ");
	scanf("%s", &player2);
	printf("\n\nPlayers:\n");
	/*printf("%s%s", player1, player2);*/
	system("clear");
	game(player1, player2);
}

static void
check()
{
	char s1 = square[1];
	char s2 = square[2];
	char s3 = square[3];
	char s4 = square[4];
	char s5 = square[5];
	char s6 = square[6];
	char s7 = square[7];
	char s8 = square[8];
	char s9 = square[9];
	if((s1 == 'X' && s2 == 'X' && s3 == 'X') || (s3 == 'X' && s6 == 'X' && s9 == 'X') || (s1 == 'X' && s4 == 'X' && s7 == 'X') || (s4 == 'X' && s5 == 'X' && s6 == 'X') || (s8 == 'X' && s7 == 'X' && s9 == 'X') || (s1 == 'X' && s5 == 'X' && s9 == 'X') || (s3 == 'X' && s7 == 'X' && s5 == 'X')){
		over = 1;
	} else if ((s1 == 'O' && s2 == 'O' && s3 == 'O') || (s3 == 'O' && s6 == 'O' && s9 == 'O') || (s1 == 'O' && s4 == 'O' && s7 == 'O') || (s4 == 'O' && s5 == 'O' && s6 == 'O') || (s8 == 'O' && s7 == 'O' && s9 == 'O') || (s1 == 'O' && s5 == 'O' && s9 == 'O') || (s3 == 'O' && s7 == 'O' && s5 == 'O')){
		over = 1;
	} else {
		over = 0;
	}
}

int
main()
{
	menu();
	return 0;
}
