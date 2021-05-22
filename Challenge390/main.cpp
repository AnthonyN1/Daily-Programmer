/*
	Anthony Nool
	
	Start date: 5/20/2021
	End date: 5/21/2021
	Total hours: 7

	Challenge #390: Number of 1's
	Difficulty: Difficult
	www.reddit.com/r/dailyprogrammer/comments/neg49j/20210517_challenge_390_difficult_number_of_1s/

	Notes:
	- Duplicate of Challenge #45
*/

#include <cstdio>
#include <string>

#include "oneCounter.h"

const unsigned int NUM_TEST_CASES = 9;
const OneCounter::ULL TEST_CASES[NUM_TEST_CASES] = {1, 5, 10, 20, 1234, 5123, 70000, 123321, 50031545098999707};
const OneCounter::ULL TC_ANSWERS[NUM_TEST_CASES] = {1, 1, 2, 12, 689, 2557, 38000, 93395, 90051450678399649};

const OneCounter::ULL HIDDEN_TC = 95367431640625;
const unsigned int HTC_SIZE = 15;
const int HTC_DIGIT_SUM = 74;


int main(){
	// Runs provided test cases.
	for(unsigned int i = 0; i < NUM_TEST_CASES; ++i){
		OneCounter::ULL result = OneCounter::numOnes(TEST_CASES[i]);
		if(result != TC_ANSWERS[i]){
			printf("ERROR: numOnes(%llu)\n", TEST_CASES[i]);
			printf("       Expected %llu, but received %llu.\n", TC_ANSWERS[i], result);
			return 1;
		}
	}

	// Runs "hidden" test case.
	OneCounter::ULL result = OneCounter::numOnes(HIDDEN_TC);
	std::string resStr = std::to_string(result);

	if(resStr.size() != HTC_SIZE){
		printf("ERROR: numOnes(%llu)\n", HIDDEN_TC);
		printf("       Expected answer to be %du digits long, but received %lu.\n", HTC_SIZE, resStr.size());
		return 1;
	}

	int digitSum = 0;
	for(unsigned int i = 0; i < resStr.size(); ++i)
		digitSum += resStr[i] - '0';

	if(digitSum != HTC_DIGIT_SUM){
		printf("ERROR: numOnes(%llu)\n", HIDDEN_TC);
		printf("       Expected the sum of the answer's digits to be %d, but received %d.\n", HTC_DIGIT_SUM, digitSum);
		return 1;
	}


	return 0;
}
