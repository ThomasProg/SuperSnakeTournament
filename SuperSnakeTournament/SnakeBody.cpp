#include "SnakeBody.h"

#include "Color.h"

void SnakeBody::draw(SdlApp& app)
{
	SDL_Rect rect{ location.x, location.y, 1, 1 };
	app.drawRectangle(Color::green(), rect);
}