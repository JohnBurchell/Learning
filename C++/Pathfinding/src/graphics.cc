#include "graphics.h"
#include <iostream>

Graphics::Graphics() :

	m_window{ SDL_CreateWindow("Pathfinder - Visualiser",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
							 640, 640, SDL_WINDOW_SHOWN) },
	m_renderer{ SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED) }

{
	if (m_window == NULL){
		std::cout << "Error creating window! " << SDL_GetError() << std::endl;
		throw Window_Error();
	}

	if (m_renderer == NULL){
		std::cout << "Error creating renderer! " << SDL_GetError() << std::endl;
		throw Renderer_Error();
	}

	//SDL_ShowCursor(SDL_DISABLE);
}

SDL_Texture* Graphics::loadImage(const std::string& fileName, bool black_is_transparent)
{
	if (loaded_images.count(fileName) == 0)	{
		SDL_Texture* texture;
		SDL_Surface* surface = SDL_LoadBMP(fileName.c_str());

		if (black_is_transparent) {
			//0 = black, this ignores black around the image
			SDL_SetColorKey(surface, SDL_TRUE, 0);
		}

		if (surface == nullptr) {
			auto error = "Error creating surface for " + fileName + "!" + SDL_GetError();
			throw Surface_Error();
		}
		texture = SDL_CreateTextureFromSurface(m_renderer, surface);

		if (texture == nullptr) {
			auto error = "Cannot load texture " + fileName + "!" + SDL_GetError();
			throw Texture_Error();
		}

		SDL_FreeSurface(surface);
		loaded_images[fileName] = texture;
	}

	return loaded_images[fileName];
}

void Graphics::renderTexture(SDL_Texture* texture, const int x, const int y, const SDL_Rect* clip) const
{
	SDL_Rect desitantion_rectangle;
	desitantion_rectangle.x = x;
	desitantion_rectangle.y = y;

	if (clip != nullptr) {
		desitantion_rectangle.w = clip->w;
		desitantion_rectangle.h = clip->h;
	}
	else {
		SDL_QueryTexture(texture, nullptr, nullptr, &desitantion_rectangle.w, &desitantion_rectangle.h);
	}

	renderTexture(texture, desitantion_rectangle, clip);
}

void Graphics::renderTexture(SDL_Texture* texture, const SDL_Rect destination, const SDL_Rect *clip) const
{
	SDL_RenderCopy(m_renderer, texture, clip, &destination);
}

void Graphics::flip()
{
	SDL_RenderPresent(m_renderer);
}

void Graphics::clear()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
}

Graphics::~Graphics()
{
	for(auto x : loaded_images)
	{
		SDL_DestroyTexture(x.second);
	}
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}


void Graphics::renderLine(int origin_x, int origin_y, int target_x, int target_y)
{
	SDL_SetRenderDrawColor(m_renderer, 200, 200, 110, 32);

	SDL_RenderDrawLine(m_renderer, origin_x + 16, origin_y + 16, target_x + 16, target_y + 16);
}
//Remove later
void Graphics::render_rectanlge(const int pos_x, const int pos_y, const int colour, const int width, const int height)
{
	SDL_Color col;
	switch (colour) {
	case 1:
		//Red
		col = { 255, 0, 0, 255 };
		break;
	case 2:
		//Yellow
		col = { 255, 255, 0, 255 };
		break;
	case 3:
		//Green
		col = { 0, 255, 0, 255 };
		break;
	case 4:
		//Blue
		col = { 20, 20, 220, 255 };
		break;
	case 5:
		//Teal
		col = { 51, 204, 255, 255 };
		break;
		//Orange
	case 6:
		col = { 204, 153, 0, 255 };
		break;
		//Purple
	case 7:
		col = { 255, 0, 255, 255 };
		break;
	case 8:
		col = { 255, 255, 255, 120 };
		break;
	default:
		col = { 255, 255, 255, 255 };
		break;
	}
	SDL_Rect rect = { pos_x, pos_y, width, height };
	SDL_SetRenderDrawColor(m_renderer, col.r, col.g, col.b, col.a);
	SDL_RenderFillRect(m_renderer, &rect);
}