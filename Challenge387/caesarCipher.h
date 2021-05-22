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

#ifndef _caesarCipher_h_
#define _caesarCipher_h_

#include <string>


class CaesarCipher{
	public:
		static char encodeChar(char ch, int shift);
		static std::string encodeStr(const std::string &str, int shift);
		static std::string decode(const std::string &str, const int freqTable[26]);
	private:
		static double getScore(const std::string &str, const int freqTable[26]);
};


#endif
