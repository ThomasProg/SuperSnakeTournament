#pragma once

#include <SDL2/SDL.h>

#include "Snake.h"
#include "SdlApp.h"

class Game
{
private:
	int width = 800;
	int height = 600;

	SdlApp app;

	bool shouldClose = false;

	// in ms
	Uint32 time = 0;
	Uint32 lastUpdateTime = 0;
	Uint32 updateDelay = 100;

	Snake snake;

public:
	Game();
	~Game();

	void run();
};

