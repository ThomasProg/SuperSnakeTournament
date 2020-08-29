#include "SlowDownItem.h"

#include "Snake.h"
#include "Color.h"

void SlowDownItem::consume(Snake& snake) 
{
	snake.slowDown();
}

void SlowDownItem::draw(SdlApp& app)
{
	app.drawRectangle(Color::green(), SDL_Rect{ location.x,location.y,1,1 });
}