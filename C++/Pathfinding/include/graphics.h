#ifndef GRAPHICS_H_
#define GRAPHICS_H_
#pragma once

#ifdef _WIN32
#include <SDL.h>
#endif

#ifdef __linux__
#include <SDL2/SDL.h>
#endif

#include <unordered_map>

class Graphics
{
	public:
		Graphics();
		~Graphics();


		SDL_Texture* loadImage(const std::string& file_name, bool black_transparency);

		void renderTexture(SDL_Texture* texture, const SDL_Rect destination, const SDL_Rect* clip = nullptr) const;
		void renderTexture(SDL_Texture* texture, const int x, const int y, const SDL_Rect* clip = nullptr) const;
		
		//REMOVE LATER - Debugging
		void render_rectanlge(const int pos_x, const int pos_y, const int colour, const int width = 32, const int height = 32);
		void renderLine(int origin_x, int origin_y, int target_x, int target_y);

		class Renderer_Error{};
		class Window_Error{};
		class Texture_Error{};
		class Surface_Error{};

		void flip();
		void clear();

	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;

		//Unordered map used as I don't care about order, but only want the associativity given by a map structure.
		std::unordered_map<std::string, SDL_Texture*> loaded_images;
};

#endif //GRAPHICS_H_
