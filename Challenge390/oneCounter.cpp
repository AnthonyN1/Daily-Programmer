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

#include <cmath>

#include "oneCounter.h"


/*
	Given a number 'n', calculates the number of times the digit '1' appears if we look at all the 
	numbers from 0 to 'n', inclusive.
*/
OneCounter::ULL OneCounter::numOnes(ULL n){
	ULL count = 0;

	// Loops through (essentially) every digit in 'n', front-to-back.
	while(n >= 10){
		int firstDigit = getFirstDigit(n);
		int nineNumberSize = log10(n);
		ULL strippedN = power(10, nineNumberSize);
		ULL nextN = n - (firstDigit * strippedN);

		/*
			numOnes(n) for any nineNumber 'n' (a number that's the repetition of the digit '9') is 
			trivial to calculate (a more in-depth explanation is provided at the function comment).

			First, calculates the value of numOnes() for the greatest "nineNumber" that is less 
			than 'n', and multiplies by the first digit of 'n'.

			Ex. if 'n' is 321, we will calculate that numOnes(99) = 20. This covers 1, 10, 11, 
			..., 18, 19, 21, 31, ..., 91. Next, we'll multiply 20 by 3. This accounts for the 
			000s, 100s, and 200s.
		*/
		count += numOnesNineNumber(nineNumberSize) * firstDigit;

		if(firstDigit == 1){
			/*
				If the first digit is a 1, we will only see a fraction of the numbers where the 
				largest digit place is a '1'.

				Ex. if 'n' is 123, we will only see 100 to 123, which excludes 124 to 199.
			*/
			count += nextN + 1;
		} else{
			// Else (the first digit can't be a 0), we will see all of the numbers where the 
			// largest digit place is a '1'.
			count += strippedN;
		}

		// Removes the first digit from 'n', and loops again.
		n = nextN;
	}

	// If the last digit of 'n' isn't a '0', then we will go through one last 1.
	if(n != 0){
		++count;
	}

	return count;
}


/*
	Given a number 'n', returns the first digit.
*/
int OneCounter::getFirstDigit(ULL n){
	while(n >= 10){
		n /= 10;
	}

	return (int)n;
}

/*
	Returns 'a' raised to the power of 'b'.

	Due to floating-point inaccuracies with this C++ implementation of pow(), power() will be used 
	as a substitute.
*/
OneCounter::ULL OneCounter::power(ULL a, ULL b){
	ULL result = 1;
	for(ULL i = 0; i < b; ++i)
		result *= a;

	return result;
}

/*
	Given the size (number of digits) of a nineNumber, calculates the result of numOnes().

	A nineNumber is a number that consists of only the digit '9'.

	Take as an example the nineNumber 99. Obeserve that for numOnes(9), the function counts all 
	the ones that appear from 0 to 9, inclusive. For 99, numOnes(9) can be used 10 times, since 
	going from 0 to 99 would iterate through all the digits in the one's place 10 times.

	Additionally, we would have to account for the ones that would potentially appear in the ten's 
	place. Clearly, there are 10 of these instances. Therefore, numOnes(99) = 20.

	This pattern is easily generalizable. For any nineNumber 'nn' and the number of digits in 'nn' 
	'nnSize', numOnes(nn) is equal to 10 times numOnes(m), where 'm' is the next smallest 
	nineNumber, plus 10^(nnSize - 1).

	Using recursion unrolling (not shown), this recursive algorithm simplies to the expression: 
	(nnSize) * 10^(nnSize - 1).
*/
OneCounter::ULL OneCounter::numOnesNineNumber(ULL nnSize){
	return nnSize * power(10, nnSize - 1);
}
