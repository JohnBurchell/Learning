#ifndef MINER_H_
#define MINER_H_

#include "baseGameEntity.h"
#include "stateMachine.h"

class Miner : public BaseGameEntity
{
	public:
		Miner(int ID);
		~Miner();

		void update() override;

		enum class LocationType
		{
			shack,
			home,
			goldmine,
			tavern
		};

		StateMachine<Miner>* GetFSM() const { return stateMachine; };

	private:

		StateMachine<Miner>* stateMachine;

		LocationType location_;

		int goldCarried_;

		int moneyInBank_;

		int thirst_;

		int fatigue_;

};

#endif //MINER_H_