#ifndef STATE_H_
#define STATE_H_

#include "miner.h"

class Miner;

template <class entity_type>
class State
{

	public:

		virtual ~State() {}

		//Enter action
		virtual void enter(entity_type*) = 0;

		//Update function called by miner.
		virtual void execute(entity_type*) = 0;

		//Exit action
		virtual void exit(entity_type*) = 0;

};

#endif //STATE_H_