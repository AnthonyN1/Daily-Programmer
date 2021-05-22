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

#ifndef _palindromes_h_
#define _palindromes_h_

#include <string>


class Palindromes{
	public:
		static std::string nextPalindrome(const std::string &str);
	private:
		static bool isNineNumber(const std::string &str);
		static std::string largestPal(const std::string &str, unsigned int len);
};


#endif
