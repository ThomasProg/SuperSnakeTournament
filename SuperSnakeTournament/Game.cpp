#include "Game.h"

#include <iostream>

Game::Game()
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		std::cout << "SDL error : " << SDL_GetError() << std::endl;
		return;
	}

	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &app.window, &app.renderer);
}	

Game::~Game()
{
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);

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

			snake.inputs(event);
		}

		snake.draw(app);

		time = SDL_GetTicks();

		if (time > updateDelay + lastUpdateTime)
		{
			lastUpdateTime = SDL_GetTicks();
			snake.update();
		}

		SDL_RenderPresent(app.renderer);
		SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
		SDL_RenderClear(app.renderer);
		SDL_Delay(1);
	}
}