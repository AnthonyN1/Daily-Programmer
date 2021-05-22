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

#include <cstdlib>
#include <string>

#include "montyHall.h"


bool MontyHall::simulate() const {
	// Monty Hall hides the prize behind door #0, #1, or #2 (picked randomly).
	int prizeDoor = rand() % 3;

	// A contestant will have their own strategy for which door to choose.
	int selectedDoor = selectDoor();

	// Monty Hall opens a door.
	// He can choose from the doors that both the contestant hasn't picked and don't have the 
	// prize behind them.
	int openedDoor;

	if(selectedDoor == prizeDoor){
		/*
			prizeDoor	|	openedDoor
			0			|	1 or 2
			1			|	0 or 2
			2			|	0 or 1
		*/
		openedDoor = ((rand() % 2) + selectedDoor + 1) % 3;
	} else{
		/*
			prizeDoor	selectedDoor	|	openedDoor
			0			1				|	2
			0			2				|	1
			1			2				|	0
		*/
		openedDoor = 3 - (prizeDoor + selectedDoor);
	}

	// A contestant can decide to either stay with their originally selected door, or switch to 
	// the last closed door.
	int lastClosedDoor = 3 - (selectedDoor + openedDoor);
	int finalDoor = switchOrStay(selectedDoor, lastClosedDoor);

	// A contestant wins if their final door has the prize behind it.
	return finalDoor == prizeDoor;
}


/*
	Returns which door a given contesant will initially choose.
*/
int MontyHall::selectDoor() const {
	if(name_ == "Alice" || name_ == "Bob" || name_ == "Frank"){
		return 0;
	} else if(name_ == "Carol" || name_ == "Dave" || name_ == "Erin"){
		return (rand() % 3);
	} else{
		return -1;
	}
}

/*
	Returns which door a given contestant finally decides on choosing.
*/
int MontyHall::switchOrStay(int theirDoor, int otherDoor) const {
	if(name_ == "Alice" || name_ == "Dave"){
		return theirDoor;
	} else if(name_ == "Bob" || name_ == "Erin"){
		return otherDoor;
	} else if(name_ == "Carol"){
		return (rand() % 2 == 0) ? theirDoor : otherDoor;
	} else if(name_ == "Frank"){
		return (otherDoor == 1) ? otherDoor : theirDoor;
	} else{
		return -1;
	}
}
