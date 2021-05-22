/*
	Anthony Nool
	
	Start date: 5/21/2021
	End date: 5/22/2021
	Total hours: 6

	Challenge #388: Next Palindrome
	Difficulty: Intermediate
	www.reddit.com/r/dailyprogrammer/comments/n3var6/20210503_challenge_388_intermediate_next/

	Notes:
	- Duplicate of Challenge #58
*/

#include <iostream>
#include <string>

#include "palindromes.h"

const unsigned int NUM_TEST_CASES = 3;
const std::string TEST_CASES[NUM_TEST_CASES] = {"808", "999", "2133"};
const std::string TC_ANSWERS[NUM_TEST_CASES] = {"818", "1001", "2222"};

const unsigned int NUM_HIDDEN_TC = 2;
const std::string HIDDEN_TC[NUM_HIDDEN_TC] = {"4052555153018976267", "3234476509624757991344647769100216810857203198904625400933895331391691459636928060001"};


int main(){
	// Runs provided test cases.
	for(unsigned int i = 0; i < NUM_TEST_CASES; ++i){
		std::string result = Palindromes::nextPalindrome(TEST_CASES[i]);
		if(result != TC_ANSWERS[i]){
			std::cout << "ERROR: nextPalindrome(\"" << TEST_CASES[i] << "\")\n";
			std::cout << "       Expected \"" << TC_ANSWERS[i] << "\", but received \"" << result << "\"\n";
			return 1;
		}
	}

	// Runs "hidden" test cases.
	for(unsigned int i = 0; i < NUM_HIDDEN_TC; ++i){
		std::string result = Palindromes::nextPalindrome(HIDDEN_TC[i]);

		std::cout << "nextPalindrome(\"" << HIDDEN_TC[i] << "\")\n\"" << result << "\"\n\n";
	}


	return 0;
}
