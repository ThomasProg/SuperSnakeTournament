#include "Game.h"
#include "Apple.h"
#include "ItemReduceLife.h"

#include <iostream>

Game::Game()
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		std::cout << "SDL error : " << SDL_GetError() << std::endl;
		shouldClose = true;
		return;
	}

	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &app.window, &app.renderer);

	nbCasesX = static_cast<int> (width / app.scale);
	nbCasesY = static_cast<int> (height / app.scale);
	items.resize(nbCasesX * nbCasesY);

	addItem<Apple>({3,2});
	addItem<ItemReduceLife>({ 9,5 });
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

		time = SDL_GetTicks();

		if (time > updateDelay + lastUpdateTime)
		{
			lastUpdateTime = SDL_GetTicks();
			if (snake)
			{
				snake->update();
				checkSnakeItemsCollision(*snake);
				if (isSnakeInWall(*snake) || isSnakeHeadInSnake(*snake))
				{
					snake.release();
				}
			}
		}

		SDL_RenderPresent(app.renderer);
		SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
		SDL_RenderClear(app.renderer);
		SDL_Delay(1);
	}
}

void Game::checkSnakeItemsCollision(Snake& snake)
{
	Vec2Int headLoc = snake.getHeadLocation();
	int index = headLoc.x + headLoc.y * nbCasesX;
	if (index < 0 || index > (nbCasesX - 1) * (nbCasesY - 1))
	{
		return;
	}

	std::unique_ptr<Item>& apple = items[headLoc.x + headLoc.y * nbCasesX];
	if (apple)
	{
		apple->consume(snake);
		apple.release();
	}
}

bool Game::isSnakeInWall(const Snake& snake)
{
	const Vec2Int headLoc = snake.getHeadLocation();
	return headLoc.x < 0 || headLoc.y < 0
		|| headLoc.x * app.scale > width
		|| headLoc.y * app.scale > height;
}

bool Game::isSnakeHeadInSnake(const Snake& snake)
{
	return snake.isHeadInsideAnotherSnake(snake);
}