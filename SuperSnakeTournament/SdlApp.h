#pragma once

#include <SDL2/SDL.h>

struct Color;

struct SdlApp
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	float scale = 50;

	void drawRectangle(const Color& color, const SDL_Rect& rect);
};

