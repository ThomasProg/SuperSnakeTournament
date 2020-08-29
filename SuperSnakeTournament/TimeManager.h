#pragma once

#include <SDL2/SDL.h>

struct TimeManager
{
	// in ms
	Uint32 time = 0;

	inline void update()
	{
		time = SDL_GetTicks();
	}
};

