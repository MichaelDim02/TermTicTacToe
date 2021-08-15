/* This is an admittedly worse version of the C vesion */

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>


char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
char over = false;

void ask_for_names();
void game(std::string player1, std::string player2);
void menu();
void interface(std::string player1, std::string player2);
void check();
void menu() {
	printf("TermTicTacToe for linux!\n");
	printf("TicTacToe for the linux terminal & Unix!\n");
	printf("	1. Start\n");
	printf("	2. Exit\n");
	printf(">> ");
	std::string input;
	std::cin>>input;
	if (input == "1"){
		ask_for_names();
	} else {
		exit(0);
	}
}
void interface(std::string player1, std::string player2) {
        system("clear");
        std::cout << "  " << square[1] <<" | " << square[2] << " | " << square[3] << std::endl;
        std::cout << " ---+---+---" << std::endl;
        std::cout << "  " << square[4] <<" | " << square[5] << " | " << square[6] << std::endl;
        std::cout << " ---+---+---" << std::endl;
        std::cout << "  " << square[7] <<" | " << square[8] << " | " << square[9] <<std::endl << std::endl;
        std::cout << player1 <<" - X" << std::endl << player2 <<" - O" <<std::endl;
}
void game(std::string player1, std::string player2) {
	bool running = true;
	while (running == true) {
		//Player1 turn
		interface(player1, player2);
		std::cout<<std::endl<<player1<<"'s turn"<<std::endl;
		std::cout<<"Choose a number>> ";
		int num1;
		std::cin>>num1;
		square[num1] = 'X';
		check();
		if (over == true) {
			interface(player1, player2);
			std::cout<<player1<<" won!"<<std::endl;
			exit(0);}
		//Player2 turn
		interface(player1, player2);
		std::cout<<std::endl<<player2<<"'s turn"<<std::endl;
		std::cout<<"Choose a number>> ";
		int num2;
		std::cin>>num2;
		square[num2] = 'O';
		check();
		if (over == true) {
			interface(player1, player2);
			std::cout<<player2<<" won!"<<std::endl;
			exit(0);
	}	}
}
void ask_for_names() {
	std::string player1;
	std::string player2;
	printf("Player one, please type a username: ");
	std::cin >> player1;
	printf("Player two, please type a username: ");
	std::cin >> player2;
	std::cout<<std::endl;
	printf("Players:\n");
	std::cout<<player1<<std::endl<<player2<<std::endl;
	system("clear");
	game(player1, player2);
}
int main() {
	menu();
	return 0;
}
void check()
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
		over = true;
	} else if ((s1 == 'O' && s2 == 'O' && s3 == 'O') || (s3 == 'O' && s6 == 'O' && s9 == 'O') || (s1 == 'O' && s4 == 'O' && s7 == 'O') || (s4 == 'O' && s5 == 'O' && s6 == 'O') || (s8 == 'O' && s7 == 'O' && s9 == 'O') || (s1 == 'O' && s5 == 'O' && s9 == 'O') || (s3 == 'O' && s7 == 'O' && s5 == 'O')){
		over = true;
	} else {
		over = false;
	}
}
























