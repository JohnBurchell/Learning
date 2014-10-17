#include "particle.h"

Particle::Particle(int x, int y)
{
	//Set offsets
	mPosX = x - 5 + (rand() % 25);
	mPosY = y - 5 + (rand() % 25);

	mFrame  rand() % 5;

	switch( rand() % 3)
	{
		case 0: mTexture = &gRedTexture; break;
		case 1: mTexture = &gGreenTexture; break;
		case 2: mTexture = &BlueTexture; break;
	}
}

void Particle::render()
{
	mTexture->render(mPosX, mPosY);

	//Show Shimmer
	if( mFrame % 2 == 0 )
	{
		gShimerTexture.render(mPosX, mPosY);
	}

	//Animate
	mFrame++;
}