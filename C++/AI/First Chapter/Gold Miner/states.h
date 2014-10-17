#ifndef STATES_H_
#define STATES_H_

#include "state.h"

class EnterMineAndDigForGold : public State
{
	EnterMineAndDigForGold() {};

	//Add copy and assignment ctor, maybe even add move?!

	public:

		//Singleton
		static EnterMineAndDigForGold* instance();

		virtual void enter(Miner*) override;
		virtual void execute(Miner*) override;
		virtual void exit(Miner*) override;
};

#endif //STATES_H_