#ifndef PARTICLE_H_
#define PARTICLE_H_


class Particle
{
	public:
		Particle(int x, int y);

		void render();

		bool isdead();
	private:
		float mPosX mPosY;

		int mFrame;

		//Texture
		SDL_Texture* mTexture;
};

#endif //PARTICLE_H_