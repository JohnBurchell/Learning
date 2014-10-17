#ifndef DOT_H_
#define DOT_H_

#include <particle.h>

class Dot
{

	public:
		//Dimensions of the dot.
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//Maximum axis velocity of the dot.
		static const int DOT_VEL = 10;

		//Initialise variables and allocate particles
		Dot();

		//Deallocates partilcles
		~Dot();

		void handleEvent( SDL_Event& e);

		void move();

		void render();

	private:
		Partilce* particles[ 20 ];

		//Show the particles
		void renderParticles();

		//Position offsets of the particles
		int mPosx, mPosY;

		//Velocity of the partciles
		int mVelx, mVelY;
	
};

#endif //DOT_H_