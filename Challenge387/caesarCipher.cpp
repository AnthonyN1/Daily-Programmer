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

#include <limits>
#include <string>

#include "caesarCipher.h"


/*
	Encodes 'ch' using a Caesar Cipher, shifting by 'shift'.
*/
char CaesarCipher::encodeChar(char ch, int shift){
	// If 'ch' is non-alphabetic, does not encode it.
	if(ch < 65 || (ch > 90 && ch < 97) || ch > 122) return ch;

	// Differentiates between uppercase and lowercase letters.
	char base;
	if(ch >= 65 && ch <= 90)	base = 'A';
	else						base = 'a';

	return ((ch - base + shift) % 26) + base;
}

/*
	Encodes 'str' using a Caesar Cipher, shifting by 'shift'.
*/
std::string CaesarCipher::encodeStr(const std::string &str, int shift){
	char* encodedChars = new char[str.size() + 1];
	encodedChars[str.size()] = '\0';

	// Encodes each character using a Caesar Cipher.
	for(unsigned int i = 0; i < str.size(); ++i)
		encodedChars[i] = encodeChar(str[i], shift);
	
	std::string encodedStr(encodedChars);
	delete[] encodedChars;
	return encodedStr;
}

/*
	Decodes a string of English text 'str' using the letter frequency table 'freqTable'.
*/
std::string CaesarCipher::decode(const std::string &str, const int freqTable[26]){
	std::string maxScoreStr;
	double maxScore = std::numeric_limits<double>::min();

	// Loops through every possible decoding of 'str'.
	for(unsigned int i = 0; i < 26; ++i){
		std::string decodedStr = encodeStr(str, i);
		double currScore = getScore(decodedStr, freqTable);

		if(currScore > maxScore){
			maxScoreStr = decodedStr;
			maxScore = currScore;
		}
	}

	return maxScoreStr;
}


/*
	Returns the score of 'str' using the letter frequency table 'freqTable'.

	The average score of the letters in a string shows how close the string is to normal English. 
	In general, the higher the score, the better.
*/
double CaesarCipher::getScore(const std::string &str, const int freqTable[26]){
	int sum = 0;
	for(unsigned int i = 0; i < str.size(); ++i){
		if(str[i] >= 65 && str[i] <= 90){
			sum += freqTable[str[i] - 'A'];
		} else if(str[i] >= 97 && str[i] <= 122){
			sum += freqTable[str[i] - 'a'];
		}
	}

	return ((double)sum) / str.size();
}
