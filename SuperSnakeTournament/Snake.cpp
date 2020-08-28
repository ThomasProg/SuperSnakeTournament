#include "Snake.h"
#include "SdlApp.h"
#include "Color.h"

void Snake::draw(SdlApp& app)
{
	SDL_Rect rect{ headLocation.x, headLocation.y, 1, 1 };
	app.drawRectangle(Color::green(), rect);
}

void Snake::update()
{
	headLocation += direction;
}

void Snake::inputs(const SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.scancode)
		{
		case SDL_SCANCODE_W:
			direction = {0, -1};
			break;
		case SDL_SCANCODE_S:
			direction = { 0, 1 };
			break;
		case SDL_SCANCODE_A:
			direction = { -1, 0 };
			break;
		case SDL_SCANCODE_D:
			direction = { 1, 0 };
			break;

		default:
			break;
		}
	}
}