#pragma once

#include "Snake.h"
#include "Item.h"
#include "SdlApp.h"	   

#include <SDL2/SDL.h>

#include <memory>

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
	
	std::vector<std::unique_ptr<Item>> items;
	int nbCasesX = 0;
	int nbCasesY = 0;

public:
	Game();
	~Game();

	void run();

	void checkSnakeItemsCollision(Snake& snake);

	template<typename ITEM_TYPE>
	inline void addItem(const Vec2Int& location)
	{
		items[location.x + location.y * nbCasesX] = std::make_unique<ITEM_TYPE>(location);
	}
};

