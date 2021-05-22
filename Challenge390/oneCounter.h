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

#ifndef _oneCounter_h_
#define _oneCounter_h_


class OneCounter{
	public:
		typedef unsigned long long ULL;

		static ULL numOnes(ULL n);
	private:
		static int getFirstDigit(ULL n);
		static ULL power(ULL a, ULL b);
		static ULL numOnesNineNumber(ULL nnSize);
};


#endif
