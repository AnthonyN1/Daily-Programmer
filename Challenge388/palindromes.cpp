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

#include <algorithm>
#include <string>

#include "palindromes.h"


/*
	Returns the smallest palindrome that's greater than the given positive whole number (represented as a string).
*/
std::string Palindromes::nextPalindrome(const std::string &str){
	// Edge case: all numbers less than 10 are palindromes.
	if(str.size() < 2) return str;

	// Edge case: nineNumber
	// The next palindrome of all nineNumbers follows the pattern: 100...001.
	if(isNineNumber(str)) return "1" + std::string(str.size() - 1, '0') + "1";

	// In general, the next palindrome will have the same number of digits as 'str'.
	char* nextPal = new char[str.size() + 1];
	nextPal[str.size()] = '\0';

	// Loops through the first half of 'str'.
	for(unsigned int i = 0; i < str.size() / 2; ++i){
		// Finds the largest palindrome based on the first (i + 1) characters of 'str'.
		std::string largestPalindrome = largestPal(str, i + 1);

		if(str < largestPalindrome){
			// The next palindrome uses those first digits.
			nextPal[i] = str[i];
			nextPal[str.size() - 1 - i] = str[i];
		} else{
			/*
				If 'str' is not less than 'largestPal', the current digit neds to be incremented, 
				and the middle digits need to be filled in as '0'.
				
				It is never the case that 'str' is greater than or equal to 'largestPal', while 
				the current digit is a '9'.
			*/
			nextPal[i] = str[i] + 1;
			nextPal[str.size() - 1 - i] = str[i] + 1;

			for(unsigned int j = i + 1; j < str.size() - 1 - i; ++j)
				nextPal[j] = '0';
			
			std::string result(nextPal);
			delete[] nextPal;
			return result;
		}
	}

	// If 'str' has odd length, the middle digit needs to be incremented.
	// At this point, it is never the case that the middle digit is a '9'.
	if(str.size() % 2 == 1){
		unsigned int middle = str.size() / 2;
		nextPal[middle] = str[middle] + 1;
	}

	std::string result(nextPal);
	delete[] nextPal;
	return result;
}


/*
	Returns true is 'str' is a nineNumber.

	A nineNumber is a number that's the repitition of the digit '9'.
*/
bool Palindromes::isNineNumber(const std::string &str){
	for(unsigned int i = 0; i < str.size(); ++i)
		if(str[i] != '9')
			return false;
	
	return true;
}

/*
	Returns the largest palindrome, based on the first 'len' characters of 'str'.

	Ex. if 'str' is "123456" and 'len' is 2, largestPal() returns the largest palindrome that 
	begins with "12" and is the same length as 'str'. This is 129921.
*/
std::string Palindromes::largestPal(const std::string &str, unsigned int len){
	std::string keptNums(str, 0, len);

	std::string keptNumsRev(keptNums);
	std::reverse(keptNumsRev.begin(), keptNumsRev.end());

	return keptNums + std::string(str.size() - (2 * len), '9') + keptNumsRev;
}
