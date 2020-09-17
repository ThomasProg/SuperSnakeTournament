#pragma once

#include "Snake.h"
#include "Item.h"
#include "SdlApp.h"	   
#include "TimeManager.h"

#include <SDL2/SDL.h>

#include <memory>

class Game
{
private:
	int width = 800;
	int height = 600;

	SdlApp app;

	bool shouldClose = false;

	TimeManager timeManager;

	std::unique_ptr<Snake> snake = std::make_unique<Snake>();
	
	std::vector<std::unique_ptr<Item>> items;
	int nbCasesX = 0;
	int nbCasesY = 0;

public:
	Game();
	~Game();

	void loadTextures();

	void run();

	void inputs(const SDL_Event& event);
	void update();
	void draw();

	void checkSnakeItemsCollision(Snake& snake);
	bool isSnakeInWall(const Snake& snake);
	bool isSnakeHeadInSnake(const Snake& snake);

	template<typename ITEM_TYPE>
	inline void addItem(const Vec2Int& location)
	{
		items[location.x + location.y * nbCasesX] = std::make_unique<ITEM_TYPE>(location);
	}

	template<typename ITEM_TYPE>
	inline void addItemAtRandomLocation()
	{
		assert(nbCasesX > 0 && nbCasesY > 0);
		Vec2Int randomLocation = {std::rand() % nbCasesX, std::rand() % nbCasesY};
		addItem<ITEM_TYPE>(randomLocation);
	}

	void addRandomItemAtRandomLocation();
};

