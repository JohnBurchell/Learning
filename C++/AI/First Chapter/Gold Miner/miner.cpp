#include "miner.h"
#include "state.h"
#include <cassert>

Miner::Miner(int id) :
	location_{LocationType::shack},
	goldCarried_{0},
	moneyInBank_{0},
	thirst_{0},
	fatigue_{0},
	BaseGameEntity(id)
	{
		//Setup statemachine
		stateMachine = new StateMachine<Miner>(this);

		//stateMachine->setCurrentState(GoHomeAndSleepTilRested::instane());
		//stateMachine->setGlobalState(MinerGlobalState::instance());
	};

Miner::~Miner()
{
	delete stateMachine;
}

void Miner::update()
{
	++thirst_;
	stateMachine->update();
}
