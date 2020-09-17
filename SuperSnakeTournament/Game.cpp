#include "Game.h"
#include "Apple.h"
#include "ItemReduceLife.h"
#include "SlowDownItem.h"
#include "SpeedUpItem.h"
#include "ItemType.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game()
{
	// Init SDL2
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		std::cout << "SDL error : " << SDL_GetError() << std::endl;
		shouldClose = true;
		return;
	}

	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &app.window, &app.renderer);

	// Init srand
	std::srand(std::time(0));

	loadTextures();

	// Init Snake Game
	nbCasesX = static_cast<int> (width / app.scale);
	nbCasesY = static_cast<int> (height / app.scale);
	items.resize(nbCasesX * nbCasesY);

	addItem<Apple>({3,2});
	addItem<ItemReduceLife>({ 9,5 });
	addItemAtRandomLocation<SlowDownItem>();
	addItemAtRandomLocation<SpeedUpItem>();
}	

Game::~Game()
{
	if (app.renderer != nullptr)
	{
		SDL_DestroyRenderer(app.renderer);
	}
	if (app.window != nullptr)
	{
		SDL_DestroyWindow(app.window);
	}

	SDL_Quit();
}

void Game::loadTextures()
{
	app.textureManager->addTexture("../ressources/Apple.png", ItemType::Apple);
	app.textureManager->addTexture("../ressources/ReduceLife.png", ItemType::ItemReduceLife);
	app.textureManager->addTexture("../ressources/SlowDown.png", ItemType::SlowDownItem);
	app.textureManager->addTexture("../ressources/SpeedUp.png", ItemType::SpeedUpItem);
}

void Game::run()
{
	while (!shouldClose)
	{								 
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				shouldClose = true;
			}
			
			inputs(event);
		}

		draw();
		update();

		SDL_RenderPresent(app.renderer);
		SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
		SDL_RenderClear(app.renderer);
		SDL_Delay(1);
	}
}

void Game::inputs(const SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.scancode == SDL_SCANCODE_R)
		{
			if (snake == nullptr)
			{
				snake = std::make_unique<Snake>();
			}
		}
	}

	if (snake)
	{
		snake->inputs(event);
	}
}

void Game::update()
{
	timeManager.update();

	if (snake)
	{
		if (snake->update(timeManager))
		{
			checkSnakeItemsCollision(*snake);
			if (isSnakeInWall(*snake) || isSnakeHeadInSnake(*snake))
			{
				snake.release();
			}
		}
	}
}

void Game::draw()
{
	if (snake)
	{
		snake->draw(app);
	}
	for (std::unique_ptr<Item>& item : items)
	{
		if (item)
		{
			item->draw(app);
		}
	}
}

void Game::checkSnakeItemsCollision(Snake& snake)
{
	Vec2Int headLoc = snake.getHeadLocation();
	int index = headLoc.x + headLoc.y * nbCasesX;
	if (index < 0 || index > nbCasesX * nbCasesY - 1)
	{
		return;
	}

	std::unique_ptr<Item>& item = items[headLoc.x + headLoc.y * nbCasesX];
	if (item)
	{
		item->consume(snake);
		bool wasApple = typeid(*item) == typeid(Apple);
		item.release();
		if (wasApple)
		{
			addRandomItemAtRandomLocation();
			addItemAtRandomLocation<Apple>();
		}
	}
}

bool Game::isSnakeInWall(const Snake& snake)
{
	const Vec2Int headLoc = snake.getHeadLocation();
	return headLoc.x < 0 || headLoc.y < 0
		|| headLoc.x > nbCasesX - 1
		|| headLoc.y > nbCasesY - 1;
}

bool Game::isSnakeHeadInSnake(const Snake& snake)
{
	return snake.isHeadInsideAnotherSnake(snake);
}

void Game::addRandomItemAtRandomLocation()
{
	constexpr int nbItemType = 4;
	ItemType randType = static_cast<ItemType> (std::rand() % (nbItemType - 2) + 1);
	switch (randType)
	{
	case ItemType::ItemReduceLife:
		addItemAtRandomLocation<ItemReduceLife>();
		break;
	case ItemType::SpeedUpItem:
		addItemAtRandomLocation<SpeedUpItem>();
		break;
	case ItemType::SlowDownItem:
		addItemAtRandomLocation<SlowDownItem>();
		break;
	}
}