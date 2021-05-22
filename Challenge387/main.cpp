/*
	Anthony Nool
	
	Start date: 5/22/2021
	End date: 5/22/2021
	Total hours: 3
	
	Challenge #387: Caesar Cipher
	Difficulty: Easy
	www.reddit.com/r/dailyprogrammer/comments/myx3wn/20210426_challenge_387_easy_caesar_cipher/
	
	Notes:
	- Duplicate of Challenge #47
*/

#include <iostream>
#include <string>

#include "caesarCipher.h"

const unsigned int NUM_TEST_CASES_CHAR = 7;
const char TEST_CASES_CHAR_ARG1[NUM_TEST_CASES_CHAR] = {'a', 'a', 'a', 'a', 'd', 'z', 'q'};
const int TEST_CASES_CHAR_ARG2[NUM_TEST_CASES_CHAR] = {0, 1, 5, 26, 15, 1, 22};
const char TC_CHAR_ANSWERS[NUM_TEST_CASES_CHAR] = {'a', 'b', 'f', 'a', 's', 'a', 'm'};

const unsigned int NUM_TEST_CASES_STR = 6;
const std::string TEST_CASES_STR_ARG1[NUM_TEST_CASES_STR] = {"a", "abcz", "irk", "fusion", "dailyprogrammer", "jgorevxumxgsskx"};
const int TEST_CASES_STR_ARG2[NUM_TEST_CASES_STR] = {1, 1, 13, 6, 6, 20};
const std::string TC_STR_ANSWERS[NUM_TEST_CASES_STR] = {"b", "bcda", "vex", "layout", "jgorevxumxgsskx", "dailyprogrammer"};

const unsigned int NUM_TEST_CASES_SPECIAL = 1;
const std::string TEST_CASES_SPECIAL_ARG1[NUM_TEST_CASES_SPECIAL] = {"Daily Programmer!"};
const int TEST_CASES_SPECIAL_ARG2[NUM_TEST_CASES_SPECIAL] = {6};
const std::string TC_SPECIAL_ANSWERS[NUM_TEST_CASES_SPECIAL] = {"Jgore Vxumxgsskx!"};

const unsigned int NUM_TEST_CASES_DECODE = 3;
const std::string TEST_CASES_DECODE[NUM_TEST_CASES_DECODE] = {
	"Zol abyulk tl puav h ulda.", 
	"Tfdv ef wlikyvi, wfi uvrky rnrzkj pfl rcc nzky erjkp, szx, gfzekp kvvky.", 
	"Qv wzlmz bw uiqvbiqv iqz-axmml dmtwkqbg, i aeittwe vmmla bw jmib qba eqvoa nwzbg-bpzmm bquma mdmzg amkwvl, zqopb?"
};
const int TEST_CASES_DECODE_LETTER_FREQ[26] = {3, -1, 1, 1, 4, 0, 0, 2, 2, -5, -2, 1, 0, 2, 3, 0, -6, 2, 2, 3, 1, -1, 0, -5, 0, -7};


int main(){
	// Runs test cases for a single character.
	for(unsigned int i = 0; i < NUM_TEST_CASES_CHAR; ++i){
		char result = CaesarCipher::encodeChar(TEST_CASES_CHAR_ARG1[i], TEST_CASES_CHAR_ARG2[i]);
		if(result != TC_CHAR_ANSWERS[i]){
			std::cout << "ERROR: encodeChar('" << TEST_CASES_CHAR_ARG1[i] << "', " << TEST_CASES_CHAR_ARG2[i] << ")\n";
			std::cout << "       Expected '" << TC_CHAR_ANSWERS[i] << "', but received '" << result << "'\n";
			return 1;
		}
	}

	// Runs test cases for a string.
	for(unsigned int i = 0; i < NUM_TEST_CASES_STR; ++i){
		std::string result = CaesarCipher::encodeStr(TEST_CASES_STR_ARG1[i], TEST_CASES_STR_ARG2[i]);
		if(result != TC_STR_ANSWERS[i]){
			std::cout << "ERROR: encodeStr(\"" << TEST_CASES_STR_ARG1[i] << "\", " << TEST_CASES_STR_ARG2[i] << ")\n";
			std::cout << "       Expected \"" << TC_STR_ANSWERS[i] << "\", but received \"" << result << "\"\n";
			return 1;
		}
	}

	// Runs special test cases. (account for non-alphabetic characters and capital letters)
	for(unsigned int i = 0; i < NUM_TEST_CASES_SPECIAL; ++i){
		std::string result = CaesarCipher::encodeStr(TEST_CASES_SPECIAL_ARG1[i], TEST_CASES_SPECIAL_ARG2[i]);
		if(result != TC_SPECIAL_ANSWERS[i]){
			std::cout << "ERROR: encodeStr(\"" << TEST_CASES_SPECIAL_ARG1[i] << "\", " << TEST_CASES_SPECIAL_ARG2[i] << ")\n";
			std::cout << "       Expected \"" << TC_SPECIAL_ANSWERS[i] << "\", but received \"" << result << "\"\n";
			return 1;
		}
	}

	// Runs test cases to decode a cipher.
	for(unsigned int i = 0; i < NUM_TEST_CASES_DECODE; ++i){
		std::string result = CaesarCipher::decode(TEST_CASES_DECODE[i], TEST_CASES_DECODE_LETTER_FREQ);

		std::cout << "decode(\"" << TEST_CASES_DECODE[i] << "\")\n\"" << result << "\"\n\n";
	}


	return 0;
}
