/*
	Anthony Nool
	
	Start date: 5/24/2021
	End date: 5/24/2021
	Total hours: 1

	Challenge #391: The ABACABA Sequence
	Difficulty: Easy
	www.reddit.com/r/dailyprogrammer/comments/njxq95/20210524_challenge_391_easy_the_abacaba_sequence/

	Notes:
	- Duplicate of Challenge #56
*/

#include <iostream>
#include <string>

#include "sequence.h"

const unsigned int NUM_TEST_CASES = 5;
const int TEST_CASES[NUM_TEST_CASES] = {1, 2, 3, 4, 5};
const std::string TC_ANSWERS[NUM_TEST_CASES] = {"a", "aba", "abacaba", "abacabadabacaba", "abacabadabacabaeabacabadabacaba"};

const int HIDDEN_TC = 26;
const unsigned int HTC_SIZE = 67108863;


int main(){
	// Runs provided test cases.
	for(unsigned int i = 0; i < NUM_TEST_CASES; ++i){
		std::string result = Sequence::genSequence(TEST_CASES[i]);
		if(result != TC_ANSWERS[i]){
			std::cout << "ERROR: genSequence(\"" << TEST_CASES[i] << "\")\n";
			std::cout << "       Expected \"" << TC_ANSWERS[i] << "\", but received \"" << result << "\"\n";
			return 1;
		}
	}

	// Runs "hidden" test case.
	std::string result = Sequence::genSequence(HIDDEN_TC);

	if(result.size() != HTC_SIZE){
		std::cout << "ERROR: genSequence(\"" << HIDDEN_TC << "\")\n";
		std::cout << "       Expected answer to be " << HTC_SIZE << " characters long, but received " << result.size() << ".\n";
		return 1;
	}

	std::cout << result << "\n";


	return 0;
}
