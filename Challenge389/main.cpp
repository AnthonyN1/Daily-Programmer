/*
	Anthony Nool
	
	Start date: 5/21/2021
	End date: 5/21/2021
	Total hours: 4
	
	Challenge #389: The Monty Hall Problem
	Difficulty: Easy
	www.reddit.com/r/dailyprogrammer/comments/n94io8/20210510_challenge_389_easy_the_monty_hall_problem/

	Notes:
	- Duplicate of Challenge #49
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>

#include "montyHall.h"

const int SIMULATION_RUNS = 1000;
const unsigned int NUM_SIMULATIONS = 6;
const std::string TEST_CASES[NUM_SIMULATIONS] = {"Alice", "Bob", "Carol", "Dave", "Erin", "Frank"};


int main(){
	srand(time(NULL));

	printf("+---------------------------+\n");
	printf("| Name       | Success Rate |\n");
	printf("|------------|--------------|\n");

	for(unsigned int i = 0; i < NUM_SIMULATIONS; ++i){
		// Creates a MontyHall for each test case.
		MontyHall mh(TEST_CASES[i]);

		// Calculates the test case's success rate.
		int numSuccesses = 0;
		for(int j = 0; j < SIMULATION_RUNS; ++j)
			if(mh.simulate())
				++numSuccesses;
		
		double percent = ((double)numSuccesses) / SIMULATION_RUNS * 100;

		// Outputs the test case's results.
		printf("| %-10s | %-11.1f%% |\n", TEST_CASES[i].c_str(), percent);
	}

	printf("+---------------------------+\n");


	return 0;
}
