#ifndef TROLL_H_
#define TROLL_H_

#include "state.h"

class Troll
{
	State* currentState;

public:
	void update()
	{
		currentState->execute(this);
	}	

	void changeState(const State* pNewState)
	{
		delete currentState;
		currentState = pNewState;
	}

	bool isSafe();
	bool isThreatened();
	void moveAwayFromEnemy();
	void snore();
};

#endif //TROLL_H_