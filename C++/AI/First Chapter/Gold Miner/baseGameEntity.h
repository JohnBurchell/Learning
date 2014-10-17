#ifndef BASE_GAME_ENTITY_H_
#define BASE_GAME_ENTITY_H_

#include <memory>

class BaseGameEntity
{

	public:
		BaseGameEntity(int id)
		{
			setID(id);
		}

		virtual ~BaseGameEntity() {}

		virtual void update() = 0;

		inline int getID() const { return ID_; };
	
	private:

		//Unique ID for each entity.
		int ID_;

		//This holds the next created base entity and is update each time a new one is instantiated.
		static int nextValidId_;

		//Called within the constructor to ensure that the ID is correctly set.  
		void setID(int id);

};

#endif //BASE_GAME_ENTITY_H_