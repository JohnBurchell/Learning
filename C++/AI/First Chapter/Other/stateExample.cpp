#include <iostream>
#include "state.h"
#include "troll.h"

class State_Sleep;
class State_RunAway;

class State_RunAway : public State
{
public:
	State_RunAway();
	void execute(Troll* troll)
	{
		if(troll->isSafe())
		{
			troll->changeState(new State_Sleep());
		}
		else
		{
			troll->moveAwayFromEnemy();
		}
	}
};

class State_Sleep : public State
{
public:
	State_Sleep();
	void execute(Troll* troll)
	{
		if(troll->isThreatened())
		{
			troll->changeState(new State_RunAway());
		}
		else
		{
			troll->snore();
		}
	}

};

int main()
{
	std::cout << "Hello states!" << std::endl;	
}