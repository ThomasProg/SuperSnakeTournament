#pragma once

#include "Vec2Int.h"

#include <SDL2/SDL.h>

struct SdlApp;

class Snake
{
private:
	Vec2Int headLocation = {0, 0};
	Vec2Int direction = {1, 0};

public:

	void update();
	void draw(SdlApp& app);
	void inputs(const SDL_Event& event);
};

