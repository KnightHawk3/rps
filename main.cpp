#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

int main (int argc, char** argv) {
	int c;

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
		}
	}

	return 0;
}
