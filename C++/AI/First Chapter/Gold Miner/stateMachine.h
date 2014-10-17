#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include "state.h"

template<class entity_type>
class StateMachine
{
	private:
		//Pointer to the agent which owns this instance
		entity_type* owner;

		State<entity_type>* currentState;

		//Records the previous state
		State<entity_type>* previousState;

		//state logic called everytime the FSM is updated.
		State<entity_type>* globalState;

	public:

		StateMachine(entity_type* owner) :
			owner{owner},
			currentState{nullptr},
			previousState{nullptr},
			globalState{nullptr}
			{}

		void setCurrentState(State<entity_type>* state) { currentState = state; };
		void setGlobalState(State<entity_type>* state) { globalState = state; };
		void setPreviousState(State<entity_type>* state) { previousState = state; };

		void update() const
		{
			//if a global state exists, call and exectue this method.
			if(globalState) globalState->execute(owner);

			//same for current state
			if(currentState) currentState->execute(owner);
		}

		//changet to a new state
		void changeState(State<entity_type>* newState)
		{
			assert(newState && "<StateMachine::ChangeState>: trying to change to a null state");

			//keep a record of the previous state
			previousState = currentState;

			//call exit of existing state;
			currentState->exit(owner);

			//change state to the new state
			currentState = newState;

			//call entry method for new state
			newState->enter(owner);
		}

		//Change state back to previous state
		void revertToPreviousState()
		{
			changeState(previousState);
		}

		//Accessors
		State<entity_type*> getCurrnetState() const { return currentState; };
		State<entity_type*> getPreviousState() const { return previousState; };
		State<entity_type*> getGlobalState() const { return globalState; };
};

#endif //STATE_MAHCINE_H_