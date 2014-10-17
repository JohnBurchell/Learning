#include "states.h"

/* Dig for gold */
void EnterMineAndDigForGold::enter(Miner* miner)
{

	//if the miner is not already at the gold mine, then he must be moved to the goldmine.
	if(miner->location() != goldmine)
	{
		cout << "\n" << getNameOfEntity(miner->ID()) << ":" << " Walkin' to the goldmine";

		miner->changeLocation(goldmine);
	}
}

void EnterMineAndDigForGold::exectue(Miner* miner)
{
	miner->addToGoldCarried(1);

	//Increase fatigue
	miner->increaseFatigue();

	std::cout << "\n" << getNameOfEntity(miner->ID()) << ":" << " Pickin' up a nugget";

	//if enough gold is gathered.
	if(miner->fullPocktes())
	{
		miner->changeState(VisitBankAndDepositGold::instance());
	}

	//If thirsty go for whiskey
	if(miner->thirsty())
	{
		miner->changeState(QuenchThirst::instance());
	}
}

void EnterMineAndDigForGold::exit(Miner* miner)
{
	cout << "\n" << getNameOfEntity(miner->ID()) << ": " << "I'm going home, so much goldz";
}