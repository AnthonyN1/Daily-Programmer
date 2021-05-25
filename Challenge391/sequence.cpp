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

#include <string>

#include "sequence.h"


/*
	Generates the 'iter'th iteration of the sequence.
*/
std::string Sequence::genSequence(int iter){
	if(iter == 1) return "a";

	char nextChar = 'a' + iter - 1;
	std::string prevSequence = genSequence(iter - 1);

	// The first part of the sequence is the previous iteration of the sequence.
	std::string sequence(prevSequence);

	// Next, the new character is appended.
	sequence += nextChar;

	// Lastly, the previous iteration is appended again.
	sequence += prevSequence;

	return sequence;
}
