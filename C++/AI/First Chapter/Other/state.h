#ifndef STATE_H_
#define STATE_H_

#include "troll.h"

class Troll;

class State 
{
	public:
		virtual void execute(Troll* troll) = 0;
};


#endif //STATE_H_