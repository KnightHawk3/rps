#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int roll();
void play(int choice);

int main (int argc, char** argv) {
    int index;
	int c;
	srand(time(0));

	while ((c = getopt (argc, argv, "h::")) != -1) {
		switch (c) {
			case 'h':
				std::cout << "Rock, Paper, Sissors (RPS)\n";
				std::cout << "Usage: rps [-h] <choice>\n";
				std::cout << "Choices:\n";
				std::cout << "\tRock\tBeats sissors, but loses to paper.\n";
				std::cout << "\tPaper\tBeats rock, but loses to sissors.\n";
				std::cout << "\tSissors\tBeats paper, but loses to rock.\n";
				break;
			case '?':
				if (isprint (optopt)) {
					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				} else {
					fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
					return 1;
				}
			default:
				std::cout << "Usage: rps [-h] <choice>\n";
				return 1;
		}
	}
	
	for (index = optind; index < argc; index++) {
		if (std::string(argv[index]) == "rock" || std::string(argv[index]) == "Rock") {
			play(1);
		} else if (std::string(argv[index]) == "paper" || std::string(argv[index]) == "Paper") {
			play(2);
		} else if (std::string(argv[index]) == "sissors" || std::string(argv[index]) == "Sissors") {
			play(3);
		}
	}

	return 0;
}

int roll() {
	int randNum = (rand() % 3) + 1;
	return randNum;
}

void play(int choice) {
	int aiChoice = roll();
	//Fabulous logic. Anyone know a better way?
	if (aiChoice == 1) {
		std::cout << "The opponent chooses rock!\nIts a ";
		if (choice == 1) {
			std::cout << "draw!";
		} else if (choice == 3) {
			std::cout << "win!";
		} else if (choice == 2) {
			std::cout << "loss!";
		}
	} else if (aiChoice == 2) {
		std::cout << "The opponent chooses paper!\nIts a ";
		if (choice == 2) {
			std::cout << "draw!";
		} else if (choice == 1) {
			std::cout << "win!";
		} else if (choice == 3) {
			std::cout << "loss!";
		}
	} else if (aiChoice == 3) {
		std::cout << "The opponent chooses sissors!\nIts a ";
		if (choice == 3) {
			std::cout << "draw!";
		} else if (choice == 2) {
			std::cout << "win!";
		} else if (choice == 1) {
			std::cout << "loss!";
		}
	}

}

