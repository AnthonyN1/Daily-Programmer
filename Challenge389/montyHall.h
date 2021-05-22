/*
	Anthony Nool
	
	Start date: 5/21/2021
	End date: 5/21/2021
	Total hours: 4
	
	Challenge #389: The Monty Hall Problem
	Difficulty: Easy
	www.reddit.com/r/dailyprogrammer/comments/n94io8/20210510_challenge_389_easy_the_monty_hall_problem/

	Notes:
	- Duplicate of Challenge #49
*/

#ifndef _montyHall_h_
#define _montyHall_h_

#include <string>


class MontyHall{
	public:
		MontyHall(const std::string &name): name_(name) {}

		bool simulate() const;
	private:
		int selectDoor() const;
		int switchOrStay(int theirDoor, int otherDoor) const;

		std::string name_;
};


#endif
